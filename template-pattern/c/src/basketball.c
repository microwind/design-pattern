#include "func.h"

// 定义子类覆写父类抽象方法
void basketball_init(Basketball *game)
{
  printf("\r\n Basketball::init() [Basketball Game Initialized! Start playing.]");
}

void basketball_start(Basketball *game)
{
  printf("\r\n Basketball::start() [Basketball Game Started. Enjoy the game!]");
}

void basketball_end(Basketball *game)
{
  printf("\r\n Basketball::end() [Basketball Game Finished!]");
}

Basketball *basketball_constructor(char *name)
{
  printf("\r\n basketball_constructor() [构建Basketball]");
  GameTemplate *template = game_template_constructor(name);
  Basketball *game = (Basketball *)template;
  game->init = &basketball_init;
  // 如果不覆盖则使用基类的函数
  // game->start = &basketball_start;
  game->end = &basketball_end;
  return game;
}