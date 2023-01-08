package src;

// 定义子类覆写父类抽象方法
public class Basketball extends GameTemplate {

   @Override
   void init() {
      System.out.println("Basketball::init() [Basketball Game Initialized! Start playing.]");
   }

   @Override
   void start() {
      System.out.println("Basketball::start() [Basketball Game Started. Enjoy the game!]");
   }

   @Override
   void end() {
      System.out.println("Basketball::end() [Basketball Game Finished!]");
   }

}