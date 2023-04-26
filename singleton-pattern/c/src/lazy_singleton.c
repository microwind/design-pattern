#include "func.h"

// 静态指针，未被创建并分配内存空间，指向唯一实例
static LazySingleton *lazy_singleton_instance = NULL;

void lazy_singleton_run(LazySingleton *singleton)
{
  printf("\r\n LazySingleton::run() [name=%s value=%d]", singleton->name, singleton->value);
}

// 非线程安全懒汉模式，延迟初始化。多个线程同时调用函数时， 可能会被初始化多次，存在线程不安全问题
LazySingleton *get_lazy_singleton_instance(char *name)
{
  printf("\r\n get_lazy_singleton_instance() [name=%s]", name);
  // 外部的实例，如果不存在则初始化，否则直接返回实例
  if (lazy_singleton_instance == NULL)
  {
    printf("\r\n new instance [name=%s]", name);
    lazy_singleton_instance = (LazySingleton *)malloc(sizeof(LazySingleton));
    strcpy(lazy_singleton_instance->name, name);
    lazy_singleton_instance->run = &lazy_singleton_run;
  }
  return lazy_singleton_instance;
}