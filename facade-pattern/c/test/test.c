#include "../src/func.h"

int main(void)
{
  printf("test start:\r\n");
  /**
   * 外观模式就是在外层添加一个访问接口类，客户通过这统一访问接口来访问这些复杂子类。
   * 外观模式与适配器模式比较像，都是提供一个高层访问接口，隔绝外部客户与内部子类。
   * 所不同是外观模式后面的类无需实现相同接口，只是把各种调用整合简化，而适配器需要是同一系列类，为的是解决接口不兼容。
   * 这里声明外观类，外观类的方法里影藏了很多子类的调用。
   */
  AbstractFacade *facade = (AbstractFacade *)facade_constructor("facade1");
  facade->encoding(facade, 123456);
  printf("\r\n");
  facade->encrypt(facade, 999999);

  return 0;
}

/**
jarry@jarrys-MacBook-Pro c % gcc test/test.c src/*.c
jarry@jarrys-MacBook-Pro c % ./a.out 
test start:

 Facade::encoding() [name=facade1, id=123456]
 NetworkModule::request() 远程读取。
 FileModule::read_file() 读取文件。
 EncodeModule::encoding() 进行编码处理。
 FileModule::save_file() 保存文件。

 Facade::encrypt() [name=facade1, id=999999]
 FileModule::read_file() 读取文件。
 EncodeModule::encoding() 进行编码处理。%  
 */