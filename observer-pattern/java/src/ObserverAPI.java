package src;

// 观察者接口，Java 9已经默认支持Observer接口
// 这里避免冲突采取ObserverAPI命名
public interface ObserverAPI {
   public Subject subject = null;
   public void update(String content);
}