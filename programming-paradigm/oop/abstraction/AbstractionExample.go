/*
抽象是一种简化复杂系统的方法，在更高层次上进行建模。抽象包括两个方面，一是过程抽象，二是数据抽象。
抽象类：Shape是一个抽象类，它包含一个抽象方法calculateArea()。抽象类通过abstract关键字进行声明，不能被实例化。
抽象类（Abstract Class）和接口（Interface）是不同的机制，用于实现多态性和代码组织。两者都可以用于定义抽象方法，但又有区别。
抽象类用于表示一种"is-a"关系，而接口用于表示一种"can-do"关系。
Go没有抽象类，可以使用interface替代。
Go没有class，可以使用struct替代。
*/
package main

import (
  "fmt"
  "math"
)

// 接口：形状
type Shape interface {
  // 计算形状的面积
  calculateArea() float64
}

// 结构体：圆形
type Circle struct {
  radius float64 // 圆的半径
}

// 实现接口方法：计算圆的面积
func (c Circle) calculateArea() float64 {
  return math.Pi * c.radius * c.radius
}

// 结构体：矩形
type Rectangle struct {
  width  float64 // 矩形的宽度
  height float64 // 矩形的高度
}

// 实现接口方法：计算矩形的面积
func (r Rectangle) calculateArea() float64 {
  return r.width * r.height
}

// 结构体：三角形
type Triangle struct {
  base   float64 // 三角形的底边长
  height float64 // 三角形的高
}

// 实现接口方法：计算三角形的面积
func (t Triangle) calculateArea() float64 {
  return 0.5 * t.base * t.height
}

func main() {
  // 创建圆形对象并计算面积
  circle := Circle{radius: 5}
  circleArea := circle.calculateArea()
  fmt.Println("圆形面积:", circleArea) // 输出：圆形面积: 78.53981633974483

  // 创建矩形对象并计算面积
  rectangle := Rectangle{width: 4, height: 6}
  rectangleArea := rectangle.calculateArea()
  fmt.Println("矩形面积:", rectangleArea) // 输出：矩形面积: 24

  // 创建三角形对象并计算面积
  triangle := Triangle{base: 3, height: 4}
  triangleArea := triangle.calculateArea()
  fmt.Println("三角形面积:", triangleArea) // 输出：三角形面积: 6
}

/*
jarry@jarrys-MacBook-Pro abstraction % go run AbstractionExample.go
圆形面积: 78.53981633974483
矩形面积: 24
三角形面积: 6
*/
