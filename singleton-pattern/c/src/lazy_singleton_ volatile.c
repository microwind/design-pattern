#include "func.h"
#include <pthread.h>

// 静态指针，未被创建并分配内存空间，指向唯一实例
static LazySingletonVolatile *lazy_singleton_volatile_instance = NULL;

void lazy_singleton_volatile_run(LazySingletonVolatile *singleton)
{
  printf("\r\n LazySingletonVolatile::run() [name=%s value=%d]", singleton->name, singleton->value);
}

// 内部私有实例化函数，不公开
static LazySingletonVolatile *new_lazy_singleton_volatile(char *name)
{
  LazySingletonVolatile *singleton = (LazySingletonVolatile *)malloc(sizeof(LazySingletonVolatile));
  strcpy(singleton->name, name);
  singleton->run = &lazy_singleton_volatile_run;
  return singleton;
}

static inline void rmb()
{
  asm volatile("lfence");
}

static inline void wmb()
{
  asm volatile("sfence");
}

// 声明锁
pthread_mutex_t singleton_lock;

// 非线程安全懒汉模式，延迟初始化。多个线程同时调用函数时， 可能会被初始化多次，存在线程不安全问题
LazySingletonVolatile *get_lazy_singleton_volatile_instance(char *name)
{
  printf("\r\n get_lazy_singleton_volatile_instance() [name=%s]", name);
  if (pthread_mutex_init(&singleton_lock, NULL) != 0)
  {
    perror("error init mutext:");
  }

  // 通过加锁和volatile双重机制来防止线程并发导致安全隐患
  if (lazy_singleton_volatile_instance == NULL)
  {
    printf("\r\n new instance [name=%s]", name);
    pthread_mutex_lock(&singleton_lock);
    rmb();
    lazy_singleton_volatile_instance = new_lazy_singleton_volatile(name);
    wmb();
    pthread_mutex_unlock(&singleton_lock);
  }
  return lazy_singleton_volatile_instance;
}