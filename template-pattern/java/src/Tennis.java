package src;

// 定义子类覆写父类抽象方法
public class Tennis extends GameTemplate {

   @Override
   void init() {
      System.out.println("Tennis::init() [Tennis Game Initialized! Start playing.]");
   }

   @Override
   void start() {
      System.out.println("Tennis::start() [Tennis Game Started. Enjoy the game!]");
   }

   @Override
   void end() {
      System.out.println("Tennis::end() [Tennis Game Finished!]");
   }

}