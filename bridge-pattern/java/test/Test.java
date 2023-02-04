package test;

import src.*;

public class Test {

  public static void start() {

    /**
     * 桥接模式是将基础抽象类作为桥接器，用来连接业务对象和具体动作，将两者充分解耦。
     * 具体对象以抽象对象为父类，实现父类方法。
     * 具体工具类实现统一的工具接口，为抽象桥接对象服务
     * 使用时，声明具体对象同时传入具体工具，使得具体对象可以使用具体工具的动作。
     */

    // 用抽象类来声明具体对象，并指定具体工具
    AbstractShape shape = new RefinedShape(new DrawStyeA());
    // 调用对象的方法，里面执行了工具类的方法
    shape.draw(10, 20, 50);
    RefinedShape shape1 = (RefinedShape) shape;
    // 类型强转为具体业务类，调用具体类的方法
    shape1.drawDone();

    // /*********************** 分割线 ******************************************/

    // 直接用具体类来声明对象，并指定另外的工具
    RefinedShape shape2 = new RefinedShape(new DrawStyleB());
    // 调用对象的方法，里面执行了工具类的方法
    shape2.draw(11, 22, 33);
    shape2.drawDone();
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
 * RefinedShape::draw() [x=10 y=20 radius=50]
 * DrawStyleA:drawStyle()
 * RefinedShape::drawDone(), 执行的drawTool是: DrawStyeA
 * RefinedShape::draw() [x=11 y=22 radius=33]
 * DrawStyleB:drawStyle()
 * RefinedShape::drawDone(), 执行的drawTool是: DrawStyleB
 */