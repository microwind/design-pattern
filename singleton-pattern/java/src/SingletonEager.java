package src;

// 饿汉式（线程安全）
// 当类被加载的时候会初始化，静态变量被创建并分配内存空间 
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
