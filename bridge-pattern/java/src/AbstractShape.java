package src;

// 定义抽象桥接类，关联具体的DrawTool操作接口
// 供具体的Shape继承，以及聚合DrawTool的实现
public abstract class AbstractShape {
   protected DrawTool drawTool;

   protected AbstractShape(DrawTool drawTool) {
      this.drawTool = drawTool;
   }

   public abstract void draw(int x, int y, int radius);
}