#include <iostream>
#include <string>
#include "user.pb.h"

// UserService原来是一个本地服务，提供了两个进程内的本地方法，Login和GetFriendLists
class UserService : public fixbug::UserServiceRpc
{
public:
  bool Login(std::string name, std::string pwd)
  {
    std::cout << "doing local service: Login" << std::endl;
    std::cout << "name:" << name << " pwd:" << pwd << std::endl;
    return true;
  }

  // 重写基类UserServiceRpc的虚函数，下面这些方法都是框架直接调用的
  /*
    1. caller 发起rpc请求 ==> Login(LoginRequest) ==> muduo ==> callee 接收
    2. callee ==> Login(LoginRequest) => 交到下面重写的这个Login方法上了
  */
  void Login(::google::protobuf::RpcController *controller,
             const ::fixbug::LoginRequest *request,
             ::fixbug::LoginResponse *response,
             ::google::protobuf::Closure *done)
  {
    std::string name = request->name();
    std::string pwd = request->pwd();

    bool login_result = Login(name, pwd); 

    fixbug::ResultCode *code = response->mutable_result();
    code->set_errcode(0);
    code->set_errmsg("");
    response->set_success(login_result);

    // 回调
    
  }
};

int main()
{

  return 0;
}