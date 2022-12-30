package test;

import src.*;

public class Test {

  public static void start() {

    // 声明一个聊天室
    GeneralRoom generalRoom = new GeneralRoom();
    // 给聊天室添加点不同的人
    AbstractUser user1 = new CommonUser("user1");
    generalRoom.register(user1);
    CommonUser user2 = new CommonUser("user2");
    generalRoom.register(user2);
    MemberUser user3 = new MemberUser("user3");
    generalRoom.register(user3);

    // user1 发送给全体
    user1.send("hello, I'm " + user1.getName() + ".");
    // user2 发送给 user3
    user2.sendTo(user3.getName(), "hello user3, how do you do.");
    // user3 发送给 自己
    user3.sendTo(user3.getName(), "hello everyone, how are you.");

  }

  public static void main(String[] args) {
    System.out.println("test start:");
    start();
  }

}

/**
 * 测试
 * D:\design-pattern\bridge-pattern\java> javac -encoding utf-8 test/Test.java
 * D:\design-pattern\bridge-pattern\java> java test/Test
 * test start:
 * CommonUser:send() [user: user1 send message:hello, I'm user1.]
 * GeneralRoom:send() [ user:user1 send messsage: hello, I'm user1.]
 * CommonUser:recieve() [user: user1 recieve message: hello, I'm user1. from
 * user:user1]
 * CommonUser:recieve() [user: user2 recieve message: hello, I'm user1. from
 * user:user1]
 * MemberUser:recieve() [user: user3 recieve message: hello, I'm user1. from
 * user:user1]
 * CommonUser:sendTo() [user: user2 send message:hello user3, how do you do. to:
 * user3]
 * GeneralRoom:send() [user:user2 send messsage: hello user3, how do you do. to:
 * user3 ]
 * MemberUser:recieve() [user: user3 recieve message: hello user3, how do you
 * do. from user:user2]
 * MemberUser:sendTo() [user: user3 send message:hello everyone, how are you.
 * to: user3]
 * GeneralRoom:send() [user:user3 send messsage: hello everyone, how are you.
 * to: user3 ]
 * MemberUser:recieve() [user: user3 recieve message: hello everyone, how are
 * you. from user:user3]
 */