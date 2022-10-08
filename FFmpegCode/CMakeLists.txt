cmake_minimum_required(VERSION 3.20)

get_filename_component(ProjectId ${CMAKE_CURRENT_SOURCE_DIR} NAME)
string(REPLACE " " "_" ProjectId ${ProjectId})
project(${ProjectId} C)

set(CMAKE_C_STANDARD 11)

set(FFMPEG_LIBS_DIR ${CMAKE_SOURCE_DIR}/FFmpegAPI)

add_library(avutil
            SHARED
            IMPORTED
            GLOBAL)
set_target_properties(avutil  PROPERTIES
        IMPORTED_LOCATION "${FFMPEG_LIBS_DIR}/lib/avutil-57.dll"
        IMPORTED_IMPLIB "${FFMPEG_LIBS_DIR}/lib/avutil.lib"
)

add_library(swresample
        SHARED
        IMPORTED
        GLOBAL)
set_target_properties(swresample  PROPERTIES
        IMPORTED_LOCATION "${FFMPEG_LIBS_DIR}/lib/swresample-4.dll"
        IMPORTED_IMPLIB "${FFMPEG_LIBS_DIR}/lib/swresample.lib"
        )

add_library(swscale
        SHARED
        IMPORTED
        GLOBAL)
set_target_properties(swscale  PROPERTIES
        IMPORTED_LOCATION "${FFMPEG_LIBS_DIR}/lib/swscale-6.dll"
        IMPORTED_IMPLIB "${FFMPEG_LIBS_DIR}/lib/swscale.lib"
        )

add_library(avcodec
        SHARED
        IMPORTED
        GLOBAL)
set_target_properties(avcodec  PROPERTIES
        IMPORTED_LOCATION "${FFMPEG_LIBS_DIR}/lib/avcodec-59.dll"
        IMPORTED_IMPLIB "${FFMPEG_LIBS_DIR}/lib/avcodec.lib"
        )

add_library(avformat
        SHARED
        IMPORTED
        GLOBAL)
set_target_properties(avformat  PROPERTIES
        IMPORTED_LOCATION "${FFMPEG_LIBS_DIR}/lib/avformat-59.dll"
        IMPORTED_IMPLIB "${FFMPEG_LIBS_DIR}/lib/avformat.lib"
        )

add_library(avfilter
        SHARED
        IMPORTED
        GLOBAL)
set_target_properties(avfilter  PROPERTIES
        IMPORTED_LOCATION "${FFMPEG_LIBS_DIR}/lib/avfilter-8.dll"
        IMPORTED_IMPLIB "${FFMPEG_LIBS_DIR}/lib/avfilter.lib"
        )

add_library(avdevice
        SHARED
        IMPORTED
        GLOBAL)
set_target_properties(avdevice  PROPERTIES
        IMPORTED_LOCATION "${FFMPEG_LIBS_DIR}/lib/avdevice-59.dll"
        IMPORTED_IMPLIB "${FFMPEG_LIBS_DIR}/lib/avdevice.lib"
        )

include_directories(${FFMPEG_LIBS_DIR}/includes)
#link_directories(${FFMPEG_LIBS_DIR}/lib) # 也可以用这条指令进行Link

file(GLOB files "${FFMPEG_LIBS_DIR}/lib/*.dll")
foreach(file ${files})
    configure_file(
            ${file}
            ${CMAKE_CURRENT_BINARY_DIR}
            COPYONLY
    )
endforeach()

if(MSVC)
    set(CMAKE_C_FLAGS "/utf8")
endif()

file(GLOB files "${CMAKE_CURRENT_SOURCE_DIR}/*.c")
foreach(file ${files})
    get_filename_component(name ${file} NAME)
    add_executable(${name} ${file})
    target_link_libraries(${name}
            avutil
            swresample
            swscale
            avcodec
            avformat
            avfilter
            avdevice)
endforeach()


#install(TARGETS MathFunctions DESTINATION lib)
#install(FILES MathFunctions.h DESTINATION include)

#install(TARGETS Tutorial DESTINATION bin)
#install(FILES "${PROJECT_BINARY_DIR}/TutorialConfig.h"
#        DESTINATION include
#        )


# from the binary directory run : cpack  或 cpack -G ZIP -C Debug 或 cpack --config CPackSourceConfig.cmake
include(InstallRequiredSystemLibraries)
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/License.txt")
#set(CPACK_PACKAGE_VERSION_MAJOR "${Tutorial_VERSION_MAJOR}")
#set(CPACK_PACKAGE_VERSION_MINOR "${Tutorial_VERSION_MINOR}")
set(CPACK_SOURCE_GENERATOR "TGZ")
include(CPack)