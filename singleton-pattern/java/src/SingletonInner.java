package src;

// 静态内部类方式，既实现延迟加载，也保障线程安全。
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
