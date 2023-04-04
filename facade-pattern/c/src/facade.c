#include "func.h"

// 外观模式实现类，是外部调用与内部子系统的衔接层

void encode_module_encoding(Facade *facade, int id)
{
  printf("\r\n Facade::encoding() [name=%s, id=%d]", facade->name, id);
  facade->network_module->request();
  facade->file_module->read_file();
  facade->encode_module->encoding();
  facade->file_module->save_file();
}

void encode_module_encrypt(Facade *facade, int id)
{
  printf("\r\n Facade::encrypt() [name=%s, id=%d]", facade->name, id);
  facade->file_module->read_file();
  facade->encode_module->encoding();
}

Facade *facade_constructor(char *name)
{
  AbstractFacade *abstract_facade = (AbstractFacade *)malloc(sizeof(AbstractFacade));
  FileModule *file_module = file_module_constructor("file_module");
  EncodeModule *encode_module = encode_module_constructor("encode_module");
  NetworkModule *network_module = network_module_constructor("network_module");
  strncpy(abstract_facade->name, name, 50);
  Facade *facade = (Facade *)abstract_facade;
  facade->file_module = file_module;
  facade->encode_module = encode_module;
  facade->network_module = network_module;
  facade->encoding = &encode_module_encoding;
  facade->encrypt = &encode_module_encrypt;
  return facade;
}