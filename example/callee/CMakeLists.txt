#set(SRC_LIST userservice.cc ../user.pb.cc)
set(SRC_LIST friendservice.cc ../friend.pb.cc)

add_executable(provider ${SRC_LIST})
target_link_libraries(provider mprpc )

find_package(Protobuf REQUIRED)
if(Protobuf_FOUND)
    message(STATUS "Protobuf libraries found: ${Protobuf_LIBRARIES}")
    target_link_libraries(provider ${Protobuf_LIBRARIES})
endif()














