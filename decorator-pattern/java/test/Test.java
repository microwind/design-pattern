package test;

import src.*;

public class Test {

  public static void start() {
    /**
     * 装饰器模式是将一个对象放到一个装饰器对象中，执行装饰器类里的方法时，对象的行为能力得到增强。
     * 先声明具体对象，然后放到装饰器，得到一个带有装饰器的新对象，该对象具备了新的能力。
     */

    // 声明形状
    Shape circle = new Circle();
    Shape square = new Square();

    // 增加红色装饰
    ShapeDecorator redCircle = new RedShapeDecorator(circle);
    ShapeDecorator redSquare = new RedShapeDecorator(square);
    circle.draw();
    redCircle.draw();
    redSquare.draw();

    // 增加影子装饰
    ShadowShapeDecorator shadowCircle = new ShadowShapeDecorator(circle);
    ShadowShapeDecorator shadowSquare = new ShadowShapeDecorator(square);
    shadowCircle.draw();
    shadowSquare.draw();
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
 * Circle::draw()
 * Circle::draw()
 * RedShapeDecorator::setRedColor() src.Circle
 * Square::draw()
 * RedShapeDecorator::setRedColor() src.Square
 * ShadowShapeDecorator::setShadow() src.Circle
 * ShadowShapeDecorator::setShadow() src.Square
 */
