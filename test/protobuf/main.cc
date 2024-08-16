#include "test.pb.h"
#include <iostream>
#include <string>
using namespace fixbug;

int main()
{
  /* LoginResponse rsp;
  ResultCode *rc = rsp.mutable_result();
  rc->set_errcode(1);
  rc->set_errmsg("登录处理失败了"); */

  GetFriendListsResponse rspB;
  ResultCode *rc = rspB.mutable_result();
  rc->set_errcode(0);

  User *user1 = rspB.add_friend_list();
  user1->set_name("张三");
  user1->set_age(20);
  user1->set_sex(User::MAN);

  User *user2 = rspB.add_friend_list();
  user2->set_name("张三");
  user2->set_age(20);
  user2->set_sex(User::MAN);

  std::cout << rspB.friend_list_size() << std::endl;

  

  return 0;
}

int main1()
{
  // 封装了login请求对象的数据
  LoginRequest req;
  req.set_name("zhang san");
  req.set_pwd("123456");

  // 序列化：对象转化为字节流、字符流
  std::string send_str;
  if (req.SerializeToString(&send_str))
  {
    std::cout << send_str.c_str() << std::endl;
  }

  // 从send_str反序列化login请求对象
  LoginRequest reqB;
  if (reqB.ParseFromString(send_str)){
    std::cout << reqB.name() << std::endl;
    std::cout << reqB.pwd() << std::endl;
  }

  return 0;
}
