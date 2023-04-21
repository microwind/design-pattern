#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Subject Subject;
typedef struct Observer Observer;
typedef struct ConcreteSubject ConcreteSubject;
typedef struct ConcreteObserver ConcreteObserver;
typedef struct ConcreteObserver2 ConcreteObserver2;

// 观察者抽象父类，定义一些公共方法
typedef struct Observer
{
    char name[50];
    Subject *subject;
    void (*set_subject)(Observer *observer, Subject *subject);
    void (*update)(Observer *observer, char *content);
} Observer;

// 具体的观察者实现类，也可以看成订阅者，关联对应的主题类。
typedef struct ConcreteObserver
{
    char name[50];
    Subject *subject;
    void (*set_subject)(ConcreteObserver *observer, Subject *subject);
    void (*update)(ConcreteObserver *observer, char *content);
} ConcreteObserver;
ConcreteObserver *concrete_observer_constructor(char *name);

// 具体的观察者实现类2，也可以看成订阅者，关联对应的主题类。
typedef struct ConcreteObserver2
{
    char name[50];
    Subject *subject;
    void (*set_subject)(ConcreteObserver2 *observer, Subject *subject);
    void (*update)(ConcreteObserver2 *observer, char *content);
} ConcreteObserver2;
ConcreteObserver2 *concrete_observer2_constructor(char *name);

// 定义抽象主题类或者接口，供具体主题类继承
typedef struct Subject
{
    char name[50];
    Observer **observers;
    int observers_length;
    void (*registry)(Subject *subject, Observer *observer);
    void (*remove)(Subject *subject, Observer *observer);
    void (*notify)(Subject *subject, char *content);
} Subject;

// 观察者主题类，也是发布者，重写具体的通知方法。不同主题可以关联不同的观察者。
typedef struct ConcreteSubject
{
    char name[50];
    Observer **observers;
    int observers_length;
    void (*registry)(ConcreteSubject *subject, Observer *observer);
    void (*remove)(ConcreteSubject *subject, Observer *observer);
    void (*notify)(ConcreteSubject *subject, char *content);
} ConcreteSubject;
ConcreteSubject *concrete_subject_constructor(char *name);