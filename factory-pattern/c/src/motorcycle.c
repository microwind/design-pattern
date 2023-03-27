#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "func.h"

/* Motorcycle对象函数实现 */
void motorcycle_run()
{
  printf("Motorcycle::Run(). \r\n");
}

/* 创建具体处理器的函数 */
Motorcycle *motorcycle_constructor(char *name)
{
  Motorcycle *motorcycle = (Motorcycle *)malloc(sizeof(Motorcycle));
  strncpy(motorcycle->name, name, 50);
  motorcycle->run = &motorcycle_run;
  return motorcycle;
}