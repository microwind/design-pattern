#include "func.h"

// 覆盖表达式，执行context对象
int subtract_expression_interpret(Expression *exp, Context *context)
{
  printf("\r\n SubExpression::interpret() [exp_one=%s, exp_two=%s]", exp->exp_one->key, exp->exp_two->key);
  int one_result = exp->exp_one->interpret(exp->exp_one, context);
  int two_result = exp->exp_two->interpret(exp->exp_two, context);
  return one_result - two_result;
}

SubtractExpression *subtract_expression_constructor(Expression *exp_one, Expression *exp_two)
{
  printf("\r\n sub_expression_constructor() [exp_one=%s, exp_two=%s]", exp_one->key, exp_two->key);
  Expression *exp = (Expression *)malloc(sizeof(Expression));
  exp->interpret = &subtract_expression_interpret;
  exp->exp_one = exp_one;
  exp->exp_two = exp_two;
  SubtractExpression *sub_expression = (SubtractExpression *)exp;
  return sub_expression;
}