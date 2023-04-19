#include "func.h"

// 中介者的具体实现类，聚合了全体用户，提供中转消息服务

void general_room_registry(GeneralRoom *room, AbstractUser *user)
{
  // 用户注册登记，追加到中介者的用户列表
  user->set_mediator(user, (RoomMediator *)room);
  room->users_length += 1;
  AbstractUser **new_users = (AbstractUser **)calloc(room->users_length, sizeof(AbstractUser));
  for (int i = 0; i < room->users_length - 1; i++)
  {
    new_users[i] = room->users[i];
  }
  new_users[room->users_length - 1] = user;
  free(room->users);
  room->users = new_users;
}

// 作为中介者通知给某个用户
void general_room_send_to(AbstractUser *sender, AbstractUser *receiver, char *message)
{
  printf("\r\n GeneralRoom::send_to() [sender: %s message: %s receiver: %s]", sender->name, message, receiver->name);
  // 定向发送给某个用户
  receiver->recieve(receiver, sender, message);
}

// 作为中介者通知给全体用户
void general_room_send(AbstractUser *sender, char *message)
{
  printf("\r\n GeneralRoom::send() [sender: %s message: %s] ", sender->name, message);
  for (int i = 0; i < sender->mediator->users_length; i++)
  {
    AbstractUser *receiver = (AbstractUser *)sender->mediator->users[i];
    receiver->recieve(receiver, sender, message);
  }
}

// 中介者的具体实现类构造器
GeneralRoom *general_room_constructor()
{
  printf("\r\n general_room_constructor() [构建通用聊天室]");
  RoomMediator *mediator = (RoomMediator *)malloc(sizeof(RoomMediator));
  GeneralRoom *room = (GeneralRoom *)mediator;
  room->users_length = 0;
  room->registry = &general_room_registry;
  room->send = &general_room_send;
  room->send_to = &general_room_send_to;
  return room;
}