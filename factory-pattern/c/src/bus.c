#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "func.h"

/* Bus对象函数实现 */
void bus_run()
{
  printf("Bus::Run(). \r\n");
}

/* 创建具体处理器的函数 */
Bus *bus_constructor(char *name)
{
  Bus *bus = (Bus *)malloc(sizeof(Bus));
  strncpy(bus->name, name, 50);
  bus->run = &bus_run;
  return bus;
}