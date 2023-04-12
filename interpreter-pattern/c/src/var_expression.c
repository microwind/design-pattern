#include "func.h"

// 覆盖表达式，根据key获取变量
int var_expression_interpret(Expression *exp, Context *context)
{
  int value = context->get(context, exp->key);
  printf("\r\n VarExpression::interpret() [key=%s, value=%d]", exp->key, value);
  return value;
}

void set_key(Expression *exp, char *key)
{
  strncpy(exp->key, key, 50);
}

VarExpression *var_expression_constructor(char *key)
{
  printf("\r\n var_expression_constructor() [key=%s]", key);
  Expression *exp = (Expression *)malloc(sizeof(Expression));
  strncpy(exp->key, key, 50);
  exp->interpret = &var_expression_interpret;
  exp->set_key = &set_key;
  VarExpression *var_expression = (VarExpression *)exp;
  return var_expression;
}