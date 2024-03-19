//
// Created by zhangchuang on 2024/2/25.
//
#include <unistd.h>
#include "mprpcapplication.h"
#include "mprpcconfig.h"
#include <iostream>
MprpcConfig Mprpcapplication::m_config;

void ShowArgHelp(){
    std::cout<< "format: command -i <configfile>" <<std::endl;
}
void Mprpcapplication::Init(int argc , char ** argv){
    // 初始化
    if(argc<2){
        ShowArgHelp();
        exit(EXIT_FAILURE);
    }
    // 解析命令行参数
    int c=0;
    std::string config_file;
    while((c=getopt(argc , argv , "i:")) != -1){
        switch(c){
            case 'i':
                config_file =optarg;
                break;
            case '?':
                std::cout<< "invalid args!" << std::endl;
                ShowArgHelp();
                exit(EXIT_FAILURE);
            case ':' :
                std::cout<< "EXIT_FAILURE"<< std::endl;
                ShowArgHelp();
                exit(EXIT_FAILURE);
            default:
                break;
        }
    }
    // 开始加载配置文件 rpcserver_ip =     rpcserver_port    zookeeper_ip=        zookeeper_port =
    m_config.LoadConfigFile(config_file.c_str());
//    std::cout<<"rpcserverip :"<< m_config.Load("rpcserverip")<<std::endl;
//    std::cout<<"rpcserverport :"<< m_config.Load("rpcserverport")<<std::endl;
//    std::cout<<"zookeeperip :"<< m_config.Load("zookeeperip")<<std::endl;
//    std::cout<<"zookeeperport :"<< m_config.Load("zookeeperport")<<std::endl;

}




Mprpcapplication& Mprpcapplication::GetInstance(){
    //  在首次调用时初始化，保证唯一实例,保证线程的安全性
    static Mprpcapplication app;
    // app 被声明为静态局部变量 static Mprpcapplication app;。这意味着 app 在第一次调用 GetInstance 函数时会被初始化，
    // 而且只会被初始化一次。随后的函数调用会直接返回已经初始化过的 app 实例，而不会再重新创建新的实例。
    return app;
}

MprpcConfig& Mprpcapplication::GetConfig(){
    return m_config;
}