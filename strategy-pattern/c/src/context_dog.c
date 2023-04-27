#include "func.h"

// 定义具体执行对象，执行策略接口里面的方法
void context_dog_run(ContextDog *context)
{
  printf("\r\n context_dog_run() [context=%s strategy=%s]", context->name, context->strategy->name);
  if (context->strategy != NULL)
  {
    context->strategy->run(context->strategy);
  }
}

ContextDog *context_dog_constructor(char *name)
{
  printf("\r\n context_dog_constructor() [构建ContextDog]");
  Context *context = context_constructor(name);
  ContextDog *context_dog = (ContextDog *)context;
  // 可提前绑定具体的策略
  context_dog->set_strategy(context_dog, (Strategy *)strategy_b_constructor("strategy_b"));
  context_dog->run = &context_dog_run;
  return context_dog;
}