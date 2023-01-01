package test;

import src.*;

public class Test {

  public static void start() {
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