## 代码结构
```shell
- src
  - func.h # 头文件，定义接口与数据
  - eager_singleton.c # 饿汉模式，直接返回已经初始化的实例
  - lazy_singleton_ volatile.c # 懒汉模式，延迟实例化，请求实例时判断，如果已经实例化过就直接返回
  - lazy_singleton_safe.c # 线程安全懒汉模式，延迟初始化。多个线程同时调用函数时，以动态方式创建互斥锁，防止线程并发导致的不安全
  - lazy_singleton.c # 静态指针，未被创建并分配内存空间，指向唯一实例。非线程安全懒汉模式，延迟初始化
```

## 测试验证

```shell
$ cd ./singleton-pattern/c
$ gcc test/test.c ./src/*.c
$ ./a.out
```
