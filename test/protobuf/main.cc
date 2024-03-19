//
// Created by zhangchuang on 2024/2/5.
//

#include"test.pb.h"
#include <iostream>
#include <string>
using namespace fixbug;



int main(){
    LoginResponse rsp;
    // mutable_result 获取对象的成员变量的指针
    ResultCode *rc  = rsp.mutable_result();
    rc->set_errcode(0);
    rc->set_errmsg("登录处理失败");

    GetFriendListResponse rsp1;
    ResultCode * rc1 = rsp1.mutable_result();
    rc1->set_errcode(0);

    User *user1 = rsp1.add_friend_list(); // 增加一个成员
    user1->set_name("zhang san");
    user1->set_age(20);
    user1->set_sex(User::MAN);

    User *user2 = rsp1.add_friend_list(); // 增加一个成员
    user2->set_name("zhang san2");
    user2->set_age(20);
    user2->set_sex(User::MAN);

    std::cout << rsp1.friend_list_size() << std::endl;

    return 0;
}



int main1(){

    // 处理对象类型和列表类型



    // 封装了login请求对象的数据
    LoginRequest req;
    req.set_name("zhang san");
    req.set_pwd("123456");

    // 对象数据的序列化 =》 char *
    std::string send_str;
    if(req.SerializeToString(&send_str)){
        std::cout<< send_str.c_str() << std::endl;
    }

    // 从send_str反序列化一个login请求对象
    LoginRequest reqB;
    if(reqB.ParseFromString(send_str)){
        std::cout<< reqB.name() << std::endl;
        std::cout<< reqB.pwd() << std::endl;
    }


    return 0;
}
