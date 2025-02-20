/*
抽象是一种简化复杂系统的方法，在更高层次上进行建模。抽象包括两个方面，一是过程抽象，二是数据抽象。
抽象类：Shape是一个抽象类，它包含一个抽象方法calculateArea()。抽象类通过abstract关键字进行声明，不能被实例化。
抽象类（Abstract Class）和接口（Interface）是不同的机制，用于实现多态性和代码组织。两者都可以用于定义抽象方法，但又有区别。
抽象类用于表示一种"is-a"关系，而接口用于表示一种"can-do"关系。
TS有抽象类关键词，是一种语法糖，本质与JS一致也是原型对象。
*/

// 抽象类：形状
abstract class Shape {
  // 抽象方法：计算形状的面积。由子类具体实现
  abstract calculateArea(): number;
}

// 子类：圆形
class Circle extends Shape {
  private radius: number; // 圆的半径

  // 构造方法
  constructor(radius: number) {
    super();
    this.radius = radius;
  }

  // 实现抽象方法：计算圆的面积
  calculateArea(): number {
    return Math.PI * this.radius ** 2;
  }
}

// 子类：矩形
class Rectangle extends Shape {
  private width: number; // 矩形的宽度
  private height: number; // 矩形的高度

  // 构造方法
  constructor(width: number, height: number) {
    super();
    this.width = width;
    this.height = height;
  }

  // 实现抽象方法：计算矩形的面积
  calculateArea(): number {
    return this.width * this.height;
  }
}

// 子类：三角形
class Triangle extends Shape {
  private base: number; // 三角形的底边长
  private height: number; // 三角形的高

  // 构造方法
  constructor(base: number, height: number) {
    super();
    this.base = base;
    this.height = height;
  }

  // 实现抽象方法：计算三角形的面积
  calculateArea(): number {
    return 0.5 * this.base * this.height;
  }
}

// 测试验证
// 创建圆形对象并计算面积
const circle = new Circle(5);
const circleArea = circle.calculateArea();
console.log("圆形面积:", circleArea); // 输出：圆形面积: 78.53981633974483

// 创建矩形对象并计算面积，使用抽象类型
const rectangle: Shape = new Rectangle(4, 6);
const rectangleArea = rectangle.calculateArea();
console.log("矩形面积:", rectangleArea); // 输出：矩形面积: 24

// 创建三角形对象并计算面积
const triangle = new Triangle(3, 4);
const triangleArea = triangle.calculateArea();
console.log("三角形面积:", triangleArea); // 输出：三角形面积: 6


/*
jarry@jarrys-MacBook-Pro abstraction % ts-node AbstractionExample.ts
圆形面积: 78.53981633974483
矩形面积: 24
三角形面积: 6
*/