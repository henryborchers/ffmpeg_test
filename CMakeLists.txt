cmake_minimum_required(VERSION 2.8.4)
project(ffmpeg_test)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D__STDC_CONSTANT_MACROS -std=c++11")
set(SOURCE_FILES main.cpp)
if( NOT CMAKE_MODULE_PATH )
    set(CMAKE_MODULE_PATH D:/modules)
    message( STATUS "CMAKE_MODULE_PATH=${CMAKE_MODULE_PATH}" )
endif()
add_executable(ffmpeg_test ${SOURCE_FILES})

INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/include
                    ${PROJECT_SOURCE_DIR}/lib
                    )

if(${WIN32})
    list( APPEND ExternalSharedLibraries "d:/modules/ffmpeg/bin/")


    # Where will the executables be located?
    if( DEFINED EXE_DIR )
        set( exeDir "${EXE_DIR}" )
    else()
        set( exeDir "${CMAKE_CURRENT_BINARY_DIR}" )
    endif()
    message( INFO "\tCopying ffmpeg shared libraries." )
    file( COPY ${ExternalSharedLibraries} DESTINATION "${exeDir}" NO_SOURCE_PERMISSIONS )
endif()

find_package(FFMPEG REQUIRED)
include_directories(${FFMPEG_INCLUDE_DIRS})
set(LIBS ${LIBS} ${FFMPEG_LIBRARIES})
target_link_libraries(ffmpeg_test ${LIBS})
