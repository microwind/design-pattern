package src

import "fmt"

// 具体表达式，实现了抽象表达式接口
type SubtractExpression struct {
  exprOne Expression
  exprTwo Expression
}

func (s *SubtractExpression) Init(exprOne Expression, exprTwo Expression) {
  s.exprOne = exprOne
  s.exprTwo = exprTwo
}

// 覆盖表达式，执行context对象
func (s *SubtractExpression) Interpret(context Context) int {
  fmt.Println("SubtractExpression::Interpret() [context = Context]")
  return s.exprOne.Interpret(context) + s.exprTwo.Interpret(context)
}
