package src;

/**
 * 这个例子违反了里氏代换原则，为了方面理解，把全部类放在了一起。
 * 1. 子类覆盖了父类的方法，改变了父类方法的意图。
 * 2. 因为子类改变了父类行为，因此不能子类不能替换其父类。
 */
public class LiskovSubstitution_counter {
    public LiskovSubstitution_counter() {
        return;
    }

    // 图形父类
    public abstract class Shape {
        public void draw() {
            System.out.println("Drawing Shape. area:" + this.area());
        }

        public abstract double area();
    }

    // 正方形子类，继承自图形类
    public class Square extends Shape {
        private double side;

        public Square(double side) {
            this.side = side;
        }

        // 重写父类的draw方法，同时改变了父类的行为
        @Override
        public void draw() {
            if (checkArea()) {
                System.out.println("Drawing Square. area:" + this.area());
            } else {
                // 这里存在子类其他的行为，与父类预期不一致
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

    // 矩形类，继承自图形类
    public class Rectangle extends Shape {
        private double width;
        private double height;

        public Rectangle(double width, double height) {
            this.width = width;
            this.height = height;
        }

        // 这里没有覆盖父类的draw()方法

        @Override
        public double area() {
            return width * height;
        }
    }
}
