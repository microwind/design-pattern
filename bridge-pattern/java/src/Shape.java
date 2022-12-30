package src;

// 定义抽象形状类，关联图形操作接口
public abstract class Shape {
   protected DrawTool drawTool;

   protected Shape(DrawTool drawTool) {
      this.drawTool = drawTool;
   }

   public abstract void draw(int x, int y, int radius);
}