# 【外观设计模式详解】C/Java/JS/Go/Python/TS不同语言实现

# 简介
外观模式（Facade Pattern），也叫门面模式，是一种结构型设计模式。它向现有的系统添加一个高层接口，隐藏子系统的复杂性，这个接口使得子系统更加容易使用。

如果你需要一个指向复杂子系统的直接接口，且该接口的功能有限，则可以使用外观模式。或者需要将子系统组织为多层结构，可以使用外观。

# 作用
1. 让业务代码通过统一接口与内部子系统隔离。
2. 降低访问内部子系统时的复杂度，简化客户端之间的接口。

# 实现步骤
1. 创建统一外观接口和实现类，用于衔接调用方与子系统。
2. 创建不同子模块/子模块，这些子模块可以共同实现某通用接口，也可以各自独立。
3. 通过统一外观接口来访问这些复杂子类。

# UML
<img src="../docs/uml/facade-pattern.png">


# Java代码

## 外观基础接口
```java
// AbstractFacade.java 外观模式的接口或抽象类，可选
public interface AbstractFacade {
   public void encoding(int id);

   public void encrypt(int id);
}
```

## 外观模式实现类
```java
// Facade.java 外观模式实现类，是外部调用与内部子系统的衔接层
public class Facade implements AbstractFacade {

   private FileModule fileModule;
   private NetworkModule networkModule;
   private EncodeModule encodeModule;

   public Facade() {
      fileModule = new FileModule();
      networkModule = new NetworkModule();
      encodeModule = new EncodeModule();
   }

   public void encoding(int id) {
      System.out.println(this.getClass().getName() + "::encoding() [id=" + id + "]");
      networkModule.request();
      fileModule.readFile();
      encodeModule.encoding();
      fileModule.saveFile();
   }

   public void encrypt(int id) {
      System.out.println(this.getClass().getName() + "::encrypt() [id=" + id + "]");
      fileModule.readFile();
      encodeModule.encoding();
   }

   public FileModule getFileModule() {
      return this.fileModule;
   }

   public NetworkModule getNetworkModule() {
      return this.networkModule;
   }

   public EncodeModule getEncodeModule() {
      return this.encodeModule;
   }
}
```

## 几个具体模块类
```java
// FileModule.java 文件模块
public class FileModule {

   public void readFile() {
      System.out.println(this.getClass().getName() + "::readFile() 读取文件。");
   }

   public void saveFile() {
      System.out.println(this.getClass().getName() + "::saveFile() 保存文件。");
   }
}
```

```java
// EncodeModule.java 编码模块
public class EncodeModule {
   public void encoding() {
      System.out.println(this.getClass().getName() + "::encoding() 进行编码处理。");
   }
}
```

```java
// NetworkModule.java 网络模块
public class NetworkModule {

   public void request() {
      System.out.println(this.getClass().getName() + "::request() 远程读取。");
   }
}
```

## 测试调用
```java
  /**
   * 外观模式就是在外层添加一个访问接口类，客户通过这统一访问接口来访问这些复杂子类。
   * 外观模式与适配器模式比较像，都是提供一个高层访问接口，隔绝外部客户与内部子类。
   * 所不同是外观模式后面的类无需实现相同接口，只是把各种调用整合简化，而适配器需要是同一系列类，为的是解决接口不兼容。
   * 这里声明外观类，外观类的方法里影藏了很多子类的调用。
   */
    AbstractFacade facade = new Facade();
    facade.encoding(123456);
    facade.encrypt(999999);
```

# Python代码

## 外观基础接口
```python
# AbstractFacade.py 外观模式的接口或抽象类，可选
# 外观模式的接口或抽象类，可选
from abc import abstractmethod, ABCMeta


class AbstractFacade(metaclass=ABCMeta):

    @abstractmethod
    def encoding(self, id):
        pass

    @abstractmethod
    def encrypt(id):
        pass

```

## 外观模式实现类
```python
# Facade.py 外观模式实现类，是外部调用与内部子系统的衔接层
from src.AbstractFacade import AbstractFacade
from src.FileModule import FileModule
from src.NetworkModule import NetworkModule
from src.EncodeModule import EncodeModule


# 外观模式实现类，是外部调用与内部子系统的衔接层
class Facade():
# 继承抽象类可选
# class Facade(AbstractFacade):
    def __init__(self):
        self.file_module = FileModule()
        self.network_module = NetworkModule()
        self.encode_module = EncodeModule()

    def encoding(self, id):
        print(self.__class__.__name__ + '::encoding() [id=' + str(id) + ']')
        self.network_module.request()
        self.file_module.read_file()
        self.encode_module.encoding()
        self.file_module.save_file()

    def encrypt(self, id):
        print(self.__class__.__name__ + '::encrypt() [id=' + str(id) + ']')
        self.file_module.read_file()
        self.encode_module.encoding()

    def getfile_module(self):
        return self.file_module

    def getnetwork_module(self):
        return self.network_module

    def getencode_module(self):
        return self.encode_module
```

## 几个具体模块类
```py
# FileModule.py 文件模块
class FileModule:

    def read_file(self):
        print(self.__class__.__name__ + '::read_file() 读取文件。')

    def save_file(self):
        print(self.__class__.__name__ + '::save_file() 保存文件。')
```

```py
# EncodeModule.py 编码模块
class EncodeModule():
    def encoding(self):
        print(self.__class__.__name__ + '::encoding() 进行编码处理。')
```

```py
# NetworkModule.py 网络模块
class NetworkModule:
    def request(self):
        print(self.__class__.__name__ + '::request() 远程读取。')

```

## 测试调用
```py
import sys
import os

os_path = os.getcwd()
sys.path.append(os_path)

from src.Facade import Facade

def test():
    '''
    * 外观模式就是在外层添加一个访问接口类，客户通过这统一访问接口来访问这些复杂子类。
    * 外观模式与适配器模式比较像，都是提供一个高层访问接口，隔绝外部客户与内部子类。
    * 所不同是外观模式后面的类无需实现相同接口，只是把各种调用整合简化，而适配器需要是同一系列类，为的是解决接口不兼容。
    * 这里声明外观类，外观类的方法里影藏了很多子类的调用。
    '''

    facade = Facade()
    facade.encoding(123456)
    facade.encrypt(999999)


if __name__ == '__main__':
    print(__file__)
    print("test start:")
    test()
```

## 更多语言版本
不同语言实现设计模式对比，请关注：[https://github.com/microwind/design-pattern](https://github.com/microwind/design-pattern)