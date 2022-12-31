package test;

import src.*;

public class Test {

  public static void start() {
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
