package src;

public class SingletonInner {

  private SingletonInner() {

  }

  private static class Inner {
    private static final SingletonInner instance = new SingletonInner();  
  }

  public static SingletonInner getInstance() {
    return Inner.instance;
  }

  public void run() {
    System.out.println("SingletonInner::run()");
  }
}
