package test;

import src.*;

public class Test {

  public static void start() {
    /**
     * 责任链模式核心是打造一个调用处理链，每个处理链都实现抽象类的next方法，从而可以任意组织各种检查行为。
     * 通过改变链内的成员或者调动它们的顺序，允许动态地新增或者删除职责，从而实现按需组织。
     */

    // 可以任意组织职责链，先后顺序根据需要来
    AbstractHandler handler1 = AbstractHandler.link(
        new RequestHandler(),
        new UserHandler(),
        new AuthHandler());

    System.out.println("handler1.check(1001)开始");
    handler1.check(1001);
    System.out.println("handler1.check(1002)开始");
    handler1.check(1002);

    // 可以任意组织职责链，先后顺序根据需要来
    AbstractHandler handler2 = AbstractHandler.link(
        new AuthHandler(),
        new RequestHandler(),
        new UserHandler());

    System.out.println("handler2.check(1001)开始");
    handler2.check(1001);
    System.out.println("handler2.check(1002)开始");
    handler2.check(1002);

  }

  public static void main(String[] args) {
    System.out.println("test start:");
    start();
  }
}
/**
 * 测试
 * jarry@jarrys-MacBook-Pro java % javac test/Test.java
 * jarry@jarrys-MacBook-Pro java % java test/Test
 * test start:
 * handler1.check(1001)开始
 * src.RequestHandler::check() [uid = 1001]
 * src.UserHandler::check() [uid = 1001]
 * src.AuthHandler::check() [uid = 1001]
 * handler1.check(1002)开始
 * src.RequestHandler::check() [uid = 1002]
 * src.UserHandler::check() [uid = 1002]
 * handler2.check(1001)开始
 * src.AuthHandler::check() [uid = 1001]
 * src.RequestHandler::check() [uid = 1001]
 * src.UserHandler::check() [uid = 1001]
 * handler2.check(1002)开始
 * src.AuthHandler::check() [uid = 1002]
 */
