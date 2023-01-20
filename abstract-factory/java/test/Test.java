package test;

import src.*;
import src.shop.*;
import src.vehicle.*;

public class Test {

  public static void start() {

    /**
     * 抽象工厂就是把生产产品的工厂也根据统一的抽象工厂来创建，
     * 这样不同类型的工厂可以在统一的约束下，整体上看更新加清晰。
     * 当声明工厂时可以通过抽象类型或具体工厂来声明，然后依据工厂来生产不同的产品。
     */

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
    // Shop接口没有welcome方法，故调用失败
    // directSaleShop.welcome();

    // 类型转换测试，将Shop接口类强转为DirectSaleShop实现类
    DirectSaleShop directSaleShop2 = (DirectSaleShop) directSaleShop;
    directSaleShop2.greetings();
    // 通过类型转换就可以调用welcome了
    directSaleShop2.welcome();

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
DirectSaleShop::welcome().
 */