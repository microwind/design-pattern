#include "../func.h"

/* Car对象函数实现 */
void car_run(Vehicle *vehicle)
{
  printf("\r\n car_run() [name=%s]", vehicle->name);
}

/* 创建对象构造函数 */
Car *car_constructor(char *name)
{
  Car *car = (Car *)malloc(sizeof(Car));
  strncpy(car->name, name, 50);
  car->run = &car_run;
  return car;
}