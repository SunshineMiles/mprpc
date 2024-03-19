//
// Created by zhangchuang on 2024/3/5.
//

#include <iostream>
#include "mprpcapplication.h"

#include "friend.pb.h"

int main(int argc , char **argv){

    // 整个项目启动后，想使用mprpc框架来享受rpc服务调用，一定需要先调用框架的初始化函数（只初始化一次）
    Mprpcapplication::Init(argc,argv);
    //  调用远程发布的rpc方法login
    fixbug::FriendServiceRpc_Stub stub(new MprpcChannel());

    // rpc方法的请求参数
    fixbug::GetFriendsListRequest request;
    request.set_userid(1000);

    // rpc方法的响应
    fixbug::GetFriendsListResponse response;
    //发起rpc方法的调用，同步的rpc调用过程    MprpcChannel::callmethod
    // RpcChannel -> RpcChannel::callMethod 集中来做所有rpc方法调用的参数序列化和网络发送
    MprpcController controller;
    stub.GetFriendsList(&controller ,&request,&response, nullptr);
    if(controller.Failed()){
        std::cout<< controller.ErrorText() << std::endl;
    }else{
        // 一次rpc调用结束
        if(0==response.result().errcode()){
            std::cout<<" rpc GetFriendsList response sucess" << response.sucess() << std::endl;
            int size =response.friends_size();
            for (int i=0;i<size;i++){
                std::cout<< "index:" << (i+1) << "name" << response.friends(i) << std::endl;
            }
        }else{
            std::cout<<"rpc GetFriendsList response error:" << response.result().errmsg() <<std::endl;
        }
    }

    return 0;
}