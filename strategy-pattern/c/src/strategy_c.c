#include "func.h"

// 定义策略C

// 实现策略接口的对应方法
void strategy_c_run(StrategyC *strategy)
{
  printf("\r\n StrategyC::run()");
}

StrategyC *strategy_c_constructor(char *name)
{
  // printf("\r\n strategy_c_constructor() [构建StrategyC]");
  Strategy *strategy = (Strategy *)malloc(sizeof(Strategy));
  StrategyC *strategy_c = (StrategyC *)strategy;
  strcpy(strategy_c->name, name);
  strategy_c->run = &strategy_c_run;
  return strategy_c;
}