package src;

import java.util.*;

// 构建可执行环境上下文
public class Context {

   private Map<String, Integer> map = new HashMap<>();

   public Context(String key, int value) {
      this.add(key, value);
   }

   public Context() {
   }

   public void add(String key, int value) {
      map.put(key, value);
   }

   public int get(String key) {
      return map.get(key);
   }
}