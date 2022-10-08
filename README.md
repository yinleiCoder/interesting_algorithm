# 四川师范大学 软件工程 考研 C语言程序设计与数据结构（2023）
`有趣的算法...(C/C++)`

## 2023年硕士研究生招考专业目录
招生章程： [四川师范大学招生章程公告](http://yjsc.sicnu.edu.cn/p/23/)

网上报名公告： [四川师范大学2022年研究生报名公告](http://yjsc.sicnu.edu.cn/p/0/?StId=st_app_news_i_x637680128025834659)


|序号|学院及代码|专业及代码|类型|学制(年)|学费(元)|推免生|招生计划|考试科目|业务科1参考书目|业务科2参考书目|复试科目名称及参考书目|同等学力加试科目名称及参考书目|跨专业加试科目名称及参考书目|本专业特殊要求|联系方式|校区|备注|
|:----:|:----:|:----:|:----:|:----:|:----:|:----:|:----:|:----:|:----:|:----:|:----:|:----:|:----:|:----:|:----:|:----:|:----: |
|44|013计算机科学学院|083500软件工程<br>01教育软件工程<br>02企业信息化工程<br>03智能计算技术<br>04可信计算与系统安全<br>05移动计算与嵌入式软件<br>06大数据技术与应用|学术型|3|8000（生/年）|3|10(非推免)|①101思想政治理论<br>②201英语(一)<br>③302数学(二)<br>④831C语言程序设计与数据结构|教育部指定大纲|①《C语言程序设计》第5版，谭浩强著，清华大学出版社。<br>②《数据结构（C语言版）》严蔚敏、吴伟民编著，清华大学出版社。|计算机专业基础综合参考书目：<br>①《计算机网络》第8版，谢希人著，电子工业出版社。<br>②《数据库系统概论》第5版，王珊、萨师煊著，高等教育出版社。|① 操作系统参考书目：《计算机操作系统（慕课版）》汤小丹，人民邮电出版社。<br>② 软件工程 参考书目：《软件工程导论》第6版，张海藩，清华大学出版社。|无|无|电话：（028）-84483992<br>（028)-84480016<br><br>Email:86057765@qq.com|成龙| | 

## 开发环境
`注：本项目是CMake工程 + 子工程，Run具体的工程前，需要Load CMake Project，然后再Reload CMake Project。`
- Visual Studio 2022
- Clion
- MinGW、MSVC
- WSL(可选)
- VMware、VirtualBox
- [Windows操作系统(Win11)](https://mp.weixin.qq.com/s?__biz=MzU2NzkxMzg2NQ==&mid=2247484028&idx=1&sn=0c80023581971ed1c9efdda438547025&chksm=fc94be9acbe3378cf2da2e4c6d5fd1c8c3a2459d745309ef9876292fae62a67b1761e30abfe5&token=1365422365&lang=zh_CN#rd)
- [Linux操作系统(Ubuntu 22)](https://www.bilibili.com/video/BV1EE411y7CD?spm_id_from=333.999.0.0)

## C语言的根基
```js
相信程序员是C语言设计的哲学！
```
- 类型系统
- 数组
- 预处理
- 函数
- 指针
- 聚合类型
- C标准库
- POSIX扩展
- 系统底层接口
- 宏展开
- 汇编
- 链接
- 库的引入
- 依赖管理
- GUI编程

## 仓库文件夹及文件说明
`C的编码、代码随想录算法、FFmpeg的C API、川师真题及其解答等`
- **HelloWorldC：C11新标准学习C语言**
  - 01.data_types.c: 数据类型
  - 02.variable.c：变量
  - 03.constant.c：常量
  - 04.operators.c：运算符
  - 05.condition.c： 条件分支语句
  - 06.loop.c：循环语句
  - 07.guess_number.c：猜数字游戏
  - 08.function_basics.c：函数基础
  - 09.function_proto_type.c：函数的原型
  - 10.variable_types_and_scope.c：变量类型和作用域
  - 11.function_varargs.c：函数的变长参数
  - 12.function_recursion.c：函数的递归
  - 13.hanoi.c：汉诺塔游戏
  - 14.custom_include_file.c：自定义头文件
  - 15.macro_function.c：宏函数
  - 16.conditional_macro.c：条件编译
  - 17.printlnf.c：宏函数实现printlnf函数
  - 18.array_basics.c：数组基础
  - 19.array_limits.c：数组的边界
  - 20.string_basics.c：字符串
  - 21.array_parameter.c：函数的数组类型的参数
  - 22.2d_array.c：二维数组
  - 23.shuffle_array.c：打乱数组的顺序
  - 24.array_quick_sort.c：数组元素的排序——快排Lomuto partition scheme
  - 25.pointer_basics.c：指针的基础
  - 26.readonly_pointer.c：只读指针变量与只读变量指针
  - 27.pointer_values.c：特殊的指针
  - 28.pointer_operations.c：指针的运算
  - 29.lvalue_rvalue.c：左值和右值
  - 30.pointer_parameter_as_return_value.c：指针的参数作为返回值
  - 31.dynamic_memory.c：动态内存分配
  - 32.function_pointer.c：函数指针与typedef
  - 33.swap_values.c：交换2个变量的值
  - 34.quick_sort.c：指针版本的快排——Hoare partition Scheme
  - 35.struct.c：结构体
  - 36.memory_align.c：结构体的内存对齐
  - 37.union.c：联合体
  - 38.enum.c：枚举
  - 39.byte_order.c: 判断字节序
  - 40.linked_list.c: 单链表的基本实现
  - 41.character_type.c：判断字符的类型
  - 42.conversion_str.c：字符串与其他数值类型的转换
  - 43.string_length_compare.c：字符串的长度与比较
  - 44.find_char_and_substring.c：查找字符与子串
  - 45.string_tokenize.c：字符串的拆分
  - 46.string_concat_copy.c：字符串的连接和复制
  - 47.mem_op.c：内存操作函数
  - 48.safe_version.c：C11的安全版本的函数
  - 49.mbs_wcs.c：宽字符串与窄字符串的转换
  - 50.time_basic.c：时间的基本概念
  - 51.get_sys_time.c：获取系统时间
  - 52.calendar.c：获取日历时间
  - 53.format_time.c 格式化时间
  - 54.parse_time.c 解析时间
  - 55.time_diff.c 计算时间差
  - 56.io_basic.c 输入输出流
  - 57.io_setbuf.c 文件流的缓冲
  - 58.read_write_a_character.c 读写一个字符
  - 59.copy_file.c 3个版本的复制文件
  - 60.read_write_a_line：读写一行字符
  - 61.read_write_certain_bytes.c: 读写指定大小的字节
  - 62.serialization.c: 序列化和反序列化的基本实现
  - 63.redirect_stdout.c: 重定向标准输入输出流
  - 64.count_character.c: 统计文件字符个数
  - 65.file_position.c: 输入输出流的位置
  - 66.file_other_operation.c: 其他的文件操作
  - 67.thread_basic.c: 线程的基础概念
  - 68.thread_safe_atomic.c: 资源的线程安全问题
  - 69.thread_safe_visiblity.c: 资源的线程安全问题
  - 70.thread_safe_visiblity.c: 资源的线程安全问题
  - 71.thread_safe_lock.c: 资源的线程安全问题
  - 72.thread_safe_local.c: 资源的线程安全问题
  - 73.thread_safe_local2.c: 资源的线程安全问题
  - 74.pure_function.c: 副作用与纯函数
  - 75.complex_thread_result.c: 处理复杂的线程返回结果
  - 76.callback.c: 函数回调
  - 77.gtk_learn.c: GTK3 GUI编程
- **FFmpegCode: FFmpeg的API使用(FFmpeg v5.1)**
  - bin、includes、lib：Ffmpeg的动态链接库
- **代码随想录(C++)算法和数据结构Leetcode**
  - 排序
  - 二分搜索树
  - 并查集
  - 图
  - 最小生成树
  - 最短路径
  - 数组
  - 链表
  - 哈希表
  - 字符串
  - 栈与队列
  - 二叉树
  - 回溯算法
  - 贪心算法
  - 动态规划
- **考研计算机真题资料**：
    - 川师考研历年真题计算机

## 算法工具
`数据结构和算法的动态可视化、算法刷题等`
- [VisuALGo](https://visualgo.net/zh)
- [LeetCode](https://leetcode-cn.com/)

## 推荐书籍
`我读过的C/C++编程经典书籍，持续更新中...`
- [C语言程序设计 现代方法 第2版 修订版](https://item.jd.com/13336014.html)
- [C++ Primer 第5版]()
- [代码随想录]()
- [UNIX编程艺术]()
- [UNIX环境高级编程]()
- [程序员的自我修养]()
- C++`随着c++11标准的流行，每一个具体的技术领域，只需要读四五本书就够了。以前的C++是个例外，因为语言设计有缺陷，所以要读很多书才知道如何绕过缺陷。现在C++11以以后的标准完全就可以了，大家读四五本书就可以达到合格的水平，这恰恰是语言进步的体现：从主要关注机器效率转变为更多地关注编程效率！`
  C++包括C语言基础、object-oriented c++、Template c++、STL
  - (入门)
    - C++ Primer
  - (掌握)`侯捷先生译`
    - Effective C++
    - Effective STL
  - (熟悉)`侯捷先生译`
    - STL源码剖析
    - 深度探索C++对象模型

## 我录制的相关视频教程(Bilibili)
- [msys2搭建C语言环境、FFmpeg安装与Clion配置](https://www.bilibili.com/video/BV1NG411g783/?spm_id_from=333.999.0.0&vd_source=4f1390e05f2090819d9207c0805bd038)
- [Python环境搭建](https://www.bilibili.com/video/BV1JW4y1v7z6/?spm_id_from=333.999.0.0&vd_source=4f1390e05f2090819d9207c0805bd038)

## 后续学习方向建议
`研究生及以后职业规划的学习方向，仅供参考`
- 夯实数据结构、算法基础
- 深入学习Unix/Linux系统编程
- 研发开发框架源码，如Mysql
- 学习C++、Go等更适合业务开发的语言