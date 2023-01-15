package src;

// 双重检验懒汉单例，单例模式最优方案，线程安全并且效率高 
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
