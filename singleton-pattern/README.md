# 简介
单例模式（Singleton Pattern）属于创建型设计模式，这种模式只创建一个单一的类，保证一个类只有一个实例，并提供一个访问该实例的全局节点。

当您想控制实例数目，节省系统资源，并不想混用的时候，可以使用单例模式。

# 作用
1. 避免全局使用的类频繁地创建与销毁。
2. 保证一个类仅有一个实例，并提供一个访问它的全局访问点。

# 实现步骤
1. 创建单例类，注意线程安全
2. 返回全局唯一实例

# UML
<img src="../docs/uml/singleton-pattern.png">

# 代码

单例实现，不同语言有很大不同，跟语言特性有关。请查看其他源码进行比较。

## 饿汉式（线程安全）
```java
// SingletonEager.java 当类被加载的时候会初始化，静态变量被创建并分配内存空间 
public class SingletonEager {
  private String name = "SingletonEager";
  // 类加载时就初始化，浪费内存
  private static final SingletonEager instance = new SingletonEager();

  // 构造函数是private，不允许实例化
  private SingletonEager() {

  }
  public static SingletonEager getInstance() {
    return instance;
  }

  public void run() {
    System.out.println("SingletonEager::run() " + this.name);
  }
}
```

## 饱汉式
```java
// SingletonLazy.java 懒汉式也叫饱汉式，增加synchronized来保证线程安全
public class SingletonLazy {

  private static SingletonLazy instance;
  private String name;

  private SingletonLazy() {

  }

  // 类初始化时，静态变量static的instance未被创建并分配内存空间
  // 当getInstance方法第一次被调用时，再初始化instance变量，并分配内存
  // 相当于延迟到调用时再实例化，加synchronized以便线程安全，不加则存在并发时多个实例的情形
  public static synchronized SingletonLazy getInstance(String name) {
    if (instance == null) {
      instance = new SingletonLazy();
      instance.name = name;
    }
    return instance;
  }

  public void run() {
    System.out.println("SingletonLazy::run() " + this.name);
  }
}
```

## 静态内部类
```java
// SingletonInner.java 静态内部类方式，既实现延迟加载，也保障线程安全。
public class SingletonInner {

  private String name;

  private SingletonInner() {

  }

  // 静态内部类利用了类加载初始化机制，外部类加载时，并不会加载内部类，也不会执行
  // 虚拟机会保证方法在多线程环境下使用加锁同步，只会执行一次，因此线程安全
  private static class Inner {
    private static final SingletonInner instance = new SingletonInner();
  }

  // 当执行getInstance()方法时，虚拟机才会加载静态内部类
  public static SingletonInner getInstance(String name) {
    if (Inner.instance.name == null) {
      Inner.instance.name = name;
    }
    return Inner.instance;
  }

  public void run() {
    System.out.println("SingletonInner::run() " + this.name);
  }
}
```

## 双重检验懒汉
```java
// SingletonDoubleCheck.java 双重检验懒汉单例，单例模式最优方案，线程安全并且效率高 
public class SingletonDoubleCheck {

  // 定义一个静态私有变量(不初始化，不使用final关键字）
  // 可以使用volatile保证多线程访问时变量的可见性
  // 这样避免了初始化时其他变量属性还没赋值完时，被另外线程调用
  private static volatile SingletonDoubleCheck instance;
  private String name;
  private SingletonDoubleCheck() {

  }

  // 延迟到调用时实例化
  public static SingletonDoubleCheck getInstance(String name) {
    if (instance == null) {
      // 在实例化时再synchronized
      synchronized (SingletonDoubleCheck.class) {
        if (instance == null) {
          instance = new SingletonDoubleCheck();
          instance.name = name;
        }
      }
    }
    return instance;
  }

  public void run() {
    System.out.println("SingletonDoubleCheck::run() " + this.name);
  }
}

```

## 测试调用
```java
    /**
     * 单例模式就是一个类只创建一个实例，以便节省开销和保证统一
     * 对于多线程语言需要注意线程安全和性能之间取得一个平衡
     */
    SingletonEager singletonEager1 = SingletonEager.getInstance();
    SingletonEager singletonEager2 = SingletonEager.getInstance();
    singletonEager1.run();
    singletonEager2.run();
    // 两个实例相等
    System.out.println("singletonEager1 == singletonEager2 ? " + String.valueOf(singletonEager1 == singletonEager2));

    /*********************** 分割线 ******************************************/

    SingletonLazy singletonLazy1 = SingletonLazy.getInstance("singletonLazy1");
    SingletonLazy singletonLazy2 = SingletonLazy.getInstance("singletonLazy2");
    singletonLazy1.run();
    singletonLazy2.run();

    /*********************** 分割线 ******************************************/

    SingletonDoubleCheck singletonDoubleCheck1 = SingletonDoubleCheck.getInstance("singletonDoubleCheck1");
    SingletonDoubleCheck singletonDoubleCheck2 = SingletonDoubleCheck.getInstance("singletonDoubleCheck2");
    singletonDoubleCheck1.run();
    singletonDoubleCheck2.run();

    /*********************** 分割线 ******************************************/

    SingletonInner singletonInner1 = SingletonInner.getInstance("singletonInner1");
    SingletonInner singletonInner2 = SingletonInner.getInstance("singletonInner2");
    singletonInner1.run();
    singletonInner2.run();
```
## 更多语言版本
不同语言实现设计模式：[https://github.com/microwind/design-pattern](https://github.com/microwind/design-pattern)