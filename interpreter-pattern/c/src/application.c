#include "func.h"
#include <stdarg.h>

/*
 * 解释器模式先构建执行上下文Context，然后构建一个最终的获取值的表达式VarExpression，这就构成了含上下文和变量-值的基本环境。
 * 再将基本环境放到工具表达式里AddExpression或SubtractExpreesion进行计算，最终得到结果。
 */

// 将int转str的简单实现，未处理越界等情况
char *itoa(int num)
{
  char *str = (char *)malloc(50 * sizeof(char));
  int sign = num;

  if (num < 0)
  {
    num = -num;
  }

  int i = 0;
  do
  { // 生成数字
    str[i++] = num % 10 + '0';
  } while ((num /= 10) > 0);

  // 处理负数
  if (sign < 0)
  {
    str[i++] = '-';
  }

  str[i] = '\0';
  // 翻转字符串
  for (int j = 0, k = i - 1; j < k; j++, k--)
  {
    char temp = str[j];
    str[j] = str[k];
    str[k] = temp;
  }
  return str;
}

// 构建两个数相加的例子
int add_two(int one, int two)
{
  // 构建执行上下文环境
  Context *context = context_constructor();
  context->add(context, "one", one);
  context->add(context, "two", two);

  // 构建表达式
  VarExpression *var_one = var_expression_constructor("one");
  Expression *var_two = (Expression *)var_expression_constructor("two");

  // 构建变量和多种不同表达式进行计算，使得计算就变得简单
  AddExpression *result = add_expression_constructor((Expression *)var_one, var_two);
  return result->interpret(result, context);
}

// 构建连加计算的例子，不定参数调用，第1参数是数量，后面是数字
int add_more(int count, ...)
{
  // 构建执行上下文环境
  Context *context = context_constructor();

  va_list args;
  va_start(args, count);
  for (int i = 0; i < count; i++)
  {
    int value = va_arg(args, int);
    // 构建执行环境，value直接作为key
    char *key_str = (char *)malloc(50 * sizeof(char));
    strcat(key_str, "key_");
    strcat(key_str, itoa(value));
    context->add(context, key_str, value);
  }
  va_end(args);

  // 先取出前两个作为计算基础
  // 构建执行环境，num直接作为key
  char key1_str[50] = "key_";
  strcat(key1_str, itoa(context->values[0]));
  VarExpression *var_one = var_expression_constructor(key1_str);
  char key2_str[50] = "key_";
  strcat(key2_str, itoa(context->values[1]));
  VarExpression *var_two = var_expression_constructor(key2_str);

  // 再构建表达式，先赋值前两个
  AddExpression *expression = add_expression_constructor((Expression *)var_one, (Expression *)var_two);
  // 如果只有两个数则直接返回计算结果
  if (count == 2)
  {
    return expression->interpret(expression, context);
  }

  // 如果数量超过两个则累加表达式再求值
  for (int i = 2; i < count; i++)
  {
    VarExpression *next_expression = var_expression_constructor(context->keys[i]);
    expression = add_expression_constructor((Expression *)expression, (Expression *)next_expression);
  }

  return expression->interpret(expression, context);
}

// 计算前两个数相加，再减去后一个数的计算例子
int add_and_subtract(int one, int two, int three)
{
  // 构建执行上下文环境，有3个可操作的域
  Context *context = context_constructor();
  context->add(context, "one", one);
  context->add(context, "two", two);
  context->add(context, "three", three);

  // 构建表达式，有3个变量
  VarExpression *var_one = var_expression_constructor("one");
  VarExpression *var_two = var_expression_constructor("two");
  VarExpression *var_three = var_expression_constructor("three");
  // 前两个用加法
  Expression *result = (Expression *)add_expression_constructor((Expression *)var_one, (Expression *)var_two);
  // 第3个用减法
  result = (Expression *)subtract_expression_constructor(result, (Expression *)var_three);
  return result->interpret(result, context);
}