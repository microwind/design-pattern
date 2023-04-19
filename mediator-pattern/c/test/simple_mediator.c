#include <stdio.h>

/**
 * 中介者模式是一种行为型设计模式，它可以用来减少类之间的直接依赖关系，
 * 将对象之间的通信封装到一个中介者对象中，从而使得各个对象之间的关系更加松散。
 * 在中介者模式中，对象之间不再直接相互交互，而是通过中介者来中转消息。
 */

typedef struct Colleague Colleague;
typedef struct Mediator Mediator;

// 定义抽象交互对象类
struct Colleague
{
  int id;
  struct Mediator *mediator;
  void (*send)(struct Colleague *sender, char *message);
  void (*send_to)(struct Colleague *sender, Colleague *receiver, char *message);
  void (*receive)(struct Colleague *receiver, Colleague *sender, char *message);
};

// 定义中介者类
struct Mediator
{
  struct Colleague **colleagues;
  int colleagues_length;
  void (*send)(Colleague *sender, char *message);
  void (*send_to)(Colleague *sender, Colleague *receiver, char *message);
};

// 交互对象发送消息
void colleague_send(Colleague *sender, char *message)
{
  printf("\r\n colleague_send() [sender->id=%d message=%s]", sender->id, message);
  Mediator *mediator = sender->mediator;
  // 由中介者代为转发消息给全体接收者
  mediator->send(sender, message);
}

// 交互对象发送消息
void colleague_send_to(Colleague *sender, Colleague *receiver, char *message)
{
  printf("\r\n colleague_send_to() [sender->id=%d receiver->id=%d message=%s]", sender->id, receiver->id, message);
  Mediator *mediator = sender->mediator;
  // 由中介者代为转发消息给指定接收者
  mediator->send_to(sender, receiver, message);
}

// 对象接收消息
void colleague_receive(Colleague *receiver, Colleague *sender, char *message)
{
  printf("\r\n colleague_receive() [receiver->id=%d send->id=%d message=%s]", receiver->id, sender->id, message);
}

// 中介者发送消息
void mediator_send(Colleague *sender, char *message)
{
  printf("\r\n mediator_send() [sender->id=%d message=%s]", sender->id, message);
  Colleague *receiver;
  for (int i = 0; i < sender->mediator->colleagues_length; i++)
  {
    // 中介者通知全体接收者
    receiver = sender->mediator->colleagues[i];
    receiver->receive(receiver, sender, message);
  }
}

// 中介者发送消息
void mediator_send_to(Colleague *sender, Colleague *receiver, char *message)
{
  // 中介者通知指定接收者
  printf("\r\n mediator_send_to() [sender->id=%d receiver->id=%d message=%s]", sender->id, receiver->id, message);
  receiver->receive(receiver, sender, message);
}

// 初始化交互对象类
void colleague_constructor(Colleague *self, int id)
{
  self->id = id;
  self->send = colleague_send;
  self->send_to = colleague_send_to;
  self->receive = colleague_receive;
}

// 初始化中介者类
void mediator_constructor(Mediator *self, Colleague **colleagues, int colleagues_length)
{
  self->colleagues = colleagues;
  self->colleagues_length = colleagues_length;
  // 给每个对象绑定中介者
  for (int i = 0; i < self->colleagues_length; i++)
  {
    self->colleagues[i]->mediator = self;
  }
  self->send = &mediator_send;
  self->send_to = &mediator_send_to;
}

// test

int main()
{
  // 初始化具体交互对象a，分别绑定相关函数
  Colleague colleague_a;
  colleague_constructor(&colleague_a, 1);

  // 初始化具体交互对象b，分别绑定相关函数
  Colleague colleague_b;
  colleague_constructor(&colleague_b, 2);

  // 定义交互对象数组
  Colleague *colleagues[] = {&colleague_a, &colleague_b};
  int colleagues_length = sizeof(colleagues) / sizeof(colleagues[0]);

  printf("colleagues_length=%d", colleagues_length);

  // 初始化中介者类，绑定交互对象
  Mediator mediator;
  mediator_constructor(&mediator, colleagues, colleagues_length);

  // 交互类发送消息
  colleague_a.send(&colleague_a, "Hi, all! I'm a.");
  printf("\r\n ==== \r\n");
  colleague_a.send_to(&colleague_a, &colleague_b, "Hello, colleague_b. I am a!");
  printf("\r\n ==== \r\n");
  colleague_b.send_to(&colleague_b, &colleague_a, "Hi, colleague_a! I'm b.");
  return 0;
}

// test
/*
jarry@jarrys-MacBook-Pro c % gcc test/simple_mediator.c
jarry@jarrys-MacBook-Pro c % ./a.out
colleagues_length=2
colleagues_length=2
 colleague_send() [sender->id=1 message=Hi, all! I'm a.]
 mediator_send() [sender->id=1 message=Hi, all! I'm a.]
 colleague_receive() [receiver->id=1 send->id=1 message=Hi, all! I'm a.]
 colleague_receive() [receiver->id=2 send->id=1 message=Hi, all! I'm a.]
 ==== 

 colleague_send_to() [sender->id=1 receiver->id=2 message=Hello, colleague_b. I am a!]
 mediator_send_to() [sender->id=1 receiver->id=2 message=Hello, colleague_b. I am a!]
 colleague_receive() [receiver->id=2 send->id=1 message=Hello, colleague_b. I am a!]
 ==== 

 colleague_send_to() [sender->id=2 receiver->id=1 message=Hi, colleague_a! I'm b.]
 mediator_send_to() [sender->id=2 receiver->id=1 message=Hi, colleague_a! I'm b.]
 colleague_receive() [receiver->id=1 send->id=2 message=Hi, colleague_a! I'm b.]% 
 */