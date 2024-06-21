package main

import "fmt"

// Base 接口定义
type Base interface {
  Show(base Base) string
}

// A 类型，当做父类，实现Base接口
type A struct{}

// B 类型
type B struct {
  A // 嵌入 A 类型，实现继承
}

// C 类型
type C struct {
  B // 嵌入 B 类型，实现继承
}

// D 类型
type D struct {
  B // 嵌入 B 类型，实现继承
}

// A的Show 方法实现，没有重载，根据类型判断
func (a A) Show(base Base) string {
  switch base.(type) {
  case *D:
    return "A and D"
  case *A:
    return "A and A"
  default:
    return "A and default"
  }
}

// B的Show 方法实现，没有重载，根据类型判断
func (b B) Show(base Base) string {
  switch base.(type) {
  case *B:
    return "B and B"
  case *A:
    return "B and A"
  default:
    return "B and default"
  }
}

func main() {
  //直接声明
  a := &A{}

  // A 不是接口，不能用父类定义子类
  // var ab A = &B{}

  // 用Base接口声明子类
  var ab Base = &B{}

  b := &B{}
  c := &C{}
  var d Base = &D{}

  // 1) A and A。A类型，调用时传递b.A。
  fmt.Println("1) " + a.Show(&b.A))

  // 2) A and A。A类型，传递c.B.A。
  fmt.Println("2) " + a.Show(&c.B.A))

  // 3) A and D。A类型，进入D类型判断。
  fmt.Println("3) " + a.Show(d))

  // 4) B and A。ab是Base接口，B类型，传递b.A。
  fmt.Println("4) " + ab.Show(&b.A))

  // 5) B and A。ab是Base接口，B类型，传递c.B.A。
  fmt.Println("5) " + ab.Show(&c.B.A))

  // 6) B and default。ab是Base接口，B类型，B.show没有D打印。
  fmt.Println("6) " + ab.Show(d))

  // 7) B and B。B类型，B.show有B分支打印。
  fmt.Println("7) " + b.Show(b))

  // 8) B and B。B类型，传递c.B。
  fmt.Println("8) " + b.Show(&c.B))

  // 9) B and default。B类型，B.Show没有D分支打印。
  fmt.Println("9) " + b.Show(d))

  // 10) B and A。B类型，B.Show分支打印A。
  fmt.Println("10) " + ab.Show(a))
}

/**
jarry@jarrys-MacBook-Pro polymorphism % go run PolymorphismSimple.go
1) A and A
2) A and A
3) A and D
4) B and A
5) B and A
6) B and default
7) B and B
8) B and B
9) B and default
10) B and A
*/
