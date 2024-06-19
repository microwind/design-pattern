/**
 * 重写示例，子类覆盖父类同名方法，体现多态。
 * 子类向上转型为父类型，父类强制向下转型为子类型。
 */
class Shape {
  void draw() {
    System.out.println("Shape->draw");
  }

  void drawShape() {
    System.out.println("Shape->drawShape");
  }
}

class Circle extends Shape {
  @Override
  void draw() {
    System.out.println("Circle->draw");
  }

  void drawCircle() {
    System.out.println("Circle->drawCircle");
  }
}

class Square extends Shape {
  @Override
  void draw() {
    System.out.println("Square->draw");
  }

  void drawSquare() {
    System.out.println("Square->drawSquare");
  }
}

public class OverrideExample {
  public static void main(String[] args) {
    // 用父类引用声明子类对象，向上转型
    Shape shape1 = new Circle();
    Shape shape2 = new Square();

    // 子类有同名方法，动态绑定到子类，实质执行的是Circle.draw()，体现多态
    shape1.draw();

    // 报错，编译时按声明类型检查，Shape类中没有drawCircle方法
    // shape1.drawCircle();

    // 执行父类方法，输出 "Shape->drawShape"
    shape1.drawShape();

    // 子类有同名方法，动态绑定到子类，实质执行的是Square.draw()，体现多态
    shape2.draw();

    // 报错，编译时按声明类型检查，Shape类中没有drawSquare方法
    // shape2.drawSquare();

    // 强制向下转型，此时执行对象的类型为Square，输出 "Square->drawShape"
    ((Square) shape2).drawSquare();

    // 报错，不能平级之间强转，属于实例的类型才能转换
    System.out.println("shape1's Class: " + (shape1.getClass().getName()) + " | shape1 is instance of Square? "
        + (shape1 instanceof Square));
    // ((Square) shape1).drawShape();

    // 执行父类方法，输出 "Shape->drawShape"
    shape2.drawShape();

    // 向下转型以访问子类特有的方法
    if (shape1 instanceof Circle) {
      // 向下转型，用子类重新声明，成为子类型了
      Circle myCircle = (Circle) shape1;

      // 输出 "Circle->draw"
      myCircle.draw();

      // 输出 "Circle->drawCircle"
      myCircle.drawCircle();

      // 继承父类，输出 "Shape->drawShape"
      myCircle.drawShape();
    }

    if (shape2 instanceof Square) {
      // 向下转型，用子类重新声明，成为子类型了
      Square mySquare = (Square) shape2;

      // 输出 "Square->draw"
      mySquare.draw();

      // 输出 "Square->drawSquare"
      mySquare.drawSquare();

      // 报错。若强转为父类型，则无法调用drawSquare方法
      // ((Shape) mySquare).drawSquare();

      // 继承父类，输出 "Shape->drawShape"
      mySquare.drawShape();
    }
  }
}
