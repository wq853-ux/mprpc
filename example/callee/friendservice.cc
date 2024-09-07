#include <iostream>
#include <string>
#include "friend.pb.h"
#include "mprpcapplication.h"
#include "rpcprovider.h"
#include <vector>
#include "logger.h"


class FriendService : public fixbug::FriendServiceRpc
{
public:
  std::vector<std::string> GetFriendsList(uint32_t userid)
  {
    std::cout << "do GetFriendList service! userid:" << userid << std::endl;
    std::vector<std::string> vec;
    vec.push_back("zhang san");
    vec.push_back("li si");
    vec.push_back("wang wu");
    return vec;
  }

  // 重写基类方法
  void GetFriendsList(::google::protobuf::RpcController *controller,
                      const ::fixbug::GetFriendsListRequest *request,
                      ::fixbug::GetFriendsListResponse *response,
                      ::google::protobuf::Closure *done)
  {
    uint32_t userid = request->userid();

    std::vector<std::string> friendsList = GetFriendsList(userid);
    response->mutable_result()->set_errcode(0);
    response->mutable_result()->set_errmsg("");

    for (std::string &name : friendsList)
    {
      std::string *p = response->add_friends();
      *p = name;
    }
    done->Run();
  }
};

int main(int argc, char **argv)
{
  LOG_INFO("first log message!\n");
  LOG_ERR("%s:%s:%d", __FILE__, __FUNCTION__, __LINE__);

  // 调用框架初始化操作
  MprpcApplication::Init(argc, argv);

  // 把UserService对象发布到rpc节点上
  RpcProvider provider;
  provider.NotifyService(new FriendService());

  provider.Run(); // 启动发布服务

  return 0;
}