#include "func.h"

// 网络模块
void request()
{
  printf("\r\n NetworkModule::request() 远程读取。");
}

NetworkModule *network_module_constructor(char *name)
{
  NetworkModule *module = (NetworkModule *)malloc(sizeof(NetworkModule));
  strncpy(module->name, name, 50);
  module->request = &request;
  return module;
}