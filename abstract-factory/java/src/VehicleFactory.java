package src;
import src.vehicle.*;
import src.shop.*;
/*
  Vehicle工厂类，继承自抽象工厂基类，生成Vehicle工厂
 */
public class VehicleFactory extends AbstractFactory {
  @Override
  public Vehicle getVehicle(VehicleType type) {
    switch (type) {
      case BUS:
        return new Bus();
      case CAR:
        return new Car();
      case MOTORCYCLE:
        return new Motorcycle();
      case VAN:
        return new Van();
      default:
        return null;
    }

  }

  @Override
  public Shop getShop(String name) {
    return null;
  }
}
