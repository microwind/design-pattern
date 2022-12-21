package src;
import src.vehicle.*;
import src.shop.*;
/*
  意图：定义基础接口，让其子类自己决定实例化哪一个工厂类，工厂模式使其创建过程延迟到子类进行。
  主要作用：解决接口选择的问题。统一实例化，用接口来实例化类更加抽象。
  何时使用：大量构造函数的地方，调用了大量的new来实例化类。
  如何解决：让其子类实现工厂接口，返回的也是一个抽象的产品。
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
