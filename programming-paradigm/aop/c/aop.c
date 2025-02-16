#include <stdio.h>
#include <stdarg.h>
#include <string.h>

/*
AOP（面向切面编程）是一种编程范式，通过分离横切关注点来提高模块性。
横切关注点是跨越应用程序多个部分的功能，比如日志记录、事务管理等。
在C语言中，没有像Java那样的动态代理机制，可以通过函数指针和回调函数来实现类似AOP的效果。
也就是在目标函数之外包装一层，从而执行时，从包装器开始。
*/

// 1. 定义通用函数指针类型
typedef void (*GenericFunction)(); // 通用函数指针类型

// 2. 定义参数类型枚举
typedef enum
{
  ARG_TYPE_STRING, // 字符串类型参数
  ARG_TYPE_INT,    // 整数类型参数
  ARG_TYPE_FLOAT,  // 浮点数类型参数
  ARG_TYPE_DOUBLE, // 双精度浮点数类型参数
  ARG_TYPE_NONE    // 无参数
} ArgType;

// 3. 定义切面函数
void before(const char *functionName)
{
  printf("前置通知: 准备执行函数 %s\n", functionName);
}

void after(const char *functionName)
{
  printf("后置通知: 函数 %s 执行完成\n", functionName);
}

// 4. 定义通用AOP包装函数
void aopWrapper(GenericFunction func, ArgType argType, const char *functionName, ...)
{
  va_list args;
  va_start(args, functionName); // 初始化可变参数列表

  before(functionName); // 前置通知

  // 根据参数类型调用目标函数
  switch (argType)
  {
  case ARG_TYPE_STRING:
  {
    void (*targetFunc)(const char *) = (void (*)(const char *))func;
    const char *arg = va_arg(args, const char *);
    targetFunc(arg);
    break;
  }
  case ARG_TYPE_INT:
  {
    void (*targetFunc)(int) = (void (*)(int))func;
    int arg = va_arg(args, int);
    targetFunc(arg);
    break;
  }
  case ARG_TYPE_FLOAT:
  {
    void (*targetFunc)(float) = (void (*)(float))func;
    float arg = (float)va_arg(args, double); // float 会被提升为 double
    targetFunc(arg);
    break;
  }
  case ARG_TYPE_DOUBLE:
  {
    void (*targetFunc)(double) = (void (*)(double))func;
    double arg = va_arg(args, double);
    targetFunc(arg);
    break;
  }
  case ARG_TYPE_NONE:
  {
    void (*targetFunc)() = (void (*)())func;
    targetFunc();
    break;
  }
  default:
    printf("不支持的参数类型\n");
  }

  after(functionName); // 后置通知

  va_end(args); // 清理可变参数列表
}

// 5. 实现业务函数
void addUser(const char *username)
{
  printf("添加用户: %s\n", username);
}

void deleteUser(int userId)
{
  printf("删除用户: %d\n", userId);
}

void updateUserScore(float score)
{
  printf("更新用户分数: %.2f\n", score);
}

void printSystemInfo()
{
  printf("系统信息: 这是一个示例系统\n");
}

// 6. 测试AOP
int main()
{
  const char *username = "张三";
  int userId = 101;
  float score = 95.5;

  // 通过通用AOP包装函数调用业务函数
  // 调用 addUser 时，传入目标函数、参数类型和函数名
  aopWrapper((GenericFunction)addUser, ARG_TYPE_STRING, "addUser", username);

  // 调用 deleteUser 时，传入目标函数、参数类型和函数名
  aopWrapper((GenericFunction)deleteUser, ARG_TYPE_INT, "deleteUser", userId);

  // 调用 updateUserScore 时，传入目标函数、参数类型和函数名
  aopWrapper((GenericFunction)updateUserScore, ARG_TYPE_FLOAT, "updateUserScore", score);

  // 调用 printSystemInfo 时，传入目标函数、参数类型和函数名
  aopWrapper((GenericFunction)printSystemInfo, ARG_TYPE_NONE, "printSystemInfo");

  return 0;
}

/**
jarry@Mac c % gcc aop.c
jarry@Mac c % ./a.out
前置通知: 准备执行函数 addUser
添加用户: 张三
后置通知: 函数 addUser 执行完成
前置通知: 准备执行函数 deleteUser
删除用户: 101
后置通知: 函数 deleteUser 执行完成
前置通知: 准备执行函数 updateUserScore
更新用户分数: 95.50
后置通知: 函数 updateUserScore 执行完成
前置通知: 准备执行函数 printSystemInfo
系统信息: 这是一个示例系统
后置通知: 函数 printSystemInfo 执行完成
 */