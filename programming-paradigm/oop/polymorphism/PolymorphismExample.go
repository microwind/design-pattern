/*
多态即同一个行为具有多个不同表现形式或形态的能力。
表现形式为，子类重写父类方法，实现类实现接口方法，子类重写抽象类方法等。

多态性是指同一个方法调用可以根据对象的实际类型而有不同的行为。
当使用父类的引用变量来声明子类对象时，调用方法时将根据子类的类型而变化，这就是多态性。

多态三个必要条件：继承、重写、父类引用指向子类对象。
方法重写：重写是通过子类提供的方法来覆盖父类中的方法。子类可以提供不同的方法实现，但方法名与父类中的方法一致。
动态绑定：对于方法重写，方法的选择是在运行时（动态）绑定的而不是编译时（静态）确定的。编译器不知道对象的实际类型，只有在运行时才能够确定。

本示例：
- 多态性的应用：
使用一个Animal类型的数组来存储不同类型的动物对象，包括Dog、Cat和Pig。
在遍历数组时，调用Animal类的eat()方法。根据多态的特性，实际上调用的是各子类的eat()方法，展示了不同对象的不同行为。

- 方法重载的应用：
在Animal类中，我们定义了两个版本的eat()方法，它们具有相同的名称但不同的参数列表。
在调用eat()方法时可以选择不同的参数，从而实现不同的行为。例如，我们可以调用animal.eat("some food")，这会调用重载形式的eat()方法。

- 方法重写的应用：
在Dog、Cat和Pig类中，我们重写了Animal类的eat()方法，以提供各自特定的行为。
这允许我们根据对象的实际类型来调用适当的方法，而不是始终调用基类的方法。例如，即使数组中存储的是Dog对象，但在遍历时实际上调用的是Dog类重写后的eat()方法。


- 好处：
  - 灵活性和可扩展性：我们可以轻松地向程序中添加新的动物类型，而不需要修改现有的代码。只需创建新的派生类并重写父类的方法即可。
  - 代码重用：通过将对象视为其超类型，我们可以在程序中重用相同的代码。例如，在遍历数组时，我们使用了相同的方式处理不同类型的动物对象。
  - 简化代码：多态性、方法重载和方法重写使得我们的代码更加简洁和清晰，因为我们不需要针对每种情况编写单独的代码，而是可以通过统一的方式处理不同的对象和行为。
*/

// Go语言没有class，可以通过struct或interface替代class。
// Go在多态上基本可以模拟出Java的效果来，Go可以实现重写，以及父类声明子类。

package main

import "fmt"

// Animal 接口
type Animal interface {
  Eat()
  EatFood(food string)
  GetName() string
}

// Animal 基类
type AnimalBase struct {
  Name string
}

// eat 方法
func (a *AnimalBase) Eat() {
  fmt.Println("Animal is eating...")
}

// EatFood 方法
func (a *AnimalBase) EatFood(food string) {
  fmt.Printf("Animal is eating %s...\n", food)
}

// GetName 方法
func (a *AnimalBase) GetName() string {
  return a.Name
}

// Dog 类
type Dog struct {
  AnimalBase
}

// eat 方法的重写
func (d *Dog) Eat() {
  fmt.Println("Dog is eating...")
}

// EatFood 方法的重写
func (d *Dog) EatFood(food string) {
  fmt.Printf("Dog is eating %s...\n", food)
}

// Bark 方法
func (d *Dog) Bark() {
  fmt.Println("Dog is barking...")
}

// Cat 类
type Cat struct {
  AnimalBase
}

// eat 方法的重写
func (c *Cat) Eat() {
  fmt.Println("Cat is eating...")
}

// EatFood 方法的重写
func (c *Cat) EatFood(food string) {
  fmt.Printf("Cat is eating %s...\n", food)
}

// Meow 方法
func (c *Cat) Meow() {
  fmt.Println("Cat is meowing...")
}

// Pig 类
type Pig struct {
  AnimalBase
}

// eat 方法的重写
func (p *Pig) Eat() {
  fmt.Println("Pig is eating...")
}

// EatFood 方法的重写
func (p *Pig) EatFood(food string) {
  fmt.Printf("Pig is eating %s...\n", food)
}

// Oink 方法
func (p *Pig) Oink() {
  fmt.Println("Pig is oinking...")
}

func main() {
  // 创建动物数组，类型为 Animal 接口，存储不同类型的动物对象
  animals := []Animal{
    &Dog{AnimalBase{Name: "Dog"}}, // 第一个元素是Dog对象
    &Cat{AnimalBase{Name: "Cat"}}, // 第二个元素是Cat对象
    &Pig{AnimalBase{Name: "Pig"}}, // 第三个元素是Pig对象
    &AnimalBase{Name: "Animal"},   // 第四个元素是Animal对象
  }

  // 遍历动物数组，调用各自的方法
  for _, animal := range animals {
    fmt.Println("name:", animal.GetName())
    // 调用对象的 Eat 方法
    animal.Eat()
    // 调用对象的 EatFood 方法的重载形式
    animal.EatFood("some food")
    // 类型断言，从而可以调用子类的自有方法
    switch a := animal.(type) {
    case *Dog:
      a.Bark() // 调用 Dog 类的 Bark 方法
    case *Cat:
      a.Meow() // 调用 Cat 类的 Meow 方法
    case *Pig:
      a.Oink() // 调用 Pig 类的 Oink 方法
    }
  }

  // 分割线
  fmt.Println("*** 分割线 ***")

  // 向上转型示例
  var dog Animal = &Dog{AnimalBase{Name: "Dog"}}
  var cat Animal = &Cat{AnimalBase{Name: "Cat"}}
  var pig Animal = &Pig{AnimalBase{Name: "Pig"}}

  // 多态示例
  dog.Eat()
  // 强转类型调用自有方法
  (dog.(*Dog)).Bark()

  cat.Eat()
  (cat.(*Cat)).Meow()

  pig.Eat()
  (pig.(*Pig)).Oink()
}

/**
jarry@jarrys-MacBook-Pro polymorphism % go run PolymorphismExample.go
name: Dog
Dog is eating...
Dog is eating some food...
Dog is barking...
name: Cat
Cat is eating...
Cat is eating some food...
Cat is meowing...
name: Pig
Pig is eating...
Pig is eating some food...
Pig is oinking...
name: Animal
Animal is eating...
Animal is eating some food...
*** 分割线 ***
Dog is eating...
Dog is barking...
Cat is eating...
Cat is meowing...
Pig is eating...
Pig is oinking...
/*