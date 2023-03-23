#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "func.h"

// 创建调用链，按顺序形成链，返回第一个handler
Handler *link_handler(Handler *handler, Handler *next)
{
  handler->next = next;
  return handler;
}

// 不定参数创建调用链，第一个参数是handler的数量，后面是多个handler
Handler *make_handler_chain_count(int lenght, ...)
{
  va_list args;
  va_start(args, lenght);
  // 取出第1个handler
  Handler *first = va_arg(args, Handler *);
  Handler *head = first;
  // 把handler追加到next中，形成链，总长度减去第1个
  for (int i = 0; i < lenght - 1; i++)
  {
    head->next = va_arg(args, Handler *);
    head = head->next;
  }
  va_end(args);
  return first;
}

// 不定参数创建调用链，第一个参数是handler的数量，后面是多个handler，最后一个传NULL
Handler *make_handler_chain(Handler *first, ...)
{
  va_list args;
  va_start(args, first);
  Handler *head = first;
  // 把handler追加到next中，以NULL作为结束符
  while (head != NULL)
  {
    head->next = va_arg(args, Handler *);
    head = head->next;
  }
  va_end(args);
  return first;
}

// 单独handler检查开始函数
bool check_handler_start(Handler *handler, int param)
{
  return handler->check_handler(handler, param);
}