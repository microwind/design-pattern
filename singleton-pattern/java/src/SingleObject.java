package src;

public class SingleObject {
  // 类加载时就初始化，浪费内存
  private static final SingleObject singleObject = new SingleObject();

  // 构造函数是private，不允许实例化
  private SingleObject() {

  }
  public static SingleObject getInstance() {
    return singleObject;
  }

  public void run() {
    System.out.println("SingleObject::run()");
  }
}
