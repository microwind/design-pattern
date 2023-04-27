# 【单例设计模式详解】Java/JS/Go/Python/TS不同语言实现

# 简介
单例模式（Singleton Pattern）属于创建型设计模式，这种模式只创建一个单一的类，保证一个类只有一个实例，并提供一个访问该实例的全局节点。

当您想控制实例数目，节省系统资源，并不想混用的时候，可以使用单例模式。单例有很多种实现方式，主要分为懒汉和饿汉模式，同时要通过加锁来避免线程安全。不同语言的单例实现略有差异，可以通过查看不同版本的源码来深入理解其中的差异。

# 作用
1. 避免全局使用的类频繁地创建与销毁。
2. 保证一个类仅有一个实例，并提供一个访问它的全局访问点。

# 实现步骤
1. 创建单例类，注意线程安全
2. 返回全局唯一实例

# UML
<img src="../docs/uml/singleton-pattern.png">

# Java代码

单例实现，不同语言有很大不同，跟语言特性有关。请查看其他源码进行比较。

## 饿汉式（线程安全）
```java
// SingletonEager.java 当类被加载的时候会初始化，静态变量被创建并分配内存空间 
public class SingletonEager {
  private String name = "SingletonEager";
  // 类加载时就初始化，浪费内存
  private static final SingletonEager instance = new SingletonEager();

  // 构造函数是private，不允许实例化
  private SingletonEager() {

  }
  public static SingletonEager getInstance() {
    return instance;
  }

  public void run() {
    System.out.println("SingletonEager::run() " + this.name);
  }
}
```

## 饱汉式
```java
// SingletonLazy.java 懒汉式也叫饱汉式，增加synchronized来保证线程安全
public class SingletonLazy {

  private static SingletonLazy instance;
  private String name;

  private SingletonLazy() {

  }

  // 类初始化时，静态变量static的instance未被创建并分配内存空间
  // 当getInstance方法第一次被调用时，再初始化instance变量，并分配内存
  // 相当于延迟到调用时再实例化，加synchronized以便线程安全，不加则存在并发时多个实例的情形
  public static synchronized SingletonLazy getInstance(String name) {
    if (instance == null) {
      instance = new SingletonLazy();
      instance.name = name;
    }
    return instance;
  }

  public void run() {
    System.out.println("SingletonLazy::run() " + this.name);
  }
}
```

## 静态内部类
```java
// SingletonInner.java 静态内部类方式，既实现延迟加载，也保障线程安全。
public class SingletonInner {

  private String name;

  private SingletonInner() {

  }

  // 静态内部类利用了类加载初始化机制，外部类加载时，并不会加载内部类，也不会执行
  // 虚拟机会保证方法在多线程环境下使用加锁同步，只会执行一次，因此线程安全
  private static class Inner {
    private static final SingletonInner instance = new SingletonInner();
  }

  // 当执行getInstance()方法时，虚拟机才会加载静态内部类
  public static SingletonInner getInstance(String name) {
    if (Inner.instance.name == null) {
      Inner.instance.name = name;
    }
    return Inner.instance;
  }

  public void run() {
    System.out.println("SingletonInner::run() " + this.name);
  }
}
```

## 双重检验懒汉
```java
// SingletonDoubleCheck.java 双重检验懒汉单例，单例模式最优方案，线程安全并且效率高 
public class SingletonDoubleCheck {

  // 定义一个静态私有变量(不初始化，不使用final关键字）
  // 可以使用volatile保证多线程访问时变量的可见性
  // 这样避免了初始化时其他变量属性还没赋值完时，被另外线程调用
  private static volatile SingletonDoubleCheck instance;
  private String name;
  private SingletonDoubleCheck() {

  }

  // 延迟到调用时实例化
  public static SingletonDoubleCheck getInstance(String name) {
    if (instance == null) {
      // 在实例化时再synchronized
      synchronized (SingletonDoubleCheck.class) {
        if (instance == null) {
          instance = new SingletonDoubleCheck();
          instance.name = name;
        }
      }
    }
    return instance;
  }

  public void run() {
    System.out.println("SingletonDoubleCheck::run() " + this.name);
  }
}

```

## 测试调用
```java
    /**
     * 单例模式就是一个类只创建一个实例，以便节省开销和保证统一
     * 对于多线程语言需要注意线程安全和性能之间取得一个平衡
     */
    SingletonEager singletonEager1 = SingletonEager.getInstance();
    SingletonEager singletonEager2 = SingletonEager.getInstance();
    singletonEager1.run();
    singletonEager2.run();
    // 两个实例相等
    System.out.println("singletonEager1 == singletonEager2 ? " + String.valueOf(singletonEager1 == singletonEager2));

    /*********************** 分割线 ******************************************/

    SingletonLazy singletonLazy1 = SingletonLazy.getInstance("singletonLazy1");
    SingletonLazy singletonLazy2 = SingletonLazy.getInstance("singletonLazy2");
    singletonLazy1.run();
    singletonLazy2.run();

    /*********************** 分割线 ******************************************/

    SingletonDoubleCheck singletonDoubleCheck1 = SingletonDoubleCheck.getInstance("singletonDoubleCheck1");
    SingletonDoubleCheck singletonDoubleCheck2 = SingletonDoubleCheck.getInstance("singletonDoubleCheck2");
    singletonDoubleCheck1.run();
    singletonDoubleCheck2.run();

    /*********************** 分割线 ******************************************/

    SingletonInner singletonInner1 = SingletonInner.getInstance("singletonInner1");
    SingletonInner singletonInner2 = SingletonInner.getInstance("singletonInner2");
    singletonInner1.run();
    singletonInner2.run();
```

