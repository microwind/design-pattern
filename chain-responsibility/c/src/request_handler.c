#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "func.h"

/* RequestHandler check函数实现 */
bool request_handler_check(Handler *handler, int param)
{
  printf("\r\n request_handler_check: [handler.name = %s param = %d]", handler->name, param);
  RequestHandler *request_handler = (RequestHandler *)handler;
  if (param % 5 == 0)
  {
    printf("\r\n request_handler_check: error[ %d %s 2 ] == 0", param, "%");
    return false;
  }
  // 通过next调用下一步检查
  if (handler->next != NULL)
  {
    return request_handler->next->check_next(handler->next, param);
  }
  return false;
}

/* 创建具体处理器的函数 */
RequestHandler *create_request_handler(char *name)
{
  RequestHandler *handler = (RequestHandler *)malloc(sizeof(RequestHandler));
  strncpy(handler->name, name, 50);
  // 将handler的check_next函数赋值为指定函数，便于检查处理
  handler->check_next = &request_handler_check;
  handler->next = NULL;
  return handler;
}