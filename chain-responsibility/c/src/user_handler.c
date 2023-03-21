#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "func.h"

/* UserHandler check_next函数实现 */
bool user_handler_check(Handler *handler, int param)
{
  printf("\r\n user_handler_check: [handler.name = %s param = %d]", handler->name, param);
  UserHandler *user_handler = (UserHandler *)handler;
  // 这里是判断条件，如果出错则终止调用链，返回false
  if (param % 3 == 0)
  {
    printf("\r\n user_handler_check: error[ %d %s 3 ] == 0", param, "%");
    return false;
  }
  // 通过next调用下一步检查
  if (handler->next != NULL)
  {
    return user_handler->next->check_next(handler->next, param);
  }
  return true;
}

/* 创建具体处理器的函数 */
UserHandler *create_user_handler(char *name)
{
  UserHandler *handler = (UserHandler *)malloc(sizeof(UserHandler));
  strncpy(handler->name, name, 50);
  // 将handler的check_next函数赋值为指定函数，便于检查处理
  handler->check_next = &user_handler_check;
  handler->next = NULL;
  return handler;
}