package src;

// 观察者主题类，也是发布者，重写具体的通知方法。不同主题可以关联不同的观察者。
public class ConcreteSubject extends Subject {

   public ConcreteSubject(String name) {
      this.setName(name);
   }

   // 不同的主题类有自己的通知方法，批量通知绑定的观察者
   @Override
   public void notify(String content) {
      System.out.println(this.getClass().getName() + "::notify() [content = " + content + "]");
      for (Object observer : this.observers) {
         ((ObserverAPI) observer).update(content);
      }

   }

}
