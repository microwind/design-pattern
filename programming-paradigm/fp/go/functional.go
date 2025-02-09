package main

import "fmt"

// 纯函数：不依赖于外部状态，且无副作用
// 纯函数接收参数并返回结果，不修改任何外部状态
func add(a, b int) int {
  return a + b
}

// 高阶函数：接收函数作为参数或者返回一个函数
// 下面的 functionWithFunc 函数接收一个函数作为参数
func functionWithFunc(fn func(int, int) int, x, y int) int {
  return fn(x, y) // 执行传入的函数并返回结果
}

// 匿名函数：没有名称的函数，可以直接在代码中传递和调用
func main() {
  // 1. 纯函数示例
  a, b := 5, 3
  fmt.Printf("The sum of %d and %d is: %d\n", a, b, add(a, b)) // 调用纯函数

  // 2. 高阶函数示例
  sum := functionWithFunc(add, a, b) // 将 add 函数传入作为高阶函数参数
  fmt.Printf("The sum calculated by high-order function is: %d\n", sum)

  // 3. 匿名函数示例：没有命名的函数，直接在代码块内定义
  result := func(x, y int) int {
    return x * y
  }(a, b) // 调用匿名函数，计算乘积

  fmt.Printf("The product of %d and %d is: %d\n", a, b, result)

  // 4. 函数式编程的链式调用：通过匿名函数实现链式调用
  resultChain := func(a int) int {
    return a + 10
  }(5)

  resultChain = func(a int) int {
    return a * 2
  }(resultChain)

  fmt.Printf("Chained result: %d\n", resultChain)
}

/*
jarry@MacBook-Pro go % go run functional.go
The sum of 5 and 3 is: 8
The sum calculated by high-order function is: 8
The product of 5 and 3 is: 15
Chained result: 30
*/
