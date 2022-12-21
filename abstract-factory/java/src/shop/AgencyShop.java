package src.shop;

public class AgencyShop implements Shop {
  @Override
  public void greetings() {
    System.out.println("AgencyShop::greetings().");
  }
}