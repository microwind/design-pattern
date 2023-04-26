#include "../src/func.h"

int main(void)
{
  printf("test start:\r\n");
  /**
   * 单例模式就是一个类只创建一个实例，以便节省开销和保证统一
   * 对于多线程语言需要注意线程安全和性能之间取得一个平衡
   */

  // 懒汉模式，调用函数时实例化
  LazySingleton *lazy_singleton1 = get_lazy_singleton_instance("lazySingleton1");
  LazySingleton *lazy_singleton2 = get_lazy_singleton_instance("lazySingleton2");
  lazy_singleton1->run(lazy_singleton1);
  // 实例相同
  lazy_singleton2->value = 99;
  lazy_singleton2->run(lazy_singleton2);

  // 懒汉模式，线程安全
  LazySingletonSafe *lazy_singleton_safe1 = get_lazy_singleton_safe_instance("lazySingletonSafe1");
  LazySingletonSafe *lazy_singleton_safe2 = get_lazy_singleton_safe_instance("lazySingletonSafe2");
  lazy_singleton_safe1->run(lazy_singleton_safe1);
  // 实例相同
  lazy_singleton_safe2->value = 88;
  lazy_singleton_safe2->run(lazy_singleton_safe2);

  // 懒汉模式volatile，线程安全
  LazySingletonVolatile *lazy_singleton_volatile1 = get_lazy_singleton_volatile_instance("lazySingletonVolatile1");
  LazySingletonVolatile *lazy_singleton_volatile2 = get_lazy_singleton_volatile_instance("lazySingletonVolatile2");
  lazy_singleton_volatile1->run(lazy_singleton_volatile1);
  // 实例相同
  lazy_singleton_volatile2->value = 77;
  lazy_singleton_volatile2->run(lazy_singleton_volatile2);

  // 饿汉模式，已经初始化，可直接使用
  EagerSingleton *eager_singleton1 = get_eager_singleton_instance("eagerSingleton1");
  EagerSingleton *eager_singleton2 = get_eager_singleton_instance("eagerSingleton2");
  eager_singleton1->run(eager_singleton1);
  // 实例相同
  eager_singleton2->run(eager_singleton2);
}

/**
jarry@jarrys-MacBook-Pro c % gcc test/test.c ./src下*.c
jarry@jarrys-MacBook-Pro c % ./a.out
test start:

 proxy_image_constructor() [构建ProxyImage]
 ProxyImage::display() [file_name=001.jpg]
 real_image_constructor() [构建RealImage]
 RealImage::load_from_disk() [file_name=001.jpg]
 RealImage::display() [file_name=001.jpg]
 ProxyImage::display() [file_name=001.jpg]
 RealImage::display() [file_name=001.jpg]%
 */