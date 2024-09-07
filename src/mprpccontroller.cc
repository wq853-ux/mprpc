#include "mprpccontroller.h"

MprpcController::MprpcController()
{
  m_falied = false;
  m_errText = "";
}
void MprpcController::Reset()
{
  m_falied = false;
  m_errText = "";
}
bool MprpcController::Failed() const
{
  return m_falied;
}
std::string MprpcController::ErrorText() const
{
  return m_errText;
}
void MprpcController::SetFailed(const std::string &reason)
{
  m_falied = true;
  m_errText = reason;
}

void MprpcController::StartCancel(){}
bool MprpcController::IsCanceled() const{return false;}
void MprpcController::NotifyOnCancel(google::protobuf::Closure *callback){}