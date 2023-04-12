#include "../src/func.h"

int main(void)
{
  printf("test start:\r\n");
  /**
   * 解释器模式实现了一个表达式接口，该接口可以解释一个特定的上下文的变量和语句。
   * 也就是先定义上下文，然后定义变量，再使用表达式进行求值。相当可以构造一个简单的语法解析器。
   */

  int result1 = add_two(1, 2);
  printf("\r\n result1:[1 + 2 = %d]", result1);

  // 计算多个数字，第1个为数量，后面是待计算的数字
  int result2 = add_more(5, 1, 2, 3, 4, 5);
  printf("\r\n result2: [1 + 2 + 3 + 4 + 5 = %d]", result2);

  int result3 = add_and_subtract(3, 4, 5);
  printf("\r\n result3: [3 + 4 - 5 = %d]", result3);
  return 0;
}

/**
jarry@jarrys-MacBook-Pro c % gcc test/test.c src*.c
jarry@jarrys-MacBook-Pro c % ./a.out
test start:

 context_constructor() 构建执行上下文
 Context::add() [key=one, value=1]
 Context::add() [key=two, value=2]
 var_expression_constructor() [key=one]
 var_expression_constructor() [key=two]
 add_expression_constructor() [exp_one=one, exp_two=two]
 AddExpression::interpret() [exp_one=one, exp_two=two]
 VarExpression::interpret() [key=one, value=1]
 VarExpression::interpret() [key=two, value=2]
 result1:[1 + 2 = 3]
 context_constructor() 构建执行上下文
 Context::add() [key=key_1, value=1]
 Context::add() [key=key_2, value=2]
 Context::add() [key=key_3, value=3]
 Context::add() [key=key_4, value=4]
 Context::add() [key=key_5, value=5]
 var_expression_constructor() [key=key_1]
 var_expression_constructor() [key=key_2]
 add_expression_constructor() [exp_one=key_1, exp_two=key_2]
 var_expression_constructor() [key=key_3]
 add_expression_constructor() [exp_one=, exp_two=key_3]
 var_expression_constructor() [key=key_4]
 add_expression_constructor() [exp_one=, exp_two=key_4]
 var_expression_constructor() [key=key_5]
 add_expression_constructor() [exp_one=, exp_two=key_5]
 AddExpression::interpret() [exp_one=, exp_two=key_5]
 AddExpression::interpret() [exp_one=, exp_two=key_4]
 AddExpression::interpret() [exp_one=, exp_two=key_3]
 AddExpression::interpret() [exp_one=key_1, exp_two=key_2]
 VarExpression::interpret() [key=key_1, value=1]
 VarExpression::interpret() [key=key_2, value=2]
 VarExpression::interpret() [key=key_3, value=3]
 VarExpression::interpret() [key=key_4, value=4]
 VarExpression::interpret() [key=key_5, value=5]
 result2: [1 + 2 + 3 + 4 + 5 = 15]
 context_constructor() 构建执行上下文
 Context::add() [key=one, value=3]
 Context::add() [key=two, value=4]
 Context::add() [key=three, value=5]
 var_expression_constructor() [key=one]
 var_expression_constructor() [key=two]
 var_expression_constructor() [key=three]
 add_expression_constructor() [exp_one=one, exp_two=two]
 sub_expression_constructor() [exp_one=, exp_two=three]
 SubExpression::interpret() [exp_one=, exp_two=three]
 AddExpression::interpret() [exp_one=one, exp_two=two]
 VarExpression::interpret() [key=one, value=3]
 VarExpression::interpret() [key=two, value=4]
 VarExpression::interpret() [key=three, value=5]
 result3: [3 + 4 - 5 = 2]%  
 */