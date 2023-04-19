#include "func.h"

// 实现基础类的普通用户1，聚合了中介者

void common_set_mediator(CommonUser *user, RoomMediator *mediator)
{
  user->mediator = mediator;
}

void common_send(CommonUser *sender, char *message)
{
  printf("\r\n CommonUser::send() [sender:%s message:%s]", sender->name, message);
  // 通过中介者来中转消息
  sender->mediator->send((AbstractUser *)sender, message);
}

void common_send_to(CommonUser *sender, AbstractUser *receiver, char *message)
{
  printf("\r\n CommonUser::send_to() [sender:%s message:%s receiver:%s]", sender->name, message, receiver->name);
  // 通过中介者来中转消息
  sender->mediator->send_to((AbstractUser *)sender, receiver, message);
}

void common_recieve(CommonUser *receiver, AbstractUser *sender, char *message)
{
  printf("\r\n CommonUser::recieve() [receiver:%s message:%s sender:%s]", receiver->name, message, sender->name);
}

// 普通用户2构造器
CommonUser *common_user_constructor(char *name)
{
  printf("\r\n common_user_constructor() [构建CommonUser]");
  AbstractUser *user = (AbstractUser *)malloc(sizeof(AbstractUser));
  strncpy(user->name, name, 50);
  CommonUser *common = (CommonUser *)user;
  common->send = &common_send;
  common->send_to = &common_send_to;
  common->recieve = &common_recieve;
  common->set_mediator = &common_set_mediator;
  return common;
}