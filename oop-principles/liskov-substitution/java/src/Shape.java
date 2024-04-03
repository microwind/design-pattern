package src;

/**
 * 抽象图形父类，抽象方法供重写，非抽象方法尽量不去覆盖
 */
public abstract class Shape {
    public void draw() {
        System.out.println("Drawing Shape. area:" + this.area());
    }

    public abstract double area();
}