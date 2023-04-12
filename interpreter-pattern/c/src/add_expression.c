#include "func.h"

// 具体表达式，实现了抽象表达式接口
// 覆盖表达式，执行context对象
int add_expression_interpret(Expression *exp, Context *context)
{
  printf("\r\n AddExpression::interpret() [exp_one=%s, exp_two=%s]", exp->exp_one->key, exp->exp_two->key);
  int one_result = exp->exp_one->interpret(exp->exp_one, context);
  int two_result = exp->exp_two->interpret(exp->exp_two, context);
  return one_result + two_result;
}

AddExpression *add_expression_constructor(Expression *exp_one, Expression *exp_two)
{
  printf("\r\n add_expression_constructor() [exp_one=%s, exp_two=%s]", exp_one->key, exp_two->key);
  Expression *exp = (Expression *)malloc(sizeof(Expression));
  exp->interpret = &add_expression_interpret;
  exp->exp_one = exp_one;
  exp->exp_two = exp_two;
  AddExpression *add_expression = (AddExpression *)exp;
  return add_expression;
}