# 【外观设计模式详解】Java/JS/Go/Python/TS不同语言实现

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


# 代码

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

## 更多语言版本
不同语言实现设计模式：[https://github.com/microwind/design-pattern](https://github.com/microwind/design-pattern)