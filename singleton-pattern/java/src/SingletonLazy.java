package src;

// 懒汉式也叫饱汉式，增加synchronized来保证线程安全
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
