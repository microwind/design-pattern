#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// 享元角色抽象接口
typedef struct Flyweight
{
    char name[50];
    char kind[50];
    void (*operate)(struct Flyweight *, char *);
} Flyweight;

// 享元工厂，储存一个对象共享池，已经生成过的对象直接取出
typedef struct FlyweightFactory
{
    char name[50];
    int (*get_pool_size)();
    Flyweight **(*get_pool)();
    Flyweight *(*get_factory)(char *name);
} FlyweightFactory;
FlyweightFactory *flyweight_factory_constructor(char *name);

// 具体享元角色，实现抽象接口，用于共享状态，一个类被创建以后就不用重复创建了
typedef struct ConcreteFlyweight
{
    // 内部状态，即不会随着环境的改变而改变的可共享部分
    // 这里的name也是对象保存的key
    char name[50];
    char kind[50];
    void (*operate)(struct ConcreteFlyweight *, char *);
} ConcreteFlyweight;
ConcreteFlyweight *concrete_flyweight_constructor(char *name);
ConcreteFlyweight *concrete_flyweight_init(char *name);

// 无需共享实例的角色，用于处理外部非共享状态
// 当不需要共享时用这样的类
typedef struct UnsharedConcreteFlyweight
{
    char name[50];
    char kind[50];
    void (*operate)(struct UnsharedConcreteFlyweight *, char *);
} UnsharedConcreteFlyweight;
UnsharedConcreteFlyweight *unshared_concrete_flyweight_constructor(char *name);
UnsharedConcreteFlyweight *unshared_concrete_flyweight_init(char *name);