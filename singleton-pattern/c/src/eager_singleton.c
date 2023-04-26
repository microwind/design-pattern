#include "func.h"

void eager_singleton_run(EagerSingleton *singleton)
{
  printf("\r\n EagerSingleton::run() [name=%s value=%d]", singleton->name, singleton->value);
}

// 直接用static声明struct对象并初始化，相当于实例化类
static EagerSingleton earge_singleton_instance = {
    .name = "",
    .run = &eager_singleton_run,
    .value = 0,
};

// 饿汉模式，全局唯一，系统加载则初始化变量，无并发安全问题，但可能存在浪费
EagerSingleton *get_eager_singleton_instance(char *name)
{
  // 如果name为空则更新name
  if (strcmp(earge_singleton_instance.name, "") == 0)
  {
    strcpy(earge_singleton_instance.name, name);
  }
  return &earge_singleton_instance;
}