# Go代码
```go
// DoubleCheckSingleton.go
import (
  "fmt"
  "sync"
)

// 安全懒汉模式的升级版，通过sync的Mutex实现双重检验
type DoubleCheckSingleton struct {
  name string
}

func (s *DoubleCheckSingleton) Run() {
  fmt.Println("DoubleCheckSingleton::run()", s.name)
}

// 定义私有变量，用来保存实例
var doubleCheckSingletonInstance *DoubleCheckSingleton
var lock = &sync.Mutex{}

// 是懒汉模式安升级版，双重检查来来支持延迟实例化单例对象
func GetDoubleCheckSingletonInstance(name string) *DoubleCheckSingleton {
  // 未实例化才进行加锁
  if doubleCheckSingletonInstance == nil {
    lock.Lock()
    defer lock.Unlock()
    // 为了保险，锁住之后再次检查是否已实例化
    if doubleCheckSingletonInstance == nil {
      doubleCheckSingletonInstance = &DoubleCheckSingleton{}
      doubleCheckSingletonInstance.name = name
    }
  }

  return doubleCheckSingletonInstance
}

```

# JS版本
```js
// LazySingleton.js
export class LazySingleton {
  static instance
  constructor(alias) {
    this.alias = alias
  }

  // 懒汉模式，延迟实例化，请求实例时判断，如果已经实例化过就直接返回
  // js是单线程语言，无需考虑多线程问题
  static getInstance(alias) {
    if (this.instance === undefined) {
      this.instance = new LazySingleton(alias)
    }
    return this.instance
  }

  run() {
    console.log('LazySingleton::run()', this.alias)
  }
}
```

# Python语言
```py
# SingletonSafe.py
from threading import Lock, Thread


# 加锁的基于元类的单例模式，基于元类type创建的加强版
class SingletonMeta(type):
    # 线程安全单例模式，适用python3
    _instances = {}

    _lock: Lock = Lock()

    def __call__(cls, *args, **kwargs):
        with cls._lock:
            if cls not in cls._instances:
                instance = super().__call__(*args, **kwargs)
                cls._instances[cls] = instance
        return cls._instances[cls]

# 继承SingletonMeta就是单例
class SingletonSafe(metaclass=SingletonMeta):
    name: str = None

    def __init__(self, name: str) -> None:
        self.name = name

    def run(self):
        print('SingletonSafe::run()', self.name)

```

# C语言
```c
// lazy_singleton_safe.c
#include "func.h"
#include <pthread.h>

// 静态指针，未被创建并分配内存空间，指向唯一实例
static LazySingletonSafe *lazy_singleton_safe_instance = NULL;

void lazy_singleton_safe_run(LazySingletonSafe *singleton)
{
  printf("\r\n LazySingletonSafe::run() [name=%s value=%d]", singleton->name, singleton->value);
}

// 内部私有实例化函数，不公开
static LazySingletonSafe *new_lazy_singleton_safe(char *name)
{
  LazySingletonSafe *singleton = (LazySingletonSafe *)malloc(sizeof(LazySingletonSafe));
  strcpy(singleton->name, name);
  singleton->run = &lazy_singleton_safe_run;
  return singleton;
}

// 声明锁
pthread_mutex_t singleton_lock;

// 非线程安全懒汉模式，延迟初始化。多个线程同时调用函数时， 可能会被初始化多次，存在线程不安全问题
LazySingletonSafe *get_lazy_singleton_safe_instance(char *name)
{
  printf("\r\n get_lazy_singleton_safe_instance() [name=%s]", name);
  if (pthread_mutex_init(&singleton_lock, NULL) != 0)
  {
    perror("error init mutext:");
  }

  // 通过加锁来防止线程并发导致的不安全
  if (lazy_singleton_safe_instance == NULL)
  {
    printf("\r\n new instance [name=%s]", name);
    pthread_mutex_lock(&singleton_lock);
    lazy_singleton_safe_instance = new_lazy_singleton_safe(name);
    pthread_mutex_unlock(&singleton_lock);
  }
  return lazy_singleton_safe_instance;
}
```
## 更多语言版本
不同语言设计模式源码：[https://github.com/microwind/design-pattern](https://github.com/microwind/design-pattern)