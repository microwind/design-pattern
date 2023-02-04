# 简介
享元模式（Flyweight Pattern），是一种结构型设计模式。主要用于减少创建对象的数量，以减少内存占用和提高性能。它摒弃了在每个对象中保存所有数据的方式，通过共享多个对象所共有的相同状态，让你能在有限的内存容量中载入更多对象。

当程序需要生成数量巨大的相似对象时，可能对内存有大量损耗，而对象中包含可抽取且能在多个对象间共享的重复状态，您可以采取享元模式。

内部状态 vs. 外部状态
内部状态是存储在享元对象内部，一般在构造时确定或通过setter设置，并且不会随环境改变而改变的状态，因此内部状态可以共享。
外部状态是随环境改变而改变、不可以共享的状态。外部状态在需要使用时通过客户端传入享元对象。外部状态必须由客户端保存。

# 作用
1. 有相同的业务请求，直接返回在内存中已有的对象，避免重新创建。
2. 如果程序中有很多相似对象，可减少对象的创建，降低系统的内存，使效率提高。

# 实现步骤
1. 创建享元角色抽象接口，用于具体享元角色实现。
2. 创建具体享元角色，实现抽象方法。具体享元角色就是一般类，该类可以支持外部状态数据。
3. 创建享元工厂，里面建一个储存对象共享池，对已经实例化的对象直接取出返回。

# UML
<img src="../docs/uml/flyweight-pattern.png">

# 代码

## 享元抽象接口
```java
// Flyweight.java 享元角色抽象接口
public interface Flyweight {
   void operate(String state);
}
```

## 具体享元角色

```java
// ConcreteFlyweight.java 具体享元角色，实现抽象接口，用于共享状态，一个类被创建以后就不用重复创建了
public class ConcreteFlyweight implements Flyweight {
   private String name;
   private String type;

   public ConcreteFlyweight(String name) {
      // 内部状态，即不会随着环境的改变而改变的可共享部分
      // 这里的name也是对象保存的key
      this.name = name;
      this.type = "piano";
      System.out.println("ConcreteFlyweight::ConcreteFlyweight(name) [创建具体享元" + name + "]");
   }

  // 这里state属于外部状态，由外部调用时传入
  // 也可以把非共享的对象传入进来
   @Override
   public void operate(String state) {
      System.out.println(
            String.format("%s::operate() [%s %s %s]", this.getClass().getName(), this.getName(),
                  this.getType(), state));
   }

   public String getName() {
      return this.name;
   }

   public String getType() {
      return this.type;
   }
}
```

```java
// UnsharedConcreteFlyweight.java 无需共享的角色，每次都是新实例
public class UnsharedConcreteFlyweight implements Flyweight {
   private String name;
   private String type = "guitar";

   public UnsharedConcreteFlyweight(String name) {
      this.name = name;
      System.out.println("UnsharedConcreteFlyweight::UnsharedConcreteFlyweight(name) [创建非共享对象" + name + "]");
   }


   // 这里state属于外部状态，在调用时外部传入。
   @Override
   public void operate(String state) {
      System.out.println(
            String.format("%s::operate() [%s %s %s]", this.getClass().getName(), this.getName(),
                  this.getType(), state));
   }

   public String getName() {
      return this.name;
   }

   public String getType() {
      return this.type;
   }
}
```

## 享元工厂类
```java
// FlyweightFactory.java 享元工厂，储存一个对象共享池，已经生成过的对象直接取出
public class FlyweightFactory {
   public static Map<String, Flyweight> pool = new HashMap<String, Flyweight>();

   // 这里的name可以认为是内部状态，在构造时确定，具有唯一性。
   public static Flyweight getFactory(String name) {
      Flyweight flyweight = pool.get(name);
      if (flyweight == null) {
         // 如果对象不存在则创建新的对象放入到池子里，如果已经存在则复用前面的对象
         flyweight = new ConcreteFlyweight(name);
         pool.put(name, flyweight);
      } else {
         System.out.println("FlyweightFactory::getFactory(name) [成功获取具体享元" + name + "]");
       }
      return flyweight;
   }
}
```

## 测试调用
```java
    /**
     * 享元模式就是将已经声明过的实例或数据保存在内存里，需要使用时则取出来，无需再次实例化和声明。
     * 通过共享多个对象所共有的相同状态，以达到节省开销的目的。
     * 享元模式分为内部状态和外部状态，内部状态基于享元对象共享，外部状态则外部传入或使用非享元类。
     */

    // 假设有钢琴和吉他，钢琴使用者很多需要共享实例，而吉他每次创建新实例

    // 2个一样名称的为共享对象，只创建1个实例，后面的返回缓存实例
    Flyweight factory1 = FlyweightFactory.getFactory("piano1");
    // piano1已经声明过了，同名则共享前面的实例
    Flyweight factory2 = FlyweightFactory.getFactory("piano1");
    Flyweight factory3 = FlyweightFactory.getFactory("piano2");
    Flyweight factory4 = FlyweightFactory.getFactory("piano2");

    factory1.operate("factory1");
    factory2.operate("factory2");
    factory3.operate("factory3");
    factory4.operate("factory4");

    // 查看一共多少个对象
    for (Map.Entry<String, Flyweight> entry : FlyweightFactory.pool.entrySet()) {
      System.out.println("享元对象:" + entry.getKey());
      // entry.getValue().operate(null);
    }

    // 无需共享的，名字一样也是多个对象
    Flyweight factory5 = new UnsharedConcreteFlyweight("guitar1");
    Flyweight factory6 = new UnsharedConcreteFlyweight("guitar1");
    factory5.operate("factory5");
    factory6.operate("factory6");
```
## 更多语言版本
不同语言实现设计模式：[https://github.com/microwind/design-pattern](https://github.com/microwind/design-pattern)