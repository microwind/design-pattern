# 【责任链设计模式详解】C/Java/JS/Go/Python/TS不同语言实现

# 简介
责任链模式（Chain of Responsibility Pattern）是一种行为型设计模式，也叫职责链模式、命令链模式。这种模式为请求创建了一个接收者对象的链，允许你将请求沿着处理者链进行发送，每个处理者均可对请求进行处理，或将其传递给链上的下个处理者。

当程序需要使用不同方式来处理多种类请求，且请求类型和顺序不可知，或者当必须按顺序执行多个处理时，可以使用责任链模式。或者如果所需处理及其顺序必须在运行时进行改变，也可以使用该模式。

# 作用
1. 避免请求发送者与接收者耦合在一起，客户只需要将请求发送到链上，而无须关心请求的处理细节和请求的传递。
2. 通过改变链内的成员或者调动它们的次序，允许动态地新增或者删除责任。

# 实现步骤
1. 创建一个抽象处理器类，用来供处理器继承。
2. 抽象处理器类可将各子类按任意组织为链式，以便调用。
3. 创建多个互不干涉的处理器，实现抽象类的next方法，以便不断执行链式检查。

# UML
<img src="../docs/uml/chain-responsibility.png">


# Java代码

## 抽象事件处理类
```java
// AbstractHandler.java 所有处理变成链式，可以互动干涉，动态组合
public abstract class AbstractHandler {
   // 形成职责链
   private AbstractHandler next;

   // 创建调用链，传入多个handler，按顺序形成链，返回第一个handler
   public static AbstractHandler link(AbstractHandler first, AbstractHandler... chain) {
      AbstractHandler head = first;
      for (AbstractHandler handler : chain) {
         head.next = handler;
         head = handler;
      }
      return first;
   }

   // 子类需要实现的检查方法
   public abstract boolean check(int uid);

   // 继续下一个检查
   protected boolean checkNext(int uid) {
      if (next == null) {
         return true;
      }
      return next.check(uid);
   }
}
```

## 不同事件，可以多个，相互独立
```java
// AuthHandler.java 权限检查类
public class AuthHandler extends AbstractHandler {
    // 如果检查不通过则返回失败，否则继续下一个检查
    public boolean check(int uid) {
      System.out.println(this.getClass().getName() + "::check() [uid = " + uid + "]");
      if (uid % 2 == 0) {
          return false;
      }
      return checkNext(uid);
  }
}
```

```java
// RequestHandler.java 请求是否安全合法检查
public class RequestHandler extends AbstractHandler {
    // 如果检查不通过则返回失败，否则继续下一个检查
    public boolean check(int uid) {
      System.out.println(this.getClass().getName() + "::check() [uid = " + uid + "]");
      if (uid % 1 != 0) {
          return false;
      }
      return checkNext(uid);
  }
}
```

```java
// UserHandler.java 用户基本信息检查类
public class UserHandler extends AbstractHandler {
    // 如果检查不通过则返回失败，否则继续下一个检查
    public boolean check(int uid) {
        System.out.println(this.getClass().getName() + "::check() [uid = " + uid + "]");
        if (uid % 3 == 0) {
            return false;
        }
        return checkNext(uid);
    }
}
```

## 测试调用
```java
    /**
     * 责任链模式核心是打造一个调用处理链，每个处理链都实现抽象类的next方法，从而可以任意组织各种检查行为。
     * 通过改变链内的成员或者调动它们的顺序，允许动态地新增或者删除职责，从而实现按需组织。
     */

    // 可以任意组织职责链，先后顺序根据需要来
    AbstractHandler handler1 = AbstractHandler.link(
        new RequestHandler(),
        new UserHandler(),
        new AuthHandler());

    System.out.println("handler1.check(1001)开始");
    handler1.check(1001);
    System.out.println("handler1.check(1002)开始");
    handler1.check(1002);

    // 可以任意组织职责链，先后顺序根据需要来
    AbstractHandler handler2 = AbstractHandler.link(
        new AuthHandler(),
        new RequestHandler(),
        new UserHandler());

    System.out.println("handler2.check(1001)开始");
    handler2.check(1001);
    System.out.println("handler2.check(1002)开始");
    handler2.check(1002);
```

