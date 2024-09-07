#include <iostream>
#include <string>
#include "user.pb.h"
<<<<<<< HEAD
#include "mprpcapplication.h"
#include "rpcprovider.h"
=======
>>>>>>> 2ea601eed4f7530ca0c589c43c27297b0828fefc

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

<<<<<<< HEAD
  bool Register(uint32_t id, std::string name, std::string pwd)
  {
    std::cout << "doing local service: Register" << std::endl;
    std::cout << "id:" << id << "name:" << name << " pwd:" << pwd << std::endl;
    return true;
  }

=======
>>>>>>> 2ea601eed4f7530ca0c589c43c27297b0828fefc
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

<<<<<<< HEAD
    // 响应对象数据的序列化和网络发送（框架实现）
    done->Run();
  }

  void Register(::google::protobuf::RpcController* controller,
                       const ::fixbug::RegisterRequest* request,
                       ::fixbug::RegisterResponse* response,
                       ::google::protobuf::Closure* done)
  {
    uint32_t id = request->id();
    std::string name = request->name();
    std::string pwd = request->pwd();

    bool ret = Register(id, name, pwd);

    response->mutable_result()->set_errcode(0);
    response->mutable_result()->set_errmsg("");
    response->set_success(ret);

    done->Run();
  }
};

int main(int argc, char **argv)
{
  // 调用框架初始化操作
  MprpcApplication::Init(argc, argv);

  // 把UserService对象发布到rpc节点上
  RpcProvider provider; 
  provider.NotifyService(new UserService());

  provider.Run(); //启动发布服务
=======
    // 回调
    
  }
};

int main()
{
>>>>>>> 2ea601eed4f7530ca0c589c43c27297b0828fefc

  return 0;
}