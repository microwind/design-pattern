package src;

// 具体形状实现了基础形状接口
public class Square implements Shape {

   @Override
   public void draw() {
      System.out.println("Square::draw()");
   }
}