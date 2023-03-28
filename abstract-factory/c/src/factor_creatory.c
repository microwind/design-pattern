#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "func.h"

/* 工厂创建者，返回某类工厂建造者 */
AbstractFactory *get_factory(char *name)
{
  if (strcmp(name, "vehicle") == 0)
  {
    return (AbstractFactory *)create_vehicle_factory();
  }
  if (strcmp(name, "shop") == 0)
  {
    return (AbstractFactory *)create_shop_factory();
  }
  return NULL;
}

/* 初始化工厂创建者 */
FactoryCreatory *factory_creatory_constructor()
{
  FactoryCreatory *factory_creatory = (FactoryCreatory *)malloc(sizeof(FactoryCreatory));
  // 通过参数来获取某个工厂
  factory_creatory->get_factory = &get_factory;
  return factory_creatory;
}