package src;

// 定义子类覆写父类抽象方法
public class Football extends GameTemplate {

   @Override
   void init() {
      System.out.println("Football::init() [Football Game Initialized! Start playing.]");
   }

   @Override
   void start() {
      System.out.println("Football::start() [Football Game Started. Enjoy the game!]");
   }

   @Override
   void end() {
      System.out.println("Football::end() [Football Game Finished!]");
   }

}