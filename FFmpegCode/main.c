#include <stdio.h>
#include <string.h>
#include <libavutil/avutil.h>
#include <libavdevice/avdevice.h>
#include <libavformat/avformat.h>
#include <libavcodec/avcodec.h>
#include <libswresample/swresample.h>

/**
 * 音频编码器编码音频数据
 * @param codec_context
 * @param frame
 * @param newpkt
 * @param outfile
 */
void encode(AVCodecContext *codec_context, AVFrame* frame, AVPacket *newpkt, FILE *outfile) {
  int ret = 0;
  // 将数据送入编码器
  ret = avcodec_send_frame(codec_context, frame);
  while(ret >= 0) {
    // 获取编码后的音频数据
    ret = avcodec_receive_packet(codec_context, newpkt);
    if (ret == AVERROR(EAGAIN) || ret == AVERROR_EOF) {
      return;
    } else if(ret < 0){
      av_log(NULL, AV_LOG_ERROR,
             "encoding audio packet error!");
      exit(-1);
    }
    // 将音频数据写入到文件中
    fwrite(newpkt->data, 1, newpkt->size, outfile);
    fflush(outfile);
  }
}

/**
 * 音频编码器打开
 * @return
 */
AVCodecContext* open_coder(){
  AVCodec *codec = avcodec_find_encoder_by_name("libopus");//  avcodec_find_encoder(AV_CODEC_ID_AAC)
  AVCodecContext *codec_context = avcodec_alloc_context3(codec);
  codec_context->sample_fmt = AV_SAMPLE_FMT_S16; // 采样大小
  codec_context->channel_layout = AV_CH_LAYOUT_STEREO;// 采样布局
  codec_context->channels = 2;
  codec_context->sample_rate = 48000; // 采样率
  codec_context->bit_rate = 0;// AAC_LC 128K AAC HE 64K AAC HE V2 32K
  codec_context->profile = FF_PROFILE_AAC_HE_V2;
  if (avcodec_open2(codec_context, codec, NULL) < 0) {
    av_log(NULL, AV_LOG_ERROR,
           "open audio codec error!");
    return NULL;
  }
  return codec_context;
}

/**
 * 音频重采样context初始化
 * @return SwrContext*
 */
SwrContext* init_swr() {
  SwrContext *swr_context = NULL;
  swr_context = swr_alloc_set_opts(NULL,
                                   AV_CH_LAYOUT_STEREO,
                                   AV_SAMPLE_FMT_S16,
                                   44100,
                                   AV_CH_LAYOUT_STEREO,
                                   AV_SAMPLE_FMT_S16,
                                   48000,
                                   0,
                                   NULL);
  if(!swr_context){
    printf(stderr, "swr_alloc_set_opts error");
  }
  if(swr_init(swr_context)<0){
    printf(stderr, "swr_init error");
  }
  return swr_context;
}

/**
 * FFmpeg采集音频
 * 打开输入设备->数据包->重采样->输出文件
 *
 * FFmpeg音频AAC编码
 *  创建编码器 avcodec_find_encoder
 *  创建上下文 avcodec_alloc_context3
 *  打开编码器 avcodec_open2
 *  送数据给编码器
 *  编码
 *  释放资源
 */
