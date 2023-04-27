#include "func.h"

// 定义策略A

// 实现策略接口的对应方法
void strategy_a_run(StrategyA *strategy)
{
  printf("\r\n StrategyA::run()");
}

StrategyA *strategy_a_constructor(char *name)
{
  // printf("\r\n strategy_a_constructor() [构建StrategyA]");
  Strategy *strategy = (Strategy *)malloc(sizeof(Strategy));
  StrategyA *strategy_a = (StrategyA *)strategy;
  strcpy(strategy_a->name, name);
  strategy_a->run = &strategy_a_run;
  return strategy_a;
}