#include "func.h"

// 定义具体执行对象，执行策略接口里面的方法
void context_cat_run(ContextCat *context)
{
  printf("\r\n context_cat_run() [context=%s strategy=%s]", context->name, context->strategy->name);
  if (context->strategy != NULL)
  {
    context->strategy->run(context->strategy);
  }
}

ContextCat *context_cat_constructor(char *name)
{
  printf("\r\n context_cat_constructor() [构建ContextCat]");
  Context *context = context_constructor(name);
  ContextCat *context_cat = (ContextCat *)context;
  // 可提前绑定具体的策略
  context_cat->set_strategy(context_cat, (Strategy *)strategy_c_constructor("strategy_c"));
  context_cat->run = &context_cat_run;
  return context_cat;
}