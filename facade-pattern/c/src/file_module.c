#include "func.h"

// 文件模块
void read_file()
{
  printf("\r\n FileModule::read_file() 读取文件。");
}

void save_file()
{
  printf("\r\n FileModule::save_file() 保存文件。");
}

FileModule *file_module_constructor(char *name)
{
  FileModule *module = (FileModule *)malloc(sizeof(FileModule));
  strncpy(module->name, name, 50);
  module->read_file = &read_file;
  module->save_file = &save_file;
  return module;
}