# C语言代码
## func.h 头文件函数
```c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 定义通用handler
typedef struct Handler
{
    char name[50];
    // handler链指针
    struct Handler *next;
    // 结构体内部的check_handler函数，供各handler独立实现
    bool (*check_handler)(struct Handler *, int);
} Handler;

// 创建handler调用链，逐个创建
Handler *link_handler(Handler *handler, Handler *next);

// 两种创建链式hander的方式，功能相同，可以传入多个参数
Handler *make_handler_chain_count(int lenght, ...);
Handler *make_handler_chain(Handler *handler, ...);

// 检查handler通用函数
bool check_handler_start(Handler *handler, int param);


// 定义权限检查handler
typedef struct AuthHandler
{
    char name[50];
    Handler *next;
    bool (*check_handler)(struct Handler *, int);
} AuthHandler;

// 创建AuthHandler
AuthHandler *create_auth_handler(char *name);

// 定义请求检查handler
typedef struct RequestHandler
{
    char name[50];
    Handler *next;
    bool (*check_handler)(struct Handler *, int);
} RequestHandler;

// 创建RequestHandler
RequestHandler *create_request_handler(char *name);

// 定义用户检查handler
typedef struct UserHandler
{
    char name[50];
    Handler *next;
    bool (*check_handler)(struct Handler *, int);
} UserHandler;

// 创建UserHandler
UserHandler *create_user_handler(char *name);
```

## 统一事件处理
```c
// handler.c 基础事件
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
```

## 不同事件，可以多个，相互独立
```c
// auth_handler.c 权限检查类
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
```

```c
// request_handler.c 请求是否安全合法检查
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "func.h"

/* RequestHandler check函数实现 */
bool request_handler_check(Handler *handler, int param)
{
  printf("\r\n request_handler_check: [handler.name = %s param = %d]", handler->name, param);
  RequestHandler *request_handler = (RequestHandler *)handler;
  // 这里是判断条件，如果出错则终止调用链，返回false
  if (param % 5 == 0)
  {
    printf("\r\n request_handler_check: error[ %d %s 5 ] == 0", param, "%");
    return false;
  }
  // 通过next调用下一步检查
  if (handler->next != NULL)
  {
    return request_handler->next->check_handler(handler->next, param);
  }
  return true;
}

/* 创建具体处理器的函数 */
RequestHandler *create_request_handler(char *name)
{
  RequestHandler *handler = (RequestHandler *)malloc(sizeof(RequestHandler));
  strncpy(handler->name, name, 50);
  // 将handler的check_handler函数赋值为指定函数，便于检查处理
  handler->check_handler = &request_handler_check;
  handler->next = NULL;
  return handler;
}
```

```c
// user_handler.c 用户基本信息检查类
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "func.h"

/* UserHandler check_handler函数实现 */
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
    return user_handler->next->check_handler(handler->next, param);
  }
  return true;
}

/* 创建具体处理器的函数 */
UserHandler *create_user_handler(char *name)
{
  UserHandler *handler = (UserHandler *)malloc(sizeof(UserHandler));
  strncpy(handler->name, name, 50);
  // 将handler的check_handler函数赋值为指定函数，便于检查处理
  handler->check_handler = &user_handler_check;
  handler->next = NULL;
  return handler;
}
```

## 测试调用
```c
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
    bool result1 = request_handler->check_handler((Handler *)request_handler, 666);
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
```

## 更多语言版本
不同语言实现设计模式：[https://github.com/microwind/design-pattern](https://github.com/microwind/design-pattern)