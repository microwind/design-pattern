/*
抽象是一种简化复杂系统的方法，在更高层次上进行建模。抽象包括两个方面，一是过程抽象，二是数据抽象。
抽象类：Shape是一个抽象类，它包含一个抽象方法calculateArea()。抽象类通过abstract关键字进行声明，不能被实例化。
抽象类（Abstract Class）和接口（Interface）是不同的机制，用于实现多态性和代码组织。两者都可以用于定义抽象方法，但又有区别。
抽象类用于表示一种"is-a"关系，而接口用于表示一种"can-do"关系。
JavaScript没有抽象类，声明对象也没有类型，使用了普通类和继承来模拟抽象类的概念。
抽象类的作用和意义在于提供了一种抽象的、模板化的设计方式，通过定义抽象方法和具体实现，规范了子类的行为，普通类可以替代抽象类，但它们并不完全等价。
*/

// 类：形状，可看作是抽象类
class Shape {
  // 计算形状的面积，子类实现
  calculateArea() {
    throw new Error('Method "calculateArea" must be implemented');
  }
}

// 子类：圆形
class Circle extends Shape {
  constructor(radius) {
    super();
    this.radius = radius; // 圆的半径
  }

  // 实现抽象方法：计算圆的面积
  calculateArea() {
    return Math.PI * this.radius ** 2;
  }
}

// 子类：矩形
class Rectangle extends Shape {
  constructor(width, height) {
    super();
    this.width = width; // 矩形的宽度
    this.height = height; // 矩形的高度
  }

  // 实现抽象方法：计算矩形的面积
  calculateArea() {
    return this.width * this.height;
  }
}

// 子类：三角形
class Triangle extends Shape {
  constructor(base, height) {
    super();
    this.base = base; // 三角形的底边长
    this.height = height; // 三角形的高
  }

  // 实现抽象方法：计算三角形的面积
  calculateArea() {
    return 0.5 * this.base * this.height;
  }
}

// 测试验证
// 创建圆形对象并计算面积
const circle = new Circle(5);
const circleArea = circle.calculateArea();
console.log("圆形面积:", circleArea); // 输出：圆形面积: 78.53981633974483

// 创建矩形对象并计算面积
const rectangle = new Rectangle(4, 6);
const rectangleArea = rectangle.calculateArea();
console.log("矩形面积:", rectangleArea); // 输出：矩形面积: 24

// 创建三角形对象并计算面积
const triangle = new Triangle(3, 4);
const triangleArea = triangle.calculateArea();
console.log("三角形面积:", triangleArea); // 输出：三角形面积: 6