#include "func.h"

// 编码模块

void encoding()
{
  printf("\r\n EncodeModule::encoding() 进行编码处理。");
}

EncodeModule *encode_module_constructor(char *name)
{
  EncodeModule *module = (EncodeModule *)malloc(sizeof(EncodeModule));
  strncpy(module->name, name, 50);
  module->encoding = &encoding;
  return module;
}