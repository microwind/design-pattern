#include "func.h"

/* vehicle_factory实现 */

Vehicle *get_vehicle(char *type, char *name)
{
  if (strcmp(type, "bus") == 0)
  {
    return (Vehicle *)bus_constructor(name);
  }
  if (strcmp(type, "car") == 0)
  {
    return (Vehicle *)car_constructor(name);
  }
  if (strcmp(type, "motorcycle") == 0)
  {
    return (Vehicle *)motorcycle_constructor(name);
  }
  if (strcmp(type, "van") == 0)
  {
    return (Vehicle *)van_constructor(name);
  }
  return NULL;
}

/* 创建具体工厂的函数 */
VehicleFactory *create_vehicle_factory()
{
  VehicleFactory *factory = (VehicleFactory *)malloc(sizeof(VehicleFactory));
  factory->get_vehicle = &get_vehicle;
  factory->get_shop = NULL;
  return factory;
}