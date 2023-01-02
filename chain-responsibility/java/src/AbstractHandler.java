package src;

// 抽象处理类，所有处理变成链式，可以互动干涉，动态组合
public abstract class AbstractHandler {
   // 形成职责链
   private AbstractHandler next;

   // 创建调用链，传入多个handler，按顺序形成链，返回第一个handler
   public static AbstractHandler link(AbstractHandler first, AbstractHandler... chain) {
      AbstractHandler head = first;
      for (AbstractHandler handler : chain) {
         head.next = handler;
         head = handler;
      }
      return first;
   }

   // 子类需要实现的检查方法
   public abstract boolean check(int uid);

   // 继续下一个检查
   protected boolean checkNext(int uid) {
      if (next == null) {
         return true;
      }
      return next.check(uid);
   }
}