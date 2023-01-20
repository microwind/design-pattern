package src.vehicle;

// 具体产品类，实现抽象产品接口
public class Bus implements Vehicle {
 
  @Override
  public void run() {
     System.out.println("Bus::run().");
  }
}