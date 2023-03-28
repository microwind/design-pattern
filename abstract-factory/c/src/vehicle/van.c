#include "../func.h"

/* Van对象函数实现 */
void van_run(Vehicle *vehicle)
{
  printf("\r\n van_run() [name=%s]", vehicle->name);
}

/* 创建对象构造函数 */
Van *van_constructor(char *name)
{
  Van *van = (Van *)malloc(sizeof(Van));
  strncpy(van->name, name, 50);
  van->run = &van_run;
  return van;
}