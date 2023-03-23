#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "func.h"

/* AuthHandler check函数实现 */
bool auth_handler_check(Handler *handler, int param)
{
    printf("\r\n auth_handler_check: [handler.name = %s param = %d]", handler->name, param);
    AuthHandler *auth_handler = (AuthHandler *)handler;
    // 这里是判断条件，如果出错则终止调用链，返回false
    if (param % 2 == 0)
    {
        printf("\r\n auth_handler_check: error[ %d %s 2 ] == 0", param, "%");
        return false;
    }
    // 通过next调用下一步检查
    if (handler->next != NULL)
    {
        return auth_handler->next->check_handler(handler->next, param);
    }
    return true;
}

/* 创建具体处理器的函数 */
AuthHandler *create_auth_handler(char *name)
{
    AuthHandler *handler = (AuthHandler *)malloc(sizeof(AuthHandler));
    strncpy(handler->name, name, 50);
    // 将handler的check_handler函数赋值为指定函数，便于检查处理
    handler->check_handler = &auth_handler_check;
    handler->next = NULL;
    return handler;
}