#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "func.h"

/* vehicle_factory实现 */

Vehicle *get_vehicle(char *type)
{
  if (strcmp(type, "bus") == 0)
  {
    return (Vehicle *)bus_constructor("Bus");
  }
  if (strcmp(type, "car") == 0)
  {
    return (Vehicle *)car_constructor("Car");
  }
  if (strcmp(type, "motorcycle") == 0)
  {
    return (Vehicle *)motorcycle_constructor("Motorcycle");
  }
  if (strcmp(type, "van") == 0)
  {
    return (Vehicle *)van_constructor("Van");
  }
  return NULL;
}

/* 创建具体处理器的函数 */
VehicleFactory *create_vehicle_factory()
{
  VehicleFactory *factory = (VehicleFactory *)malloc(sizeof(VehicleFactory));
  factory->get_vehicle = &get_vehicle;
  return factory;
}