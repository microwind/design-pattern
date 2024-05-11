/*
抽象是一种简化复杂系统的方法，在更高层次上进行建模。抽象包括两个方面，一是过程抽象，二是数据抽象。
抽象类：Shape是一个抽象类，它包含一个抽象方法calculateArea()。抽象类通过abstract关键字进行声明，不能被实例化。
抽象类（Abstract Class）和接口（Interface）是不同的机制，用于实现多态性和代码组织。两者都可以用于定义抽象方法，但又有区别。
抽象类用于表示一种"is-a"关系，而接口用于表示一种"can-do"关系。
本示例：
- 抽象方法：calculateArea()是一个抽象方法，它没有具体的实现。子类必须实现这个方法，否则它们也必须声明为抽象类。
- 子类实现：Circle和Rectangle是Shape的具体子类，它们分别实现了calculateArea()方法。在这些子类中，我们提供了具体的面积计算逻辑。
- 多态性：通过抽象类和多态性，我们可以使用相同的接口来处理不同的子类对象。在测试中，创建了圆形和矩形对象，并分别计算了它们的面积，而不需要关心它们的具体类型。
*/

// 抽象类：形状
// 这里计算面积使用抽象类，如果是移动、缩放等行为，则可以采用接口
abstract class Shape {
  // 抽象方法：计算形状的面积。由子类具体实现
  public abstract double calculateArea();
}

// 子类：圆形
class Circle extends Shape {
  private double radius; // 圆的半径

  // 构造方法
  public Circle(double radius) {
    this.radius = radius;
  }

  // 实现抽象方法：计算圆的面积
  @Override
  public double calculateArea() {
    return Math.PI * radius * radius;
  }
}

// 子类：矩形
class Rectangle extends Shape {
  private double width; // 矩形的宽度
  private double height; // 矩形的高度

  // 构造方法
  public Rectangle(double width, double height) {
    this.width = width;
    this.height = height;
  }

  // 实现抽象方法：计算矩形的面积
  @Override
  public double calculateArea() {
    return width * height;
  }
}

// 子类：三角形
class Triangle extends Shape {
  private double base; // 三角形的底边长
  private double height; // 三角形的高

  // 构造方法
  public Triangle(double base, double height) {
    this.base = base;
    this.height = height;
  }

  // 实现抽象方法：计算三角形的面积
  @Override
  public double calculateArea() {
    return 0.5 * base * height;
  }
}

// 测试验证
public class AbstractionExample {
  public static void main(String[] args) {
    // 创建圆形对象并计算面积
    Circle circle = new Circle(5);
    double circleArea = circle.calculateArea();
    System.out.println("圆形面积: " + circleArea); // 输出：Circle Area: 78.53981633974483

    // 创建矩形对象并计算面积
    Rectangle rectangle = new Rectangle(4, 6);
    double rectangleArea = rectangle.calculateArea();
    System.out.println("矩形面积: " + rectangleArea); // 输出：Rectangle Area: 24.0

    // 创建三角形对象并计算面积
    Triangle triangle = new Triangle(3, 4);
    double triangleArea = triangle.calculateArea();
    System.out.println("三角形面积: " + triangleArea); // 输出：Triangle Area: 6.0
  }
}