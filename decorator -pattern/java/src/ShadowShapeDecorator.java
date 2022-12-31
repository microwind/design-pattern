package src;

// 具体装饰器2
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
