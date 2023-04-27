# 【装饰器设计模式详解】C/Java/JS/Go/Python/TS不同语言实现

# 简介
装饰器模式（Decorator Pattern）是一种结构型设计模式。将对象放入到一个特殊封装的对象中，为这个对象绑定新的行为，具备新的能力，同时又不改变其原有结构。

如果你希望在无需修改代码的情况下即可使用对象，且希望在运行时为对象新增额外的行为，可以使用装饰模式。或者你用继承来扩展对象行为的方案难以实现或者根本不可行，你可以使用该模式。

# 作用
1. 动态地给一个对象添加一些额外的职责，相比生成子类更为灵活。
2. 在不想增加很多子类的情况下扩展类的能力，实现强大扩展能力。

# 实现步骤
1. 创建一个基础工具接口或抽象类，设定基本的方法。
2. 增加具体工具类实现基础接口，保持工具类的规范性。
3. 创建一个装饰器抽象类，用于装饰具体工具，聚合基础工具，同时也可以实现基础工具的接口。
4. 增加多个装饰器类，继承抽象类，根据需要设定装饰能力。

# UML
<img src="../docs/uml/decorator-pattern.png">

# Java代码

## 基础形状接口
```java
// Shape.java 基础形状接口
public interface Shape {
   void draw();
}
```

## 具体形状实现
```java
// Circle.java 具体形状实现了基础形状接口
public class Circle implements Shape {

   @Override
   public void draw() {
      System.out.println("Circle::draw()");
   }
}
```

```java
// Square.java 具体形状实现了基础形状接口
public class Square implements Shape {

   @Override
   public void draw() {
      System.out.println("Square::draw()");
   }
}
```

## 抽象装饰器
```java
// ShapeDecorator.java 抽象装饰类，是否实现Shape可选
public abstract class ShapeDecorator implements Shape {
// public abstract class ShapeDecorator {
   protected Shape decoratedShape;

   public ShapeDecorator(Shape decoratedShape) {
      this.decoratedShape = decoratedShape;
   }

   public void draw() {
      decoratedShape.draw();
   }
}
```

## 具体装饰器
```java
// RedShapeDecorator.java 具体装饰器1
public class RedShapeDecorator extends ShapeDecorator {

  public RedShapeDecorator(Shape decoratedShape) {
    super(decoratedShape);
  }

  @Override
  public void draw() {
    decoratedShape.draw();
    setRedColor(decoratedShape);
  }

  private void setRedColor(Shape decoratedShape) {
    System.out.println(
      "RedShapeDecorator::setRedColor() " + decoratedShape.getClass().getName()
    );
  }
}
```

```java
// ShadowShapeDecorator.java 具体装饰器2
public class ShadowShapeDecorator extends ShapeDecorator {

  public ShadowShapeDecorator(Shape decoratedShape) {
    super(decoratedShape);
  }

  @Override
  public void draw() {
    // decoratedShape.draw();
    setShadow(decoratedShape);
  }

  private void setShadow(Shape decoratedShape) {
    System.out.println(
      "ShadowShapeDecorator::setShadow() " + decoratedShape.getClass().getName()
    );
  }
}
```

## 测试调用
```java
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
```

# Go代码

## 基础形状接口
```go
// Shape.go 基础形状接口
type Shape interface {
  Draw()
  GetName() string
}

```

## 具体形状实现
```go
// Circle.go 具体形状实现了基础形状接口
type Circle struct {
}

func (c *Circle) Draw() {
  fmt.Println("Circle::Draw()")
}

func (c *Circle) GetName() string {
  return "Circle"
}

```

```go
// Square.go 具体形状实现了基础形状接口
type Square struct {
}

func (c *Square) Draw() {
  fmt.Println("Square::Draw()")
}

func (c *Square) GetName() string {
  return "Square"
}
```

## 抽象装饰器
```go
// ShapeDecorator.go 抽象装饰类，是否实现Shape可选
type ShapeDecorator interface {
  Draw()
}
```

## 具体装饰器
```go
// RedShapeDecorator.go 具体装饰器1
type RedShapeDecorator struct {
  DecoratedShape Shape
}

func (r *RedShapeDecorator) Draw() {
  r.DecoratedShape.Draw()
  r.SetRedColor(r.DecoratedShape)
}

func (r *RedShapeDecorator) SetRedColor(decoratedShape Shape) {
  fmt.Println("RedShapeDecorator::setRedColor() " + decoratedShape.GetName())
}
```

```go
// ShadowShapeDecorator.go 具体装饰器2
type ShadowShapeDecorator struct {
  DecoratedShape Shape
}

func (s *ShadowShapeDecorator) Draw() {
  // 装饰器根据需要是否调用形状的Draw方法
  // s.DecoratedShape.Draw()
  s.SetShadow(s.DecoratedShape)
}

func (s *ShadowShapeDecorator) SetShadow(decoratedShape Shape) {
  fmt.Println("ShadowShapeDecorator::SetShadow() " + decoratedShape.GetName())
}
```

## 测试调用
```go
  /**
   * 装饰器模式是将一个对象放到一个装饰器对象中，执行装饰器类里的方法时，对象的行为能力得到增强。
   * 先声明具体对象，然后放到装饰器，得到一个带有装饰器的新对象，该对象具备了新的能力。
   */

  // 声明形状
  var circle = new(src.Circle)
  var square = new(src.Square)

  // 增加红色装饰
  var redCircle = &src.RedShapeDecorator{
    DecoratedShape: circle,
  }
  var redSquare = &src.RedShapeDecorator{
    DecoratedShape: square,
  }
  circle.Draw()
  redCircle.Draw()
  redSquare.Draw()

  // 增加影子装饰
  var shadowCircle = &src.ShadowShapeDecorator{
    DecoratedShape: circle,
  }
  var shadowSquare = &src.ShadowShapeDecorator{
    DecoratedShape: square,
  }
  shadowCircle.Draw()
  shadowSquare.Draw()
```
## 更多语言版本
不同语言设计模式源码：[https://github.com/microwind/design-pattern](https://github.com/microwind/design-pattern)