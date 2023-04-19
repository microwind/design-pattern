#include "../src/func.h"

int main(void)
{
  printf("test start:\r\n");
  /**
   * 中介者模式用一个中介对象来封装一系列动作，让对象之间利用中介者来交流。
   * 这里聊天室就是一个中介者，用户和用户之间的消息传递，全部依靠聊天室来完成。
   * 先给聊天室注册用户，也给用户绑定上中介者，双方彼此持有关系。
   * 中介者的成员之间的消息传递通过中介者来代理传达。
   */

  // 声明一个聊天室
  RoomMediator *general_room = (RoomMediator *)general_room_constructor();

  // 给聊天室添加点不同的人
  CommonUser *user1 = common_user_constructor("user1");

  general_room->registry(general_room, (AbstractUser *)user1);

  CommonUser *user2 = common_user_constructor("user2");
  general_room->registry(general_room, (AbstractUser *)user2);

  MemberUser *user3 = member_user_constructor("user3");
  general_room->registry(general_room, (AbstractUser *)user3);

  // user1 发送给全体
  user1->send(user1, "hi, I'm user1.");
  // user2 发送给 user3
  user2->send_to(user2, (AbstractUser *)user3, "Hello, haha.");
}

/**
jarry@jarrys-MacBook-Pro c % gcc test/test.c ./src下*.c
jarry@jarrys-MacBook-Pro c % ./a.out
test start:

 general_room_constructor() [构建通用聊天室]
 common_user_constructor() [构建CommonUser]
 common_user_constructor() [构建CommonUser]
 member_user_constructor() [构建MemberUser]
 CommonUser::send() [sender:user1 message:hi, I'm user1.]
 GeneralRoom::send() [sender: user1 message: hi, I'm user1.]
 CommonUser::recieve() [receiver:user1 message:hi, I'm user1. sender:user1]
 CommonUser::recieve() [receiver:user2 message:hi, I'm user1. sender:user1]
 MemberUser::recieve() [receiver:user3 message:hi, I'm user1. sender:user1]
 CommonUser::send_to() [sender:user2 message:Hello, haha. receiver:user3]
 GeneralRoom::send_to() [sender: user2 message: Hello, haha. receiver: user3]
 MemberUser::recieve() [receiver:user3 message:Hello, haha. sender:user2]%
 */