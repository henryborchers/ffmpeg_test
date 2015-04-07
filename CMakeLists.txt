cmake_minimum_required(VERSION 2.8.4)
project(testa)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D__STDC_CONSTANT_MACROS -std=c++11")
set(SOURCE_FILES main.cpp)
set(FFMPEG_LIB libavcodec.a
               libavdevice.a
               libavfilter.a
               libavformat.a
               libavutil.a
               libpostproc.a
               libswresample.a
               libswscale.a)

INCLUDE_DIRECTORIES(include)
add_subdirectory(lib)
add_subdirectory(include)
LINK_DIRECTORIES(lib)
add_executable(testa ${SOURCE_FILES})
target_link_libraries(testa ${FFMPEG_LIB})
message(STATUS "The ffmpeg libraries are: " ${FFMPEG_LIB})