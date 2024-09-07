#pragma once
#include "lockqueue.h"
#include <string>

enum LogLevel
{
  INFO, //普通日志信息
  ERROR //错误信息
};
// Mprpc框架日志系统
class Logger
{
public:
  static Logger& GetInstance(); //获取日志的单例
  void SetLogLevel(LogLevel level); //设置日志级别
  void Log(std::string msg); //写日志
private:
  int m_loglevel; //记录日志级别
  LockQueue<std::string> m_lckQue;

  Logger();
  Logger(const Logger&) = delete;
  Logger(Logger&&) = delete;
};

// 定义宏 LOG_INFO("xxx %d %s", 20, "xxxx")
#define LOG_INFO(logmsgformat, ...) \
  do \
  { \
    Logger &logger = Logger::GetInstance(); \
    logger.SetLogLevel(INFO); \
    char c[1024] = {0}; \
    snprintf(c, 1024, logmsgformat, ##__VA_ARGS__); \
    logger.Log(c);\
  } while(0)

  #define LOG_ERR(logmsgformat, ...) \
    do \
    { \
      Logger &logger = Logger::GetInstance(); \
      logger.SetLogLevel(INFO); \
      char c[1024] = {0}; \
      snprintf(c, 1024, logmsgformat, ##__VA_ARGS__); \
      logger.Log(c); \
    } while(0)
