#include "../src/func.h"

int main(void)
{
  printf("test start:\r\n");
  /**
   * 模板方法模式就是当子类具备类似行为的时候，让子类共用一套流程
   * 创建一个公共模板，确定公用流程和操作动作，子类覆盖具体的动作
   */
  Football *football = football_constructor("football");
  football->play(football);

  printf("\r\n ===");
  Basketball *basketball = basketball_constructor("basketball");
  basketball->play(basketball);

  printf("\r\n ===");
  Tennis *tennis = tennis_constructor("basketball");
  tennis->play(tennis);
}

// jarry@jarrys-MacBook-Pro c % gcc test/test.c ./src/*.c
// jarry@jarrys-MacBook-Pro c % ./a.out
/**
test start:

 football_constructor() [构建Football]
 GameTemplate::play() [name=football]
 Football::init() [Football Game Initialized! Start playing.]
 Football::start() [Football Game Started. Enjoy the game!]
 Football::end() [Football Game Finished!]
 ===
 basketball_constructor() [构建Basketball]
 GameTemplate::play() [name=basketball]
 Basketball::init() [Basketball Game Initialized! Start playing.]
 GameTemplate::start() [GameTemplate Initialized! Start playing.]
 Basketball::end() [Basketball Game Finished!]
 ===
 tennis_constructor() [构建Tennis]
 Tennis::play() [Tennis Game Play!]
 GameTemplate::play() [name=basketball]
 Tennis::init() [Tennis Game Initialized! Start playing.]
 Tennis::start() [Tennis Game Started. Enjoy the game!]
 Tennis::end() [Tennis Game Finished!]%
 */