#include "func.h"

// 实现基础类的普通用户2，聚合了中介者

void member_set_mediator(MemberUser *user, RoomMediator *mediator)
{
  user->mediator = mediator;
}

void member_send(MemberUser *sender, char *message)
{
  printf("\r\n MemberUser:send() [sender:%s message:%s]", sender->name, message);
  // 通过中介者来中转消息
  sender->mediator->send((AbstractUser *)sender, message);
}

void member_send_to(MemberUser *sender, AbstractUser *receiver, char *message)
{
  printf("\r\n MemberUser::send_to() [sender:%s message:%s receiver:%s]", sender->name, message, receiver->name);
  // 通过中介者来中转消息
  sender->mediator->send_to((AbstractUser *)sender, receiver, message);
}

void member_recieve(MemberUser *receiver, AbstractUser *sender, char *message)
{
  printf("\r\n MemberUser::recieve() [receiver:%s message:%s sender:%s]", receiver->name, message, sender->name);
}

// 普通用户2构造器
MemberUser *member_user_constructor(char *name)
{
  printf("\r\n member_user_constructor() [构建MemberUser]");
  AbstractUser *user = (AbstractUser *)malloc(sizeof(AbstractUser));
  MemberUser *member = (MemberUser *)user;
  strncpy(member->name, name, 50);
  member->send = &member_send;
  member->send_to = &member_send_to;
  member->recieve = &member_recieve;
  member->set_mediator = &member_set_mediator;
  return member;
}