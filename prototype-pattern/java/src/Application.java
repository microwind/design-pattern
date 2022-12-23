package src;

import java.util.*;

public class Application {

  public List<Shape> shapes = new ArrayList<Shape>();

  public Application() {
  }

  public void addToShapes() {
    Circle circle = new Circle();
    circle.setWidth(10);
    circle.setHeight(20);
    circle.setColor("red");
    shapes.add(circle);

    // 添加clone
    Circle anotherCircle = (Circle) circle.clone();
    anotherCircle.setColor("pink");
    shapes.add(anotherCircle);
    // 变量 `anotherCircle（另一个圆）`与 `circle（圆）`对象的内容完全一样。

    Rectangle rectangle = new Rectangle();
    rectangle.setWidth(99);
    rectangle.setHeight(69);
    rectangle.setColor("green");
    shapes.add(rectangle);
    // 添加clone
    shapes.add((Shape) rectangle.clone());
  }

  // 直接取出
  public Shape getShape(Integer index) {
    return this.shapes.get(index);
  }

  // 取出时候clone
  public Shape getShapeClone(Integer index) {
    Shape shape = this.shapes.get(index);
    return (Shape) shape.clone();
  }

  public void printShapes() {
    for (int i = 0; i < this.shapes.size(); i++) {
      Shape shape = this.shapes.get(i);
      System.out.println("shape " + i + " : " + shape.toString());
    }
  }

}
