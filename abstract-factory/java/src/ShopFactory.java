package src;
import src.vehicle.*;
import src.shop.*;
/*
 商店创建类，继承自抽象工厂
*/
public class ShopFactory extends AbstractFactory {
  @Override
  public Shop getShop(String name) {
    if (name.equals("AgencyShop")) {
      return new AgencyShop();
    } else if (name.equals("DirectSaleShop")) {
      return new DirectSaleShop();
    } else if (name.equals("SupermarketShop")) {
      return new SupermarketShop();
    } else {
      return null;
    }
  }

  @Override
  public AbstractVehicle getVehicle(VehicleType type) {
    return null;
  }
}
