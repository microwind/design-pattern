package src;

import src.vehicle.*;
import src.shop.*;

/*
  意图：提供一个创建一系列相互依赖的接口，而无需指定它们具体的类。
  主要作用：主要解决接口选择的问题。在一个对象家族系统里面里面，抽象定义多个产品对象。
  何时使用：产品很多，形成产品系列，而系统只需要处理其中某一类的产品。
  如何解决：在一个产品系列里面，定义多个产品对象。由抽象类来负责创建产品工厂。
 */
public abstract class AbstractFactory {
  public abstract Vehicle getVehicle(VehicleType type);
  public abstract Shop getShop(String name);
}
