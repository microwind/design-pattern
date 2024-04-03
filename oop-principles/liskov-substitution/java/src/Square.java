package src;

/**
 * Square对象类，继承父类Shape
 */
public class Square extends Shape {
    private double side;

    public Square(double side) {
        this.side = side;
    }

    // 不重写父类的draw方法
    // 另外起名，或通过重载得到新方法
    // public void draw(int type) {
    public void drawSquare() {
        if (checkArea()) {
            System.out.println("Haha Drawing Square. area:" + this.area());
        } else {
            System.out.println("Don't draw square");
        }
    }

    public boolean checkArea() {
        if (this.area() > 100) {
            return false;
        }
        return true;
    }

    @Override
    public double area() {
        return side * side;
    }
}