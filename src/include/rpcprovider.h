//
// Created by zhangchuang on 2024/2/25.
//

#pragma once
#include <memory>
#include "google/protobuf/service.h"
#include <google/protobuf/descriptor.h>
#include <muduo/net/TcpServer.h>
#include <muduo/net/EventLoop.h>
#include <muduo/net/InetAddress.h>
#include <muduo/net/TcpConnection.h>
#include <string>
#include <functional>
#include <unordered_map>

// 框架提供的专门服务发布rpc服务的网络对象类

class RpcProvider{
public:
    // 这里是框架提供给外部使用的，可以发布rpc方法的函数接口
    void NotifyService(google::protobuf::Service *service);
    // 启动rpc服务节点,开始提供rpc远程网络调用服务
    void Run();


private:
    // 组合了TcpServer
    // std::unique_ptr<muduo::net::TcpServer> m_tcpserverPtr;
    // 组合了EventLoop 有epoll
    muduo::net::EventLoop m_eventLoop;

        //  服务类型信息
    struct ServiceInfo{
        // 保存服务对象
        google::protobuf::Service *m_service ;
        // 保存服务方法(名字+方法的描述）
        std::unordered_map<std::string, const google::protobuf::MethodDescriptor*>m_methodMap;
    };
    // 存储注册成功服务对象和其它服务方法的所有信息
    std::unordered_map<std::string ,ServiceInfo>m_serviceMap;

    // 新的socket连接回调
    void OnConnection(const muduo::net::TcpConnectionPtr &conn);
    // 已建立连接的用户读写事件回调
    void OnMessage(const muduo::net::TcpConnectionPtr &conn, muduo::net::Buffer *buffer, muduo::Timestamp time );
    // Closure的回调操作，用于序列化rpc响应和网络发送
    void SendRpcResponse(const muduo::net::TcpConnectionPtr &conn ,google::protobuf::Message* );

};