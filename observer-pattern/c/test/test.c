#include "../src/func.h"

int main(void)
{
  printf("test start:\r\n");
  /**
   * 观察者模式应用非常广泛，主要是观察者提前绑定到发布者
   * 当发布者发布消息时，批量广播通知，而无需逐一通知
   * 观察者监听到消息后自己决定采取哪一种行为
   */

  // 定义一个主题，也就是发布者
  ConcreteSubject *concrete_subject = concrete_subject_constructor("concrete_subject");
  ConcreteObserver *observer1 = concrete_observer_constructor("observer1");
  // 再声明观察者，绑定主题，并注册到主题上
  observer1->set_subject(observer1, (Subject *)concrete_subject);
  concrete_subject->registry(concrete_subject, (Observer *)observer1);

  /**************************************************************/

  // 也可以单独给主题注册一个新的观察者
  ConcreteObserver2 *observer2 = concrete_observer2_constructor("observer2");
  // 可以不给观察者绑定某个主题，而是仅从客户角度注册观察者，这样也可以接收通知
  // observer2->set_subject(observer2, (Subject *)concrete_subject);

  concrete_subject->registry(concrete_subject, (Observer *)observer2);

  // 可以移除观察者对象，打开注释试下
  // concrete_subject->remove(concrete_subject, (Observer *)observer2);

  // 主题开始发布新通知，各观察者自动更新
  concrete_subject->notify(concrete_subject, "hello, this is broadcast.");
}

/**
jarry@jarrys-MacBook-Pro c % gcc test/test.c ./src下*.c
jarry@jarrys-MacBook-Pro c % ./a.out
test start:

 concrete_subject_constructor() [构建订阅主题]
 concrete_observer_constructor() [构建ConcreteObserver]
 ConcreteSubject::register() [observer = observer1]
 concrete_observer2_constructor() [构建ConcreteObserver2]
 ConcreteSubject::register() [observer = observer2]
 ConcreteSubject::notify() [content = hello, this is broadcast.]
 ConcreteObserver::update() [subject->name = concrete_subject content = hello, this is broadcast.]
 ConcreteObserver2::update() [subject->name = (null) content = hello, this is broadcast.]%  
 */