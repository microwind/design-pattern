package test;

import src.*;

public class Test {

  public static void start() {
  /**
   * 外观模式就是在外层添加一个访问接口类，客户通过这统一访问接口来访问这些复杂子类。
   * 外观模式与适配器模式比较像，都是提供一个高层访问接口，隔绝外部客户与内部子类。
   * 所不同是外观模式后面的类无需实现相同接口，只是把各种调用整合简化，而适配器需要是同一系列类，为的是解决接口不兼容。
   * 这里声明外观类，外观类的方法里影藏了很多子类的调用。
   */
    AbstractFacade facade = new Facade();
    facade.encoding(123456);
    facade.encrypt(999999);
  }

  public static void main(String[] args) {
    System.out.println("test start:");
    start();
  }

}

/**
 * 测试
 * jarry@jarrys-MacBook-Pro java % javac test/Test.java
 * jarry@jarrys-MacBook-Pro java % java test/Test
 * test start:
 * src.Facade::encoding() [id=123456]
 * src.NetworkModule::request() 远程读取。
 * src.FileModule::readFile() 读取文件。
 * src.EncodeModule::encoding() 进行编码处理。
 * src.FileModule::saveFile() 保存文件。
 * src.Facade::encrypt() [id=999999]
 * src.FileModule::readFile() 读取文件。
 * src.EncodeModule::encoding() 进行编码处理。
 */