void rec_audio(){
  av_log_set_level(AV_LOG_DEBUG);

  AVFormatContext *fmt_ctx = NULL;
  AVDictionary *options = NULL;
  int ret = 0;
  char errors[1024] = {0,};
  char *devicename = "audio=麦克风 (Realtek(R) Audio)";

  // 注册设备
  avdevice_register_all();

  // 设置采集方式avfoundation dshow alsa
  AVInputFormat *iformat = av_find_input_format("dshow");

  // 打开音频设备
  if((ret = avformat_open_input(&fmt_ctx, devicename, iformat, &options)) < 0){
    av_strerror(ret, errors, 1024);
    printf(stderr, "Failed to open audio device, [%d]%s\n", ret, errors);
    return;
  }

  // 录制音频：创建文件
//  char *out = "./auido.pcm";
  char *out = "./auido.aac";
  FILE *outfile = fopen(out, "wb+");

  // 音频编码器
  AVCodecContext *codec_context = open_coder();
  AVFrame *frame = av_frame_alloc(); // 音频输入数据
  if(!frame){
    av_log(NULL, AV_LOG_ERROR,
           "alloc AVFrame error! ");
  }
  frame->nb_samples = 22050;// 单通道一个音频帧的采样数
  frame->format = AV_SAMPLE_FMT_S16;
  frame->channel_layout = AV_CH_LAYOUT_STEREO;
  av_frame_get_buffer(frame, 0);
  if(!frame->buf[0]){
    av_log(NULL, AV_LOG_ERROR,
           "av_frame_get_buffer error!");
  }
  AVPacket *newpkt = av_packet_alloc(); // 分配编码后的数据空间
  if(!newpkt){
    av_log(NULL, AV_LOG_ERROR,
           "alloc AVPacket error! ");
  }

  // 音频重采样(采样率、采样大小、通道数)
  SwrContext *swr_context = init_swr();
  uint8_t  **src_data = NULL;
  int src_linesize = 0;
  uint8_t  **dst_data = NULL;
  int dst_linesize = 0;
  // 创建输入缓冲区88200/4/2=11025 88200/2/2=22050
  av_samples_alloc_array_and_samples(&src_data, // 输入缓冲区地址
                                     &src_linesize, // 缓冲区大小
                                     2, // 通道个数
                                     22050, // 单通道采样个数
                                     AV_SAMPLE_FMT_S16, // 采样格式
                                     0);
  // 创建输出缓冲区88200/4/2=11025
  av_samples_alloc_array_and_samples(&dst_data, // 输出缓冲区地址
                                     &dst_linesize, // 缓冲区大小
                                     2, // 通道个数
                                     22050, // 单通道采样个数
                                     AV_SAMPLE_FMT_S16, // 采样格式
                                     0);

  // 读取音频数据包
  int count = 0;
  AVPacket pkt;
//  av_init_packet(&pkt);
  while((ret = av_read_frame(fmt_ctx, &pkt)) == 0 && count++ < 200) {
    av_log(NULL, AV_LOG_INFO,
           "pkt size is %d(%p), count=%d\n",
           pkt.size,
           pkt.data,
           count);
    memcpy((void *)src_data[0], (void *)pkt.data, pkt.size);
    // 重采样音频
    swr_convert(swr_context, dst_data, 22050, (const uint8_t **)src_data, 22050);
    // 将重采样后的数据copy到音频编码器的输入数据并编码音频数据
    memcpy((void *)frame->data[0], dst_data[0], dst_linesize);
    encode(codec_context, frame, newpkt, outfile);
    av_packet_unref(&pkt);
  }
  // 强制将编码器缓冲区的音频进行编码输出
  encode(codec_context, NULL, newpkt, outfile);

  fclose(outfile);
  if (src_data) {
    av_freep(&src_data[0]);
  }
  av_freep(&src_data);
  if (dst_data) {
    av_freep(&dst_data[0]);
  }
  av_freep(&dst_data);
  swr_free(&swr_context);
  av_frame_free(&frame);
  av_packet_free(&newpkt);
  avformat_close_input(&fmt_ctx);
  av_log(NULL, AV_LOG_DEBUG, "Finish!\n");
}

/**
 * FFmpeg API Index: https://ffmpeg.org/doxygen/trunk/index.html
 * FFmpeg Docs: http://ffmpeg.org/ffmpeg-devices.html#avfoundation
 * ffplay -ar 44100 -ac 2 -f s16le auido.pcm
 * @return
 */
int main() {
  rec_audio();
  return 0;
}
