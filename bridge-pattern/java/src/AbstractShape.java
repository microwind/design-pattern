package src;

// 定义抽象桥接类，关联图形操作接口
public abstract class AbstractShape {
   protected DrawTool drawTool;

   protected AbstractShape(DrawTool drawTool) {
      this.drawTool = drawTool;
   }

   public abstract void draw(int x, int y, int radius);
}