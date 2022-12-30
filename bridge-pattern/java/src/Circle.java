package src;

// 具体业务类，调用工具来辅助实现功能
public class Circle extends RefinedShape {
    public Circle(DrawTool drawTool) {
        super(drawTool);
    }

    @Override
    public void draw(int x, int y, int radius) {
        System.out.println(String.format("Circle::draw() [x=%s y=%s radius=%s]", x, y, radius));
        // 通过工具类实际绘制
        drawTool.drawStyle();
    }
}