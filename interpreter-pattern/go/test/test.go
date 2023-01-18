package main

import (
  "fmt"

  "../src"
)

// main包下的main入口方法
func main() {
  fmt.Println("test start:")
  /**
   * 解释器模式实现了一个表达式接口，该接口可以解释一个特定的上下文的变量和语句。
   * 也就是先定义上下文，然后定义变量，再使用表达式进行求值。相当可以构造一个简单的语法解析器。
   */

  var application = &src.Application{}
  var result1 = application.AddTwo(1, 2)
  fmt.Println("result1: ", result1)

  var result2 = application.AddMore(1, 2, 3, 4, 5)
  fmt.Println("result2: ", result2)

  var result3 = application.AddAndSubtract(3, 4, 5)
  fmt.Println("result3: ", result3)
}

/**
jarry@jarrys-MacBook-Pro go % go build src/*.go
jarry@jarrys-MacBook-Pro go % go run test/test.go
test start:
AddExpression::interpret() [context = Context]
result1:  3
AddExpression::interpret() [context = Context]
AddExpression::interpret() [context = Context]
AddExpression::interpret() [context = Context]
AddExpression::interpret() [context = Context]
result2:  15
SubtractExpression::Interpret() [context = Context]
AddExpression::interpret() [context = Context]
result3:  12
*/
