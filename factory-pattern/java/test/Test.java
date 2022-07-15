package test;

import src.*;

public class Test {

  public static void start() {
    VehicleFactory vehicleFactory = new VehicleFactory();

    // 获取Bus对象，并调用它的 run 方法
    Vehicle bus = vehicleFactory.getVehicle(VehicleType.BUS);
    bus.run();

    // 获取Car对象，并调用它的 run 方法
    Vehicle car = vehicleFactory.getVehicle(VehicleType.CAR);
    // 类型转为Car
    Car car1 = (Car)car;
    car1.run();

    // 获取Motorcycle对象，并调用它的 run 方法
    // 类型直接转为Motorcycle
    Motorcycle motorcycle = (Motorcycle)vehicleFactory.getVehicle(VehicleType.MOTORCYCLE);
    motorcycle.run();

    // 获取Motorcycle对象，并调用它的 run 方法
    Vehicle van = vehicleFactory.getVehicle(VehicleType.VAN);
    van.run();

  }
  public static void main(String[] args) {
    System.out.println("test start:");
    start();
  }

}

/**
 * 测试
jarry@jarrys-MacBook-Pro java % java --version
java 14.0.1 2020-04-14
Java(TM) SE Runtime Environment (build 14.0.1+7)
Java HotSpot(TM) 64-Bit Server VM (build 14.0.1+7, mixed mode, sharing)

jarry@jarrys-MacBook-Pro java % javac test/Test.java 
jarry@jarrys-MacBook-Pro java % java test/Test 
test start:
Bus::run().
Car::run().
Motorcycle::run().
Van::run().
 */