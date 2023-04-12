#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// 构建可执行环境上下文
typedef struct Context
{
    char **keys;
    int *values;
    int length;
    void (*add)(struct Context *, char *key, int value);
    int (*get)(struct Context *, char *key);
} Context;
Context *context_constructor();

// 抽象表达式接口，根据业务场景规范表达式
typedef struct Expression
{
    char name[50];
    char key[50];
    struct Expression *exp_one;
    struct Expression *exp_two;
    void (*set_key)(struct Expression *, char *);
    int (*interpret)(struct Expression *, Context *);
} Expression;

// 具体表达式，实现了抽象表达式接口
typedef struct AddExpression
{
    char name[50];
    char key[50];
    struct Expression *exp_one;
    struct Expression *exp_two;
    void (*set_key)(struct AddExpression *, char *);
    int (*interpret)(struct AddExpression *, Context *);
} AddExpression;
AddExpression *add_expression_constructor(Expression *exp_one, Expression *exp_two);

// 具体表达式，实现了抽象表达式接口
typedef struct SubtractExpression
{
    char name[50];
    char key[50];
    struct Expression *exp_one;
    struct Expression *exp_two;
    void (*set_key)(struct SubtractExpression *, char *);
    int (*interpret)(struct SubtractExpression *, Context *);
} SubtractExpression;
SubtractExpression *subtract_expression_constructor(Expression *exp_one, Expression *exp_two);

// 具体表达式，实现了抽象表达式接口
typedef struct VarExpression
{
    char name[50];
    char key[50];
    struct Expression *exp_one;
    struct Expression *exp_two;
    void (*set_key)(struct VarExpression *, char *);
    int (*interpret)(struct VarExpression *, Context *);
} VarExpression;
VarExpression *var_expression_constructor(char *key);

// application function list
// 将两个数值相加
int add_two(int one, int two);
// 将多个数字相加，第1个为数量，后面可以传入多个数字
int add_more(int count, ...);
// 计算前两个数相加，再减去后一个数的计算例子
int add_and_subtract(int one, int two, int three);