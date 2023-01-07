package src;

// 具体的观察者实现类，也可以看成订阅者，关联对应的主题类。
// 不同的观察者也可以对应多个主题
public class ConcreteObserver implements ObserverAPI {

   public Subject subject;

   // 给观察者绑定主题，同时把观察者添加到主题列表
   public ConcreteObserver(Subject subject) {
      this.subject = subject;
      this.subject.register((ObserverAPI) this);
   }

   // 观察者发出更新通知，不用单独告诉订阅者，由订阅者自行监听
   public void update(String content) {
      System.out.println(String.format("%s::update() [subject.name = %s content = %s]",
            this.getClass().getName(),
            this.subject.getName(), content));
   }
}