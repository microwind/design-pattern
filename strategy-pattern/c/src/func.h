#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Context Context;
typedef struct Strategy Strategy;
typedef struct StrategyA StrategyA;
typedef struct StrategyB StrategyB;
typedef struct StrategyC StrategyC;

// 定义策略执行对象context
typedef struct Context
{
    char name[50];
    Strategy *strategy;
    void (*run)(struct Context *context);
    void (*set_strategy)(Context *context, Strategy *strategy);
} Context;
Context *context_constructor(char *name);

// 定义具体执行对象，调用依赖Context
typedef struct ContextCat
{
    char name[50];
    Strategy *strategy;
    void (*run)(struct ContextCat *context);
    void (*set_strategy)(struct ContextCat *context, Strategy *strategy);
} ContextCat;
ContextCat *context_cat_constructor(char *name);


// 定义具体执行对象，调用依赖Context
typedef struct ContextDog
{
    char name[50];
    Strategy *strategy;
    void (*run)(struct ContextDog *context);
    void (*set_strategy)(struct ContextDog *context, Strategy *strategy);
} ContextDog;
ContextDog *context_dog_constructor(char *name);

// 定义一个策略接口，注意go语言数据类型即接口
typedef struct Strategy
{
    char name[50];
    void (*run)(Strategy *strategy);
} Strategy;
Strategy *strategy_constructor(char *name);

// 定义策略A
typedef struct StrategyA
{
    char name[50];
    void (*run)(StrategyA *strategy);
} StrategyA;
StrategyA *strategy_a_constructor(char *name);


// 定义策略B
typedef struct StrategyB
{
    char name[50];
    void (*run)(StrategyB *strategy);
} StrategyB;
StrategyB *strategy_b_constructor(char *name);


// 定义策略C
typedef struct StrategyC
{
    char name[50];
    void (*run)(StrategyC *strategy);
} StrategyC;
StrategyC *strategy_c_constructor(char *name);
