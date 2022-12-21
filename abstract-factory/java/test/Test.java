package test;

import src.*;
import src.shop.*;
import src.vehicle.*;

public class Test {

  public static void start() {

    // 声明一个汽车工厂
    AbstractFactory vehicleFactory = FactoryCreator.getFactory("vehicle");
    // 从汽车工厂获取Bus对象，并调用它的 run 方法
    Vehicle bus = vehicleFactory.getVehicle(VehicleType.BUS);
    bus.run();

    // 获取Car对象，类型强转，并调用它的 run 方法
    Vehicle car = vehicleFactory.getVehicle(VehicleType.CAR);
    Car car1 = (Car) car;
    car1.run();

    /*********************** 分割线 ******************************************/

    // 声明商店工厂
    AbstractFactory shopFactory = FactoryCreator.getFactory("shop");
    // 从商店工厂获取商店对象
    Shop shop = shopFactory.getShop("SupermarketShop");
    // 调用商店的方法
    shop.greetings();

    // 声明时强转
    AgencyShop agencyShop = (AgencyShop) shopFactory.getShop("AgencyShop");
    // 调用商店的方法
    agencyShop.greetings();

    /*********************** 分割线 ******************************************/

    // 再声明一个商店工厂
    AbstractFactory shopFactory2 = FactoryCreator.getFactory("shop");
    Shop directSaleShop = shopFactory2.getShop("DirectSaleShop");
    directSaleShop.greetings();

    // 类型转换测试
    DirectSaleShop directSaleShop2 = (DirectSaleShop) directSaleShop;
    directSaleShop2.greetings();

  }

  public static void main(String[] args) {
    System.out.println("test start:");
    start();
  }

}

/**
 * 测试
 * jarry@jarrys-MacBook-Pro java % java --version
 * java 14.0.1 2020-04-14
 * Java(TM) SE Runtime Environment (build 14.0.1+7)
 * Java HotSpot(TM) 64-Bit Server VM (build 14.0.1+7, mixed mode, sharing)
 * 
 * jarry@jarrys-MacBook-Pro java % pwd
 * /Users/jarry/github/design-pattern/abstract-factory/java
 * jarry@jarrys-MacBook-Pro java % javac test/Test.java
 * jarry@jarrys-MacBook-Pro java % java test/Test
 * 
test start:
Bus::run().
Car::run().
SupermarketShop::greetings().
AgencyShop::greetings().
DirectSaleShop::greetings().
DirectSaleShop::greetings().
 */