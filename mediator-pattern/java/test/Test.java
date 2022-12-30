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
    user1.send("hi, I'm " + user1.getName() + ".");
    // user2 发送给 user3
    user2.sendTo(user3.getName(), "haha.");

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
 * CommonUser:send() [user: user1 message:hi, I'm user1.]
 * >>GeneralRoom:send() [from: user1 message: hi, I'm user1.]
 * CommonUser:recieve() [user: user1 message: hi, I'm user1. from:user1]
 * CommonUser:recieve() [user: user2 message: hi, I'm user1. from:user1]
 * MemberUser:recieve() [user: user3 message: hi, I'm user1. from user:user1]
 * CommonUser:sendTo() [user: user2 message:haha. to: user3]
 * >>GeneralRoom:sendTo() [from: user2 message: haha. to: user3 ]
 * MemberUser:recieve() [user: user3 message: haha. from user:user2]
 */