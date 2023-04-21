#include "func.h"

void concrete_observer2_set_subject(ConcreteObserver2 *observer, Subject *subject)
{
  observer->subject = subject;
}

// 观察者发出更新通知，不用单独告诉订阅者，由订阅者自行监听
void concrete_observer2_update(ConcreteObserver2 *observer, char *content)
{
  printf("\r\n ConcreteObserver2::update() [subject->name = %s content = %s]", observer->subject->name, content);
}

// 给观察者绑定主题，同时把观察者添加到主题列表
ConcreteObserver2 *concrete_observer2_constructor(char *name)
{
  printf("\r\n concrete_observer2_constructor() [构建ConcreteObserver2]");
  Observer *observer = (Observer *)malloc(sizeof(Observer));
  ConcreteObserver2 *concrete_observer2 = (ConcreteObserver2 *)observer;
  strncpy(observer->name, name, 50);
  concrete_observer2->set_subject = &concrete_observer2_set_subject;
  concrete_observer2->update = &concrete_observer2_update;

  return concrete_observer2;
}