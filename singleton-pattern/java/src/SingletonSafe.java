package src;

public class SingletonSafe {

  private static SingletonSafe instance;

  private SingletonSafe() {

  }

  // 延迟到调用时实例化
  public static SingletonSafe getInstance() {
    if (instance == null) {
      //在实例化时再synchronized
      synchronized (SingletonSafe.class) {
        if (instance == null) {
          instance = new SingletonSafe();
        }
      }
    }
    return instance;
  }

  public void run() {
    System.out.println("SingletonSafe::run()");
  }
}
