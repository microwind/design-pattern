#include "func.h"

// 定义抽象模板类的公共部分，这里用struct替代

// 抽象方法待子类来实现
void template_init(GameTemplate *game) {}
void template_start(GameTemplate *game)
{
  printf("\r\n GameTemplate::start() [GameTemplate Initialized! Start playing.]");
}
void template_end(GameTemplate *game) {}

// 可复用的算法流程
void template_play(GameTemplate *game)
{
  printf("\r\n GameTemplate::play() [name=%s]", game->name);

  // 初始化游戏
  game->init(game);

  // 开始游戏
  game->start(game);

  // 结束游戏
  game->end(game);
}

GameTemplate *game_template_constructor(char *name)
{
  // printf("\r\n game_template_constructor() [构建GameTemplate]");
  GameTemplate *game = (GameTemplate *)malloc(sizeof(GameTemplate));
  strcpy(game->name, name);
  game->init = &template_init;
  game->start = &template_start;
  game->end = &template_end;
  game->play = &template_play;
  return game;
}