package test;

import src.*;

public class Test {

  public static void start() {

    // 声明代理类来执行真实类的能力
    Image image = new ProxyImage("001.jpg");

    // 代理类执行真实类的能力
    image.display();

    // 再调用一次，不会重复实例化
    image.display();
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
 * ProxyImage::display() 001.jpg
 * RealImage::loadFromDisk() 001.jpg
 * RealImage::display() 001.jpg
 * ProxyImage::display() 001.jpg
 * RealImage::display() 001.jpg
 */