package src;

import java.util.*;

// 定义抽象主题类或者接口，供具体主题类继承
public abstract class Subject {
   private String name;
   // protected Set<ObserverAPI> observers = new HashSet<>();
   protected List<ObserverAPI> observers = new ArrayList<>();

   public String getName() {
      return name;
   }

   public void setName(String name) {
      this.name = name;
   }

   public void register(ObserverAPI observer) {
      System.out.println(this.getClass().getName() + "::register() [observer = " + observer.getClass().getSimpleName() + "]");
      observers.add(observer);
   }

   public void remove(ObserverAPI observer) {
      observers.remove(observer);
   }

   // 通知由具体类来实现逻辑
   public abstract void notify(String name);
}