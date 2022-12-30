package test;

import src.*;

public class Test {

  public static void start() {

    // 用新抽象类来声明具体对象，并指定具体工具
    RefinedShape circle = new Circle(new DrawStyeA());
    // 调用对象的方法，里面执行了工具类的方法
    circle.draw(10, 20, 50);
    // 还可以调用新抽象类里的方法
    circle.drawDone();

    // /*********************** 分割线 ******************************************/

    // 用新抽象类来声明具体对象，并指定另外的工具
    RefinedShape circle2 = new Circle(new DrawStyleB());
    // 调用对象的方法，里面执行了工具类的方法
    circle2.draw(11, 22, 33);
    // 还可以调用新抽象类里的方法
    circle2.drawDone();
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
 * Circle::draw() [x=10 y=20 radius=50]
 * DrawStyleA:drawStyle()
 * RefinedShape::drawDone(), 执行的drawTool是: DrawStyeA
 * Circle::draw() [x=11 y=22 radius=33]
 * DrawStyleB:drawStyle()
 * RefinedShape::drawDone(), 执行的drawTool是: DrawStyle
 */