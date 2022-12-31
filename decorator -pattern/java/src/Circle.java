package src;

// 具体形状实现了基础形状接口
public class Circle implements Shape {

   @Override
   public void draw() {
      System.out.println("Circle::draw()");
   }
}