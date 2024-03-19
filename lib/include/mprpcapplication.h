//
// Created by zhangchuang on 2024/2/25.
//

#pragma once
#include "mprpcconfig.h"
#include "mprpcchannel.h"
#include "mprpccontroller.h"

// mprpc框架的初始化类，负责框架的初始化操作
class Mprpcapplication {
public:
    static void Init(int argc , char ** argv);
    static Mprpcapplication& GetInstance();
    static MprpcConfig& GetConfig();
private:
    static MprpcConfig m_config;
    Mprpcapplication(){}
    // 单列模式
    Mprpcapplication(const Mprpcapplication&) =delete; // 拷贝构造函数声明并将其删除
    Mprpcapplication(Mprpcapplication&&) =delete;  // 移动构造函数声明并将其删除
};

