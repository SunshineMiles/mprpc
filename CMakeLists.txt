
cmake_minimum_required(VERSION  3.25.2)
project(mprpc)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE "Debug")

#add_executable(main test/protobuf/main.cc test/protobuf/test.pb.cc)
#
##target_link_libraries(main lprotobuf)
#
#find_package(Protobuf REQUIRED)
#
## /usr/local/lib/libprotobuf.so
#if(Protobuf_FOUND)
#    message(STATUS "Protobuf libraries found: ${Protobuf_LIBRARIES}")
#    target_link_libraries(main ${Protobuf_LIBRARIES})
#endif()


# 设置项目可执行文件输出的路径  EXECUTABLE_OUTPUT_PATH是一个变量，用于指定生成的可执行文件的输出路径。${PROJECT_SOURCE_DIR}表示项目的根目录
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

# 设置项目库文件输出的路径
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

# 设置项目编译头文件搜索路径 -I
include_directories(${PROJECT_SOURCE_DIR}/src/include)
include_directories(${PROJECT_SOURCE_DIR}/example)


#设置项目库文件搜索路径
link_directories(${PROJECT_SOURCE_DIR}/lib)

#add_subdirectory(src)表示告诉CMake去处理src目录下的CMakeLists.txt文件
add_subdirectory(src)
add_subdirectory(example)

