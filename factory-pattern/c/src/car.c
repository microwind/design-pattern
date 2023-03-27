#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "func.h"

/* Car对象函数实现 */
void car_run()
{
  printf("Car::Run(). \r\n");
}

/* 创建具体处理器的函数 */
Car *car_constructor(char *name)
{
  Car *car = (Car *)malloc(sizeof(Car));
  strncpy(car->name, name, 50);
  car->run = &car_run;
  return car;
}