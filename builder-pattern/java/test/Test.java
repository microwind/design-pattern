package test;

import src.*;

public class Test {

  public static void start() {

    Application.makeIPhone();

    Application.makeHuaweiPhone();

    // *********************** 分割线 ******************************************/

    // 声明指挥者
    Director director = new Director();
    // 创建手机
    PhoneBuilder phoneBuilder = new PhoneBuilder();
    director.buildMiPhone(phoneBuilder);
    Phone miPhone = phoneBuilder.getProduct();
    System.out.println("miPhone:" + miPhone.getName() + " | " + miPhone.getGpuType().toString());
    // 创建手册
    ManualBuilder manualBuilder = new ManualBuilder();
    director.buildMiPhone(manualBuilder);
    Manual manual = manualBuilder.getProduct();
    System.out.println("manual:" + manual.getName() + " | " + manual.getGpuType().toString());

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
 * jarry@jarrys-MacBook-Pro java % javac test/Test.java
 * jarry@jarrys-MacBook-Pro java % java test/Test
 * test start:
 * SingleObject::run()
 * SingletonLazy::run()
 * SingletonSafe::run()
 * SingletonInner::run()
 */