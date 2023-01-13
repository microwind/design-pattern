package test;

import src.*;

public class Test {

  public static void start() {
    /**
     * 模板方法模式就是当子类具备类似行为的时候，让子类共用一套流程
     * 创建一个公共模板，确定公用流程和操作动作，子类覆盖具体的动作
     */
    GameTemplate football = new Football();
    football.play();

    System.out.println("===");
    GameTemplate basketball = new Basketball();
    basketball.play();

    System.out.println("===");
    GameTemplate tennis = new Tennis();
    tennis.play();

  }

  public static void main(String[] args) {
    System.out.println("test start:");
    start();
  }

}

/**
 * 测试
 * jarry@jarrys-MacBook-Pro java % javac -encoding utf-8 test/Test.java
 * jarry@jarrys-MacBook-Pro java % java test/Test
 * test start:
 * Football::play()
 * Football::init() [Football Game Initialized! Start playing.]
 * Football::start() [Football Game Started. Enjoy the game!]
 * Football::end() [Football Game Finished!]
 * ===
 * Basketball::play()
 * Basketball::init() [Basketball Game Initialized! Start playing.]
 * Basketball::start() [Basketball Game Started. Enjoy the game!]
 * Basketball::end() [Basketball Game Finished!]
 * ===
 * Tennis::play()
 * Tennis::init() [Tennis Game Initialized! Start playing.]
 * Tennis::start() [Tennis Game Started. Enjoy the game!]
 * Tennis::end() [Tennis Game Finished!]
 */