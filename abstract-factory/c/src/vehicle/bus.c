#include "../func.h"

/* Bus对象函数实现 */
void bus_run(Vehicle *vehicle)
{
  printf("\r\n bus_run() [name=%s]", vehicle->name);
}

/* 创建对象构造函数 */
Bus *bus_constructor(char *name)
{
  Bus *bus = (Bus *)malloc(sizeof(Bus));
  strncpy(bus->name, name, 50);
  bus->run = &bus_run;
  return bus;
}