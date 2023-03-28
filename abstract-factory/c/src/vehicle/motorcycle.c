#include "../func.h"

/* Motorcycle对象函数实现 */
void motorcycle_run(Vehicle *vehicle)
{
  printf("\r\n motorcycle_run() [name=%s]", vehicle->name);
}

/* 创建对象构造函数 */
Motorcycle *motorcycle_constructor(char *name)
{
  Motorcycle *motorcycle = (Motorcycle *)malloc(sizeof(Motorcycle));
  strncpy(motorcycle->name, name, 50);
  motorcycle->run = &motorcycle_run;
  return motorcycle;
}