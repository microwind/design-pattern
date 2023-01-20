package src.shop;

// 具体产品类，实现抽象产品接口
public class DirectSaleShop implements Shop {
  @Override
  public void greetings() {
     System.out.println("DirectSaleShop::greetings().");
  }

  public void welcome() {
     System.out.println("DirectSaleShop::welcome().");
  }
}