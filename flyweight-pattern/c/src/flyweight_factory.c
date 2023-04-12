#include "func.h"

/* 享元工厂，储存一个对象共享池，已经生成过的对象直接取出 */

// 全局用来记录Flyweight的对象数组
static Flyweight **flyweight_factory_member_pool;
// 全局用来记录Flyweight的名称数组
static char **flyweight_factory_name_pool;
// 全局记录flyweight_factory的数量
static int flyweight_factory_pool_size = 0;

// 这里的name可以认为是内部状态，在构造时确定，具有唯一性。
Flyweight *get_factory(char *name)
{

  // 定义公共map用作共享池子，全局共用
  int number = 100;
  if (flyweight_factory_member_pool == NULL)
  {
    flyweight_factory_member_pool = (Flyweight **)calloc(number, sizeof(Flyweight));
  }
  if (flyweight_factory_name_pool == NULL)
  {
    flyweight_factory_name_pool = (char **)calloc(number, sizeof(char));
  }

  Flyweight **flyweight_pool = flyweight_factory_member_pool;
  char **name_pool = flyweight_factory_name_pool;
  int length = flyweight_factory_pool_size;

  int flyweight_index = -1;
  for (int i = 0; i < length; i++)
  {
    if (name == name_pool[i])
    {
      flyweight_index = i;
      break;
    }
  }

  Flyweight *flyweight;

  // 如果已经存在则复用前面的对象
  if (flyweight_index >= 0)
  {
    flyweight = flyweight_pool[flyweight_index];
    printf("\r\n FlyweightFactory::get_factory() 成功获取具体享元[name=%s]", name);
  }
  else
  {
    // 不存在则创建新的对象放入到池子里
    flyweight = (Flyweight *)concrete_flyweight_constructor(name);
    flyweight_pool[length] = flyweight;
    name_pool[length] = name;
    flyweight_factory_pool_size += 1;
    printf("\r\n FlyweightFactory::get_factory() 成功创建具体享元[name=%s]", name);
  }
  return flyweight;
}

Flyweight **get_flyweight_pool()
{
  return flyweight_factory_member_pool;
}

int get_flyweight_pool_size()
{
  return flyweight_factory_pool_size;
}

FlyweightFactory *flyweight_factory_constructor(char *name)
{
  FlyweightFactory *factory = (FlyweightFactory *)malloc(sizeof(FlyweightFactory));
  strncpy(factory->name, name, 50);
  factory->get_factory = &get_factory;
  factory->get_pool = &get_flyweight_pool;
  factory->get_pool_size = &get_flyweight_pool_size;
  return factory;
}