package src;

// 定义新抽象类继承基础抽象类
public abstract class RefinedShape extends Shape {
   public RefinedShape(DrawTool drawTool) {
      super(drawTool);
   }

   // 新抽象类里的方法，可作为补充
   public void drawDone() {
      System.out.println("RefinedShape::drawDone(), 执行的drawTool是: " + drawTool.getClass().getSimpleName());
   }
}