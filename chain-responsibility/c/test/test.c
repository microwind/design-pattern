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

    // 测试链接情况
    Handler *handler = (Handler *)request_handler;
    printf("\r\n建立职责链:\r\n");
    while (handler != NULL)
    {
        printf(" -> %s", handler->name);
        handler = handler->next;
    }

    // 从任意handler开始检查
    printf("\r\ncheck_handler_start检查:");
    check_handler_start((Handler *)request_handler, 1001);

    // 直接从某个handler开始
    printf("\r\nrequest_handler_check检查:");
    request_handler_check((Handler *)request_handler, 1002);

    /*** ========分割线============ ***/

    /* 创建一组hanler */
    RequestHandler *request_handler2 = create_request_handler("request_handler_101");
    UserHandler *user_handler2 = create_user_handler("user_handler_102");
    AuthHandler *auth_handler2 = create_auth_handler("auth_handler_103");
    printf("\r\n创建handler:\r\n %s %s %s", request_handler2->name, user_handler2->name, auth_handler2->name);

    // 将handler一次性链接为职责链，传入多个handler
    Handler *handler2 = make_handler_chain_count(3, auth_handler2, request_handler2, user_handler2);
    // Handler *handler2 = make_handler_chain((Handler*)auth_handler2, request_handler2, user_handler2);
    // 测试链接情况
    Handler *handler0 = (Handler *)handler2;
    printf("\r\n建立职责链:\r\n");
    while (handler0 != NULL)
    {
        printf(" -> %s", handler0->name);
        handler0 = handler0->next;

    }
    auth_handler_check(handler2, 1003);
    check_handler_start(handler2, 1003);

    /* 释放内存 */
    free(request_handler);
    free(auth_handler);
    free(user_handler);

    return 0;
}

/**
jarry@jarrys-MacBook-Pro c % gcc ./test/test.c ./src/*.c
jarry@jarrys-MacBook-Pro c % ./a.out                    
创建handler:
 request_handler_01 user_handler_02 auth_handler_03
建立职责链:
 -> request_handler_01 -> user_handler_02 -> auth_handler_03
check_handler_start检查:
 request_handler_check: [handler.name = request_handler_01 param = 1001]
 user_handler_check: [handler.name = user_handler_02 param = 1001]
 auth_handler_check: [handler.name = auth_handler_03 param = 1001]
request_handler_check检查:
 request_handler_check: [handler.name = request_handler_01 param = 1002]
 user_handler_check: [handler.name = user_handler_02 param = 1002]
 user_handler_check: error[ 1002 % 3 ] == 0
创建handler:
 request_handler_101 user_handler_102 auth_handler_103
建立职责链:
 -> auth_handler_103 -> request_handler_101 -> user_handler_102
 auth_handler_check: [handler.name = auth_handler_103 param = 1003]
 request_handler_check: [handler.name = request_handler_101 param = 1003]
 user_handler_check: [handler.name = user_handler_102 param = 1003]
 auth_handler_check: [handler.name = auth_handler_103 param = 1003]
 request_handler_check: [handler.name = request_handler_101 param = 1003]
 user_handler_check: [handler.name = user_handler_102 param = 1003]% 

 */