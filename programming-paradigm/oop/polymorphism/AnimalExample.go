/*Go实现多态的例子 */

package main

import (
  "fmt"
)

// 定义一个Animal接口
type Animal interface {
  MakeSound()
}

// 定义一个 Dog 类型
type Dog struct{}

// 实现 Animal 接口的 MakeSound 方法
func (d Dog) MakeSound() {
  fmt.Println("Dog barks")
}

// 定义一个 Cat 类型
type Cat struct{}

// 实现 Animal 接口的 MakeSound 方法
func (c Cat) MakeSound() {
  fmt.Println("Cat meows")
}

// Cat自有方法
func (c *Cat) Meow() {
  fmt.Println("Cat is meowing...")
}

// 定义一个 Zoo 类型，用于管理动物
type Zoo struct{}

// 定义一个方法，让动物发出声音
func (z Zoo) LetAnimalMakeSound(a Animal) {
  a.MakeSound()
}

type Bird struct{}

// 实现 Animal 接口的 MakeSound 方法
func (b Bird) MakeSound() {
  fmt.Println("Bird chirps")
}

func main() {
  zoo := Zoo{}
  myDog := Dog{}
  // 接口断言。用接口来声明结构体，类似父类声明子类
  var myCat Animal = &Cat{}
  // 类型断言。将接口转为子类类型，打印自有方法
  (myCat.(*Cat)).Meow()
  myBird := Bird{}

  // 使用多态性，通过接口类型处理不同的具体类型
  zoo.LetAnimalMakeSound(myDog)  // 输出 "Dog barks"
  zoo.LetAnimalMakeSound(myCat)  // 输出 "Cat meows"
  zoo.LetAnimalMakeSound(myBird) // 输出 "Bird chirps"
}
