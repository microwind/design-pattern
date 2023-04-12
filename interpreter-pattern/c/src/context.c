#include "func.h"

void add(Context *context, char *key, int value)
{
  printf("\r\n Context::add() [key=%s, value=%d]", key, value);
  // 申请新的数组
  int new_len = context->length + 1;
  char **new_keys = (char **)calloc(new_len * 50, sizeof(char));
  int *new_values = (int *)malloc(new_len * sizeof(int));

  // 复制原来的数组内容
  for (int i = 0; i < context->length; i++)
  {
    new_keys[i] = context->keys[i];
    new_values[i] = context->values[i];
  }
  // 追加新的内容
  new_keys[context->length] = key;
  new_values[context->length] = value;
  // 指向新数组
  context->keys = new_keys;
  context->values = new_values;
  // 重设新的长度
  context->length = new_len;
}

int get(Context *context, char *key)
{
  int idx;
  for (int i = 0; i < context->length; i++)
  {
    if (strcmp(context->keys[i], key) == 0)
    {
      idx = i;
      break;
    }
  }
  return context->values[idx];
}

// 构建可执行环境上下文
Context *context_constructor()
{
  printf("\r\n context_constructor() 构建执行上下文");
  Context *context = (Context *)malloc(sizeof(Context));
  context->keys = NULL;
  context->values = NULL;
  context->length = 0;
  context->add = &add;
  context->get = &get;
  return context;
}