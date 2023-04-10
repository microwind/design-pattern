#include "../src/func.h"

int main(void)
{
  printf("test start:\r\n");
  /**
   * 享元模式就是将已经声明过的实例或数据保存在内存里，需要使用时则取出来，无需再次实例化和声明。
   * 通过共享多个对象所共有的相同状态，以达到节省开销的目的。
   * 享元模式分为内部状态和外部状态，内部状态基于享元对象共享，外部状态则外部传入或使用非享元类。
   */

  FlyweightFactory *flyweight_factory = flyweight_factory_constructor("flyweight_factory");
  // 假设有钢琴和吉他，钢琴使用者很多需要共享实例，而吉他每次创建新实例
  // // 2个一样名称的为共享对象，只创建1个实例，后面的返回缓存实例
  Flyweight *factory1 = flyweight_factory->get_factory("piano1");
  Flyweight *factory2 = flyweight_factory->get_factory("piano1");
  // 转换类型测试
  ConcreteFlyweight *factory3 = (ConcreteFlyweight *)flyweight_factory->get_factory("piano2");
  Flyweight *factory4 = flyweight_factory->get_factory("piano2");

  factory1->operate(factory1, "factory1");
  factory2->operate(factory2, "factory2");
  factory3->operate(factory3, "factory3");
  factory4->operate(factory4, "factory4");

  // 打印全部共享对象
  Flyweight **flyweight_pool = flyweight_factory->get_pool();
  int pool_size = flyweight_factory->get_pool_size();
  for (int i = 0; i < pool_size; i++)
  {
    printf("\r\n 享元对象:%d %s", i, flyweight_pool[i]->name);
  }

  // 无需共享的对象，name虽然一样，是不同的实例
  Flyweight *factory5 = (Flyweight *)unshared_concrete_flyweight_constructor("guitar1");
  UnsharedConcreteFlyweight *factory6 = unshared_concrete_flyweight_constructor("guitar1");
  factory5->operate(factory5, "factory5");
  factory6->operate(factory6, "factory6");

  free(flyweight_factory);

  return 0;
}

/**
jarry@jarrys-MacBook-Pro c % gcc test/test.c src/*.c
jarry@jarrys-MacBook-Pro c % ./a.out
test start:

 ConcreteFlyweight::concrete_flyweight_constructor() 创建具体享元对象[name=piano1]
 FlyweightFactory::get_factory() 成功创建具体享元[name=piano1]
 FlyweightFactory::get_factory() 成功获取具体享元[name=piano1]
 ConcreteFlyweight::concrete_flyweight_constructor() 创建具体享元对象[name=piano2]
 FlyweightFactory::get_factory() 成功创建具体享元[name=piano2]
 FlyweightFactory::get_factory() 成功获取具体享元[name=piano2]
 ConcreteFlyweight::operate() [name=piano1 kind=piano state=factory1]
 ConcreteFlyweight::operate() [name=piano1 kind=piano state=factory2]
 ConcreteFlyweight::operate() [name=piano2 kind=piano state=factory3]
 ConcreteFlyweight::operate() [name=piano2 kind=piano state=factory4]
 享元对象:0 piano1
 享元对象:1 piano2
 UnsharedConcreteFlyweight::unshared_concrete_flyweight_constructor() 创建非共享对象[name=guitar1]
 UnsharedConcreteFlyweight::unshared_concrete_flyweight_constructor() 创建非共享对象[name=guitar1]
 UnsharedConcreteFlyweight::operate() [name=guitar1 kind=guitar state=factory5]
 UnsharedConcreteFlyweight::operate() [name=guitar1 kind=guitar state=factory6]%
 */