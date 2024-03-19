//
// Created by zhangchuang on 2024/3/3.
//


#include <iostream>
#include "mprpcapplication.h"
#include "mprpcchannel.h"
#include "user.pb.h"
int main(int argc , char **argv){

    // 整个项目启动后，想使用mprpc框架来享受rpc服务调用，一定需要先调用框架的初始化函数（只初始化一次）
    Mprpcapplication::Init(argc,argv);
    //  调用远程发布的rpc方法login
    fixbug::UserServiceRpc_Stub stub(new MprpcChannel());

    // rpc方法的请求参数
    fixbug::LoginRequest request;
    request.set_name("zhang san");
    request.set_pwd("123456");

    // rpc方法的响应
    fixbug::LoginResponse response;
    //发起rpc方法的调用，同步的rpc调用过程    MprpcChannel::callmethod
    // RpcChannel -> RpcChannel::callMethod 集中来做所有rpc方法调用的参数序列化和网络发送
    stub.Login(nullptr ,&request,&response, nullptr);

    // 一次rpc调用结束
    if(0==response.result().errcode()){
        std::cout<<" rpc login response" << response.sucess() << std::endl;
    }else{
        std::cout<<"rpc login response error:" << response.result().errmsg() <<std::endl;
    }

    // 演示调用远程发布的rpc方法Register
    fixbug::RegisterRequest req;
    req.set_id(2000);
    req.set_name("mprpc");
    req.set_pwd("66666");

    // 以同步的方法发起rpc请求，等待结果
    fixbug::RegisterResponse rsp;
    stub.Register(nullptr ,&req,&rsp, nullptr);

    if(0==rsp.result().errcode()){
        std::cout<<" rpc register response" << rsp.sucess() << std::endl;
    }else{
        std::cout<<"rpc register response error:" << rsp.result().errmsg() <<std::endl;
    }


    return 0;
}