package src;

// 具体桥接类，继承抽象桥接类，扩充了自己的方法
// 也可以将此类当做抽象类，再往下派生具体实现类
public class RefinedShape extends AbstractShape {
   public RefinedShape(DrawTool drawTool) {
      super(drawTool);
   }

  @Override
  public void draw(int x, int y, int radius) {
      System.out.println(String.format("RefinedShape::draw() [x=%s y=%s radius=%s]", x, y, radius));
      // 通过工具类实际绘制
      drawTool.drawStyle();
  }

   // 新增的方法，可作为工具类的补充
   public void drawDone() {
      System.out.println("RefinedShape::drawDone(), 执行的drawTool是: " + drawTool.getClass().getSimpleName());
   }
}