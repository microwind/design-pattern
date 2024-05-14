package main

import "fmt"

// 定义父类 A
type A struct{}

// A 类的 show 方法
func (a A) show(obj interface{}) string {
  switch obj.(type) {
  // case B:
  //   return "A and B"
  case D:
    return "A and D"
  default:
    return "A and A"
  }
}

// 定义子类 B，继承自 A
type B struct{ A }

// B 类的 show 方法
func (b B) show(obj interface{}) string {
  switch obj.(type) {
  case B:
    return "B and B"
  case A:
    return "B and A"
  default:
    return b.A.show(obj)
  }
}

// 定义子类 C，继承自 B
type C struct{ B }

// 定义子类 D，继承自 B
type D struct{ B }

func main() {
  a := A{}
  ab := B{}
  b := B{}
  c := C{}
  d := D{}

  fmt.Println("1--" + a.show(b))   // 输出：A and A
  fmt.Println("2--" + a.show(c))   // 输出：A and A
  fmt.Println("3--" + a.show(d))   // 输出：A and D
  fmt.Println("4--" + ab.show(b))  // 输出：B and B
  fmt.Println("5--" + ab.show(c))  // 输出：A and A
  fmt.Println("6--" + ab.show(d))  // 输出：A and D
  fmt.Println("7--" + b.show(b))   // 输出：B and B
  fmt.Println("8--" + b.show(c))   // 输出：A and A
  fmt.Println("9--" + b.show(d))   // 输出：A and D
  fmt.Println("10--" + ab.show(a)) // 输出：B and A
}
