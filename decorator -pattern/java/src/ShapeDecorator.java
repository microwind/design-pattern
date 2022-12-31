package src;

// 抽象装饰类，是否实现Shape可选
public abstract class ShapeDecorator implements Shape {
   protected Shape decoratedShape;

   public ShapeDecorator(Shape decoratedShape) {
      this.decoratedShape = decoratedShape;
   }

   public void draw() {
      decoratedShape.draw();
   }
}