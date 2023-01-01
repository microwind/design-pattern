package src;

import java.util.*;

// 享元工厂，储存一个对象共享池，已经生成过的对象直接取出
public class FlyweightFactory {
   public static Map<String, Flyweight> pool = new HashMap<String, Flyweight>();

   // 这里的name可以认为是内部状态，在构造时确定，具有唯一性。
   public static Flyweight getFactory(String name) {
      Flyweight flyweight = pool.get(name);
      if (flyweight == null) {
         // 如果对象不存在则创建新的对象放入到池子里，如果已经存在则复用前面的对象
         flyweight = new ConcreteFlyweight(name);
         pool.put(name, flyweight);
      }
      return flyweight;
   }
}
