package src.shop;

// 具体产品类，实现抽象产品接口
public class SupermarketShop implements Shop {
  @Override
  public void greetings() {
     System.out.println("SupermarketShop::greetings().");
  }
}