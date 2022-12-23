package src;

// 具体原型类，克隆方法会创建一个新对象并将其传递给构造函数。
public class Square extends Shape {
  public Square() {
    super();
    type = "Square";
  }

  @Override
  public void draw() {
    System.out.println("Square::draw() method.");
  }
}
