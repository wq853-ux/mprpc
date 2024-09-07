#include <iostream>
#include "mprpcapplication.h"
#include "friend.pb.h"

int main(int argc, char **argv)
{
  // 程序启动以后，想使用mprpc框架来享受rpc服务调用，一定要先调用框架的初始化函数
  MprpcApplication::Init(argc, argv);

  // 调用远程发布的rpc方法GetFriendsList
  fixbug::FriendServiceRpc_Stub stub(new MprpcChannel());
  // rpc方法的请求参数
  fixbug::GetFriendsListRequest request;
  request.set_userid(1000);
  // rpc方法的响应
  fixbug::GetFriendsListResponse response;

  MprpcController controller;
  // 发起rpc方法的调用 同步rpc调用过程
  stub.GetFriendsList(&controller, &request, &response, nullptr); // 实际是调用RpcChannel::callMethod，集中来做所有rpc方法调用的参数序列化和网络发送

  // 一次rpc调用完成，读调用结果
  if (controller.Failed())
  {
    std::cout << controller.ErrorText() << std::endl;
  }
  else
  {
    if (response.result().errcode() == 0)
    {
      std::cout << "rpc GetFriendsList response success:" << std::endl;
      // 打印返回的好友列表
      int size = response.friends_size();
      for (int i = 0; i < size; ++i)
      {
        std::cout << "index:" << (i + 1) << "name:" << response.friends(i) << std::endl;
      }
    }
    else
    {
      std::cout << "rpc GetFriendsList response error:" << response.result().errmsg() << std::endl;
    }
  }
  

  return 0;
}