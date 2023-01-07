package src;

// 具体的观察者实现类，也可以看成订阅者，关联对应的主题类。
// 不同的观察者可以对应不同的主题。
public class ConcreteObserver2 implements ObserverAPI {

  // 这里没有在构造器就绑定某个主题，而是从客户角度去注册观察者
  public ConcreteObserver2() {
  }

  // 观察者发出更新通知，观察者自行监听
  public void update(String content) {
    System.out.println(String.format("%s::update() [content = %s]",
        this.getClass().getName(), content));
  }
}