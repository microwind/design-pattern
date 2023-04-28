#include "func.h"

// 定义子类覆写父类抽象方法
void tennis_init(Tennis *game)
{
  printf("\r\n Tennis::init() [Tennis Game Initialized! Start playing.]");
}

void tennis_start(Tennis *game)
{
  printf("\r\n Tennis::start() [Tennis Game Started. Enjoy the game!]");
}

void tennis_end(Tennis *game)
{
  printf("\r\n Tennis::end() [Tennis Game Finished!]");
}

// 在调用父类play之前，如果要执行自己的行为，也可以覆盖父类方法
void tennis_play(Tennis *game)
{
  // 先执行自己的内容，再调用基类的函数
  printf("\r\n Tennis::play() [Tennis Game Play!]");
  template_play((GameTemplate *)game);
}

Tennis *tennis_constructor(char *name)
{
  printf("\r\n tennis_constructor() [构建Tennis]");
  GameTemplate *template = game_template_constructor(name);
  Tennis *game = (Tennis *)template;
  game->init = &tennis_init;
  game->start = &tennis_start;
  game->end = &tennis_end;
  game->play = &tennis_play;
  return game;
}