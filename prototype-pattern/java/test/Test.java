package test;

import src.*;

public class Test {

  public static void start() {

    Application application = new Application();
    application.addToShapes();
    Shape shapeClone = application.getShapeClone(1);
    // 更改clone
    shapeClone.setColor("gray");
    System.out.println("shapeClone : " + shapeClone.toString());
    // 直接更改
    application.getShape(3).setColor("yellow");
    application.printShapes();

    // /*********************** 分割线 ******************************************/
    application.shapes.add(new Square());
    for (Shape shape : application.shapes) {
      shape.draw();
      System.out.println(shape.toString());
    }

  }

  public static void main(String[] args) {
    System.out.println("test start:");
    start();
  }

}

/**
 * 测试
 * jarry@jarrys-MacBook-Pro java % java --version
 * java 14.0.1 2020-04-14
 * Java(TM) SE Runtime Environment (build 14.0.1+7)
 * Java HotSpot(TM) 64-Bit Server VM (build 14.0.1+7, mixed mode, sharing)
 * 
 * jarry@jarrys-MacBook-Pro java % javac test/Test.java
 * jarry@jarrys-MacBook-Pro java % java test/Test
 * test start:
 * shapeClone : {width = 10, height = 20, type = Circle, color = gray }
 * shape 0 : {width = 10, height = 20, type = Circle, color = red }
 * shape 1 : {width = 10, height = 20, type = Circle, color = pink }
 * shape 2 : {width = 99, height = 69, type = Rectangle, color = green }
 * shape 3 : {width = 99, height = 69, type = Rectangle, color = yellow }
 * Circle::draw() method.
 * {width = 10, height = 20, type = Circle, color = red }
 * Circle::draw() method.
 * {width = 10, height = 20, type = Circle, color = pink }
 * Rectangle::draw() method.
 * {width = 99, height = 69, type = Rectangle, color = green }
 * Rectangle::draw() method.
 * {width = 99, height = 69, type = Rectangle, color = yellow }
 * Square::draw() method.
 * {width = 0, height = 0, type = Square, color = }
 */