#include "func.h"

// 定义策略B

// 实现策略接口的对应方法
void strategy_b_run(StrategyB *strategy)
{
  printf("\r\n StrategyB::run()");
}

StrategyB *strategy_b_constructor(char *name)
{
  // printf("\r\n strategy_b_constructor() [构建StrategyB]");
  Strategy *strategy = (Strategy *)malloc(sizeof(Strategy));
  StrategyB *strategy_b = (StrategyB *)strategy;
  strcpy(strategy_b->name, name);
  strategy_b->run = &strategy_b_run;
  return strategy_b;
}