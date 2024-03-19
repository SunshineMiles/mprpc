#set(SRC_LIST calluserservice.cc ../user.pb.cc)
set(SRC_LIST callfriendservice.cc ../friend.pb.cc)
add_executable(consumer ${SRC_LIST})

# 使用动态链接库
target_link_libraries(consumer mprpc)

find_package(Protobuf REQUIRED)
if(Protobuf_FOUND)
    message(STATUS "Protobuf libraries found: ${Protobuf_LIBRARIES}")
    target_link_libraries(consumer ${Protobuf_LIBRARIES})
endif()














