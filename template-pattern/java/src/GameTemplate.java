package src;

// 定义抽象模板类
public abstract class GameTemplate {

   // 抽象方法待子类来实现
   abstract void init();

   abstract void start();

   abstract void end();

   // 可复用的算法流程
   public final void play() {

      System.out.println(this.getClass().getSimpleName() + "::play()");

      // 初始化游戏
      init();

      // 开始游戏
      start();

      // 结束游戏
      end();
   }

}