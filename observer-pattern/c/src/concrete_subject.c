#include "func.h"

// 观察者主题类，也是发布者，重写具体的通知方法。不同主题可以关联不同的观察者。

void concrete_registry(ConcreteSubject *subject, Observer *observer)
{
  printf("\r\n ConcreteSubject::register() [observer = %s]", observer->name);
  subject->observers_length += 1;
  Observer **new_observers = (Observer **)calloc(subject->observers_length, sizeof(Observer));
  // 复制原有数组，并追加新内容到新数组
  for (int i = 0; i < subject->observers_length - 1; i++)
  {
    new_observers[i] = subject->observers[i];
  }
  new_observers[subject->observers_length - 1] = observer;
  free(subject->observers);
  // 指向新数组
  subject->observers = new_observers;
}

void concrete_remove(ConcreteSubject *subject, Observer *observer)
{
  printf("\r\n ConcreteSubject::remove() [observer = %s]", observer->name);
  Observer **new_observers = (Observer **)calloc(subject->observers_length - 1, sizeof(Observer));
  int new_length = 0;
  bool is_removed = false;
  for (int i = 0; i < subject->observers_length; i++)
  {
    // 过滤掉第一个出现的匹配项，达到删除目的
    if (is_removed == false && subject->observers[i] == observer)
    {
      is_removed = true;
      continue;
    }
    new_length++;
    new_observers[new_length - 1] = subject->observers[i];
  }
  free(subject->observers);
  // 指向新数组和新长度
  subject->observers = new_observers;
  subject->observers_length = new_length;
}

// 通知批量各个观察者
void concrete_notify(ConcreteSubject *subject, char *content)
{
  printf("\r\n ConcreteSubject::notify() [content = %s]", content);
  for (int i = 0; i < subject->observers_length; i++)
  {
    subject->observers[i]->update(subject->observers[i], content);
  }
}

ConcreteSubject *concrete_subject_constructor(char *name)
{
  printf("\r\n concrete_subject_constructor() [构建订阅主题]");
  Subject *subject = (Subject *)malloc(sizeof(Subject));
  ConcreteSubject *concrete_subject = (ConcreteSubject *)subject;
  strncpy(concrete_subject->name, name, 50);
  concrete_subject->registry = &concrete_registry;
  concrete_subject->remove = &concrete_remove;
  concrete_subject->notify = &concrete_notify;
  return concrete_subject;
}
