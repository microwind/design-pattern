#include "func.h"

// 定义策略执行对象context

// 设置不同strategy，方法名首字母大写
void context_set_strategy(Context *context, Strategy *strategy)
{
  context->strategy = strategy;
}

void context_run(Context *context)
{
  printf("\r\n context_run() [context=%s strategy=%s]", context->name, context->strategy->name);
  if (context->strategy != NULL)
  {
    context->strategy->run(context->strategy);
  }
}

Context *context_constructor(char *name)
{
  Context *context = (Context *)malloc(sizeof(Context));
  strcpy(context->name, name);
  context->set_strategy = &context_set_strategy;
  context->run = &context_run;
  return context;
}