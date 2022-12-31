package src;

// 具体装饰器1
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
