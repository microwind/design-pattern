package src;

public class SingletonLazy {

  private static SingletonLazy instance;

  private SingletonLazy() {

  }

  // 延迟到调用时实例化，加synchronized以便线程安全
  public static synchronized SingletonLazy getInstance() {
    if (instance == null) {
      instance = new SingletonLazy();
    }
    return instance;
  }

  public void run() {
    System.out.println("SingletonLazy::run()");
  }
}
