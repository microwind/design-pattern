#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// 懒汉模式，不重复实例化，非线程安全
typedef struct LazySingleton LazySingleton;
typedef struct LazySingleton
{
  char name[50];
  int value;
  void (*run)(LazySingleton *);
} LazySingleton;

LazySingleton *get_lazy_singleton_instance();

// 懒汉模式，加锁，线程安全
typedef struct LazySingletonSafe LazySingletonSafe;
typedef struct LazySingletonSafe
{
  char name[50];
  int value;
  void (*run)(LazySingletonSafe *);
} LazySingletonSafe;
LazySingletonSafe *get_lazy_singleton_safe_instance();

// 懒汉模式，加锁，线程安全
typedef struct EagerSingleton EagerSingleton;
typedef struct EagerSingleton
{
  char name[50];
  int value;
  void (*run)(EagerSingleton *);
} EagerSingleton;
EagerSingleton *get_eager_singleton_instance();

// 懒汉模式，加锁，增加volatile
typedef struct LazySingletonVolatile LazySingletonVolatile;
typedef struct LazySingletonVolatile
{
  char name[50];
  int value;
  void (*run)(LazySingletonVolatile *);
} LazySingletonVolatile;
LazySingletonVolatile *get_lazy_singleton_volatile_instance();
