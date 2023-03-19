#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 定义通用handler
typedef struct Handler {
    char name[50];
    // handler链指针
    struct Handler* next;
    // 结构体内部的check_next函数，供各handler独立实现
    bool (*check_next)(struct Handler*, int);
} Handler;

// 创建handler调用链
Handler *link_handler(Handler *handler, Handler *next);

// 检查handler通用函数
bool check_handler_start(Handler *handler, int param);

Handler *make_handler_chain_count(int lenght, ...);
Handler *make_handler_chain(Handler *handler, ...);

// 定义权限检查handler
typedef struct AuthHandler
{
    char name[50];
    Handler *next;
    bool (*check_next)(struct Handler*, int);
} AuthHandler;

// 创建AuthHandler
AuthHandler* create_auth_handler(char *name);
bool user_handler_check(Handler *handler, int param);

// 定义请求检查handler
typedef struct RequestHandler
{
    char name[50];
    Handler *next;
    bool (*check_next)(struct Handler*, int);
} RequestHandler;
bool auth_handler_check(Handler *handler, int param);

// 创建RequestHandler
RequestHandler *create_request_handler(char *name);
bool request_handler_check(Handler *handler, int param);

// 定义用户检查handler
typedef struct UserHandler
{
    char name[50];
    Handler *next;
    bool (*check_next)(struct Handler*, int);
} UserHandler;

// 创建UserHandler
UserHandler *create_user_handler(char *name);