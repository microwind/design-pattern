#include "func.h"

// 定义子类覆写父类抽象方法
void football_init(Football *game)
{
  printf("\r\n Football::init() [Football Game Initialized! Start playing.]");
}

void football_start(Football *game)
{
  printf("\r\n Football::start() [Football Game Started. Enjoy the game!]");
}

void football_end(Football *game)
{
  printf("\r\n Football::end() [Football Game Finished!]");
}

Football *football_constructor(char *name)
{
  printf("\r\n football_constructor() [构建Football]");
  GameTemplate *template = game_template_constructor(name);
  Football *game = (Football *)template;
  game->init = &football_init;
  game->start = &football_start;
  game->end = &football_end;
  return game;
}