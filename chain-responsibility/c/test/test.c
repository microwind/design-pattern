#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../src/func.h"

int main(void)
{
    /**
     * 责任链模式核心是打造一个调用处理链，每个处理链都实现抽象类的next方法，从而可以任意组织各种检查行为。
     * 通过改变链内的成员或者调动它们的顺序，允许动态地新增或者删除职责，从而实现按需组织。
     */

    // 创建一组hanler
    RequestHandler *request_handler = create_request_handler("request_handler_01");
    UserHandler *user_handler = create_user_handler("user_handler_02");
    AuthHandler *auth_handler = create_auth_handler("auth_handler_03");
    printf("创建handler:\r\n %s %s %s", request_handler->name, user_handler->name, auth_handler->name);

    // 将handler逐个链接成职责链
    link_handler((Handler *)request_handler, (Handler *)user_handler);
    link_handler((Handler *)user_handler, (Handler *)auth_handler);

    printf("\r\n建立职责链:\r\n");
    Handler *handler_cur = (Handler *)request_handler;
    while (handler_cur != NULL)
    {
        printf(" -> %s", handler_cur->name);
        handler_cur = handler_cur->next;
    }

    // 从任意handler开始检查
    // printf("\r\ncheck_handler_start检查:");
    // check_handler_start((Handler *)request_handler, 666);

    // 从执行handler开始
    printf("\r\n开始检查:");
    bool result1 = request_handler_check((Handler *)request_handler, 666);
    printf("\r\n执行结果: %s \r\n", result1 ? "true" : "false");

    /* 释放内存 */
    free(handler_cur);
    free(request_handler);
    free(auth_handler);
    free(user_handler);

    /*** ========分割线============ ***/
    printf("\r\n=============\r\n");

    /* 创建一组hanler */
    RequestHandler *request_handler2 = create_request_handler("request_handler_101");
    UserHandler *user_handler2 = create_user_handler("user_handler_102");
    AuthHandler *auth_handler2 = create_auth_handler("auth_handler_103");
    printf("\r\n创建handler:\r\n %s %s %s", request_handler2->name, user_handler2->name, auth_handler2->name);

    // 将handler一次性链接为职责链，传入多个handler，第一个参数是数量
    Handler *handler2 = make_handler_chain_count(3, auth_handler2, request_handler2, user_handler2);
    printf("\r\n建立职责链:\r\n");
    Handler *handler_cur2 = (Handler *)handler2;
    while (handler_cur2 != NULL)
    {
        printf(" -> %s", handler_cur2->name);
        handler_cur2 = handler_cur2->next;
    }
    // 从指定的handler开始执行
    // auth_handler_check((Handler *)auth_handler2, 777);
    // 调用通用检查函数开始
    printf("\r\n开始检查:");
    bool result2 = check_handler_start(handler2, 777);
    printf("\r\n执行结果: %s \r\n", result2 ? "true" : "false");

    /* 释放内存 */
    free(handler_cur2);
    free(request_handler2);
    free(auth_handler2);
    free(user_handler2);

    /*** ========分割线============ ***/
    printf("\r\n=============\r\n");
    /* 再创建一组hanler */
    RequestHandler *request_handler3 = create_request_handler("request_handler_201");
    UserHandler *user_handler3 = create_user_handler("user_handler_202");
    AuthHandler *auth_handler3 = create_auth_handler("auth_handler_203");
    printf("\r\n创建handler:\r\n %s %s %s", request_handler3->name, user_handler3->name, auth_handler3->name);
    // 将handler一次性链接为职责链，传入多个handler，最后一个参数是NULL
    Handler *handler3 = make_handler_chain((Handler *)auth_handler3, user_handler3, request_handler3, NULL);
    Handler *handler_cur3 = (Handler *)handler3;
    printf("\r\n建立职责链:\r\n");
    while (handler_cur3 != NULL)
    {
        printf(" -> %s", handler_cur3->name);
        handler_cur3 = handler_cur3->next;
    }
    printf("\r\n开始检查:");
    bool result3 = check_handler_start(handler3, 167);
    printf("\r\n执行结果: %s \r\n", result3 ? "true" : "false");

    /* 释放内存 */
    free(handler_cur3);
    free(request_handler3);
    free(auth_handler3);
    free(user_handler3);

    return 0;
}

/**
jarry@jarrys-MacBook-Pro c % gcc ./test/test.c ./src/*.c
jarry@jarrys-MacBook-Pro c % ./a.out 
创建handler:
 request_handler_01 user_handler_02 auth_handler_03
建立职责链:
 -> request_handler_01 -> user_handler_02 -> auth_handler_03
开始检查:
 request_handler_check: [handler.name = request_handler_01 param = 666]
 user_handler_check: [handler.name = user_handler_02 param = 666]
 user_handler_check: error[ 666 % 3 ] == 0
执行结果: false 

=============

创建handler:
 request_handler_101 user_handler_102 auth_handler_103
建立职责链:
 -> auth_handler_103 -> request_handler_101 -> user_handler_102
开始检查:
 auth_handler_check: [handler.name = auth_handler_103 param = 777]
 request_handler_check: [handler.name = request_handler_101 param = 777]
 user_handler_check: [handler.name = user_handler_102 param = 777]
 user_handler_check: error[ 777 % 3 ] == 0
执行结果: false 

=============

创建handler:
 request_handler_201 user_handler_202 auth_handler_203
建立职责链:
 -> auth_handler_203 -> user_handler_202 -> request_handler_201
开始检查:
 auth_handler_check: [handler.name = auth_handler_203 param = 167]
 user_handler_check: [handler.name = user_handler_202 param = 167]
 request_handler_check: [handler.name = request_handler_201 param = 167]
执行结果: true 
 */