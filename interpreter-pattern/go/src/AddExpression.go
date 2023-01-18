package src

import "fmt"

// 具体表达式，实现了抽象表达式接口
type AddExpression struct {
  exprOne Expression
  exprTwo Expression
}

func (a *AddExpression) Init(exprOne Expression, exprTwo Expression) {
  a.exprOne = exprOne
  a.exprTwo = exprTwo
}

// 覆盖表达式，执行context对象
func (a *AddExpression) Interpret(context Context) int {
  fmt.Println("AddExpression::interpret() [context = Context]")
  return a.exprOne.Interpret(context) + a.exprTwo.Interpret(context)
}
