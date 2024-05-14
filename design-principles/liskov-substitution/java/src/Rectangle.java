package src;

/**
 * Rectangle类，继承父类
 */
public class Rectangle extends Shape {
  private double width;
  private double height;

  public Rectangle(double width, double height) {
    this.width = width;
    this.height = height;
  }

  // 这里没有覆盖父类的draw()方法

  @Override
  public double area() {
    return width * height;
  }
}