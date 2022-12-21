package src;

/*
  工厂创建者，用来创建不同的工厂
*/
public class FactoryCreator {
  public static AbstractFactory getFactory(String name) {
    switch (name) {
      // 汽车工厂
      case "vehicle":
        return new VehicleFactory();
      // 商店工厂
      case "shop":
        return new ShopFactory();
      default:
        return null;
    }
  }
}
