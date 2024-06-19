# 什么是多态

面向对象程序设计有三要素：封装、继承、多态，封装、继承比较好理解，多态总让人含混不清，也不知道具体有什么作用，为什么要有多态。今天来详细分析下什么是多态，以及多态有哪些好处。多态是指同一行为作用于不同的对象时，可以表现出多种不同的形式和结果来。

以方法为例，当子类继承父类并覆盖其方法后，若使用父类类型的引用来指向子类对象并调用该方法，那么实际执行的是子类中的方法，而不是父类中的方法。

这种基于对象实际类型而非声明类型来确定执行哪个方法的行为，就是多态性的体现。多态性主要通过继承和接口来实现，它允许同一接口拥有多种不同的实现方式。

# 多态的分类

- 编译时多态，也叫静态绑定。编译器通过检查引用类型（也称为声明类型或静态类型）的方法是否存在，在编译时就定位到引用类及其方法，但它不会检查实际对象（也称为运行时类型或动态类型）是否确实支持该方法。编译时多态主要体现在方法重载上，即根据参数类型、个数和次序，在编译时就确定好要执行的是哪一个方法。

- 运行时多态，即动态绑定。程序在运行时根据对象的实际类型来确定调用哪个方法，而不是在编译时确定。这意味着方法的具体实现取决于对象的实际类型，而不是声明对象时但引用类型。通过父引用类型可以声明不同的子类对象，这就使得相同方法的调用可以产生不同的行为结果。通过运行时再确定具体的执行方法，这使得代码具有更好的扩展性和可维护性。

# 多态的实现方式

## 编译时多态，方法重载（Overloading）：

重载即同一个类中可以有多个方法，它们具有相同的名字但参数列表不同（参数的数量或类型不同）。

编译器在编译阶段就定位到具体的方法。以下是一个重载示例，多个同名方法，参数个数或类型不同。重载的好处就是简化了接口设计，不用因为类型不同而写很多方法名。

```java
// OverloadExample.java  全部源码见文档链接
/**
 * 重载示例，同名方法，参数个数或类型不同。
 * 编译器在编译时确定具体的调用方法。
 */
class Calculator {
    public int add(int num1, int num2) {
        return num1 + num2;
    }

    public int add(int... nums) {
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }
        return sum;
    }
}
```

## 运行时多态，方法重写（Override）与转型（Casting）：

运行时多态是指在程序运行时才确定实际要执行的方法。

子类在继承父类时，可以覆盖父类的同名方法，这就是重写。当通过父引用类型来声明子类对象时，子类就向上转型为父类类型，调用该对象的方法会执行子类的方法，而不是父类的。

向上转型即用父类引用来声明子类对象，这时子类对象的实际类型是父类，但可以通过父类引用来调用子类的方法（子类已转型为父类了）。通过向上转型，代码更加通用，当处理一组相关对象时，无需知道它们的具体类型。

向下转型则是将父类对象转换为子类引用，这种转换需要显式进行，并且在转换前需要进行类型检查，使用 instanceof 关键字。

```java
// OverrideExample.java 全部源码见文档链接
/**
 * 重写示例，子类覆盖父类同名方法，体现多态。
 * 子类向上转型为父类型，父类强制向下转型为子类型。
 */
class Shape {
  void draw() {
    System.out.println("Shape->draw");
  }

  void drawShape() {
    System.out.println("Shape->drawShape");
  }
}

class Circle extends Shape {
  @Override
  void draw() {
    System.out.println("Circle->draw");
  }

  void drawCircle() {
    System.out.println("Circle->drawCircle");
  }
}

class Square extends Shape {
  @Override
  void draw() {
    System.out.println("Square->draw");
  }

  void drawSquare() {
    System.out.println("Square->drawSquare");
  }
}

public class OverrideExample {
  public static void main(String[] args) {
    // 用父类引用声明子类对象，向上转型
    Shape shape1 = new Circle();
    Shape shape2 = new Square();

    // 子类有同名方法，动态绑定到子类，实质执行的是Circle.draw()，体现多态
    shape1.draw();

    // 报错，编译时按声明类型检查，Shape类中没有drawCircle方法
    // shape1.drawCircle();

    // 执行父类方法，输出 "Shape->drawShape"
    shape1.drawShape();

    if (shape2 instanceof Square) {
      // 向下转型，用子类重新声明，成为子类型了
      Square mySquare = (Square) shape2;

      // 输出 "Square->draw"
      mySquare.draw();

      // 输出 "Square->drawSquare"
      mySquare.drawSquare();

      // 报错。若强转为父类型，则无法调用drawSquare方法
      // ((Shape) mySquare).drawSquare();

      // 继承父类，输出 "Shape->drawShape"
      mySquare.drawShape();
    }
  }
}

```

## 多态三个必要条件：
严格来讲，多态需要具备三个条件。重载不属于严格意义上多态，因为重载在编译阶段就确定了。我们这里主要探讨运行时的多态，即针对某个类型的方法调用，实际执行的方法取决于运行时的对象，而不是声明时的类型。
    1. 继承。子类继承父类或实现接口。
    2. 重写。子类覆盖了父类的方法。
    3. 父类声明子类。父类引用来声明子类对象。

```java
// 父类
class Animal {
    void makeSound() {
        System.out.println("Animal makes a sound");
    }
}

// 子类继承并重写同名方法
class Dog extends Animal {
    @Override
    void makeSound() {
        System.out.println("Dog barks");
    }
}

public class Test {
    public static void main(String[] args) {
         // 父类引用声明子类
        Animal myAnimal = new Dog();
         // 运行时对象为子类，故输出"Dog barks"
        myAnimal.makeSound();
    }
}
```

**如何理解父类声明子类 `Parent child = new Child();` ？**

- 解释：用Parent类声明了一个child引用变量（变量存于栈中），赋值为Child实例对象（对象存于堆中）。变量child的类型为Parent（向上转型了），它的值是一个实例对象，类型为Child。
- 加载执行顺序：
    编译时：JVM编译时会检查类的关系和对应方法（含重载），确定变量的类型并定位到相关方法名称 -> 生成字节码
    运行时：JVM加载Parent与Child类 -> 依据Parent和Child大小分配堆内存 -> 初始化new Child()并返回对象引用 ->
    分配栈内存给变量child -> 将对象引用赋值给child。
    总结：编译时根据引用类型（不是实例对象）来确定方法的名称和参数（含重载），运行时若子类覆盖了父类的相同方法，则调用子类（实例引用类型）的方法，若没有覆盖，则执行父类（变量引用类型）的方法。


## 多态的好处

能非常好的体现面向对象设计的“开闭原则”，对于代码的可扩展和可维护大有好处。

延续上面的例子，业务需要扩充更多子类。
```java
// 定义一个通用Animal类
class Animal {
    void makeSound() {
        System.out.println("Animal makes a sound");
    }
}

// 定义Dog类，它是动物的子类
class Dog extends Animal {
    @Override
    void makeSound() {
        System.out.println("Dog barks");
    }
}

// 定义Cat类，它是动物的子类
class Cat extends Animal {
    @Override
    void makeSound() {
        System.out.println("Cat meows");
    }
}

// 定义一个动物园类，管理不同的动物
class Zoo {
    // 传入的是抽象父类或接口，方便扩展
    void letAnimalMakeSound(Animal animal) {
        animal.makeSound();
    }
}

public class AnimalExample {
    public static void main(String[] args) {
        Zoo zoo = new Zoo();

        Animal myDog = new Dog(); // 向上转型
        Animal myCat = new Cat(); // 向上转型

        // 通过多态性，动物园可以使用相同的方法处理不同种类的动物
        zoo.letAnimalMakeSound(myDog); // 输出 "Dog barks"
        zoo.letAnimalMakeSound(myCat); // 输出 "Cat meows"
    }
}
```

假设我们要增加新的动物，例如鸟类（Bird），我们只需扩展 Animal 类，而不需要修改现有Zoo里面的方法。

对扩展开放：允许新增Animal子类；
对修改封闭：不需要修改依赖Zoo里的letAnimalMakeSound方法。

这样代码就更具灵活性和可扩展性，同时更简洁清晰。

```java
class Bird extends Animal {
    @Override
    void makeSound() {
        System.out.println("Bird chirps");
    }
}

public class AnimalExample {
    public static void main(String[] args) {
        Zoo zoo = new Zoo();

        Animal myDog = new Dog(); // 向上转型
        Animal myCat = new Cat(); // 向上转型
        Animal myBird = new Bird(); // 向上转型

        // 通过多态性，动物园可以使用相同的方法处理不同种类的动物
        zoo.letAnimalMakeSound(myDog); // 输出 "Dog barks"
        zoo.letAnimalMakeSound(myCat); // 输出 "Cat meows"
        zoo.letAnimalMakeSound(myBird); // 输出 "Bird chirps"
    }
}
```

# 其他语言如何实现多态？

## Go语言例子
Go语言没有继承，也就没有父类声明子类，也没有重载，也就没法实现Java意义上的多态。但Go有struct以及接口，可以通过struct定义数据结构，用接口来声明struct，还可以通过匿名组合的方式来模拟继承父struct。

```go
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

func main() {
  zoo := Zoo{}
  myDog := Dog{}
  // 接口断言
  var myCat Animal = &Cat{}
  // 类型断言
  (myCat.(*Cat)).Meow()

  // 使用多态性，通过接口类型处理不同的具体类型
  zoo.LetAnimalMakeSound(myDog) // 输出 "Dog barks"
  zoo.LetAnimalMakeSound(myCat) // 输出 "Cat meows"
}s
```

当需要增加Bird类型时，直接增加即可。同样无需修改Zoo类里面的LetAnimalMakeSound方法。

```go
type Bird struct{}

// 实现 Animal 接口的 MakeSound 方法
func (b Bird) MakeSound() {
    fmt.Println("Bird chirps")
}

func main() {
  zoo := Zoo{}
  myDog := Dog{}
  var myCat Animal = &Cat{}
  (myCat.(*Cat)).Meow()
  myBird := Bird{}

  // 使用多态性，通过接口类型处理不同的具体类型
  zoo.LetAnimalMakeSound(myDog)  // 输出 "Dog barks"
  zoo.LetAnimalMakeSound(myCat)  // 输出 "Cat meows"
  zoo.LetAnimalMakeSound(myBird) // 输出 "Bird chirps"
}
```

严格的多态，包括子类继承父类，方法重写，以及父类声明子类等，那么Go语言就无法实现了。Go语言没有class概念，其struct虽然看起来像class，也有方法，但没有继承和重载。Go语言摒弃了传统面向对象的class和继承概念，我们当以新的视角来解读面向对象。

## JavaScript语言例子

## Python语言例子

## Java多态实例详解

以下是一个关于Java多态的实例，详尽分析了Java多态的原理和执行过程，请调试代码测试下。通过这个列子，基本上把Java多态全部搞清楚了。其他语言的详细版本不一一列出，请从代码库里找。

```java
// PolymorphismSimple.java
// 父类A
class A {
    public String show(D object) {
        return ("A and D");
    }

    public String show(A object) {
        return ("A and A");
    }

    // 默认注释掉。可开关注释测试下
    // public String show(B object) {
    // return ("A and B");
    // }
}

// 子类B
class B extends A {
    public String show(B object) {
        return ("B and B");
    }

    public String show(A object) {
        return ("B and A");
    }
}

// 孙子类C
class C extends B {
}

// 孙子类D
class D extends B {
}

// 测试验证
public class PolymorphismSimple {
    public static void main(String[] args) {
        // 父类声明自己
        A a = new A();
        // 父类声明子类
        A ab = new B();
        // 子类声明自己
        B b = new B();
        C c = new C();
        D d = new D();

        // 1) A and A。b的类型是B，也是B的实例，A里没有show(B)方法，但有show(A)方法。B的父类是A，因此定位到A.show(A)。
        System.out.println("1) " + a.show(b));

        // 2) A and A。c的类型是C，也是C的实例，C继承B，B继承A。A里没有show(C)方法，也没有show(B)方法，最后指向A.show(A)。
        System.out.println("2) " + a.show(c));

        // 3) A and D, d的类型是D，也是D的实例，D继承B，B继承A。A里有show(D)方法，直接定位到A.show(D)。
        System.out.println("3) " + a.show(d));

        // 4) B and A, ab是B的实例，但用A声明，即向上转型得到的类型是A，运行时才能确定具体该调用哪个方法。
        // ab是B的实例对象，但引用类型是A。类型是在编译时确定，因此从类型开始定位方法。
        // A类中没有show(B)方法，但有show(A)方法，因为A是B的父类，ab也是A的实例，于是定位到A.show(A)方法。
        // 由于B是A的子类，且B重写了A的show(A)，A的方法被覆盖了，于是定位到B.show(A)，这就是动态绑定。
        // 虽然B中有show(B)方法，但是因为ab的类型是A，编译时根据类型定位到A的方法，而不是B。

        // 以下几种可开关打开/注释代码测试下。
        // -
        // 若A里有show(A)和show(B)，B里有show(B)有show(A)，则编译时关联到A.show(B)，因B覆盖了A.show(B)，动态绑定到B.show(B)。
        // -
        // 若A里有show(A)和show(B)，B里无show(B)有show(A)，则编译时关联到A.show(B)，因B无覆盖，则直接调用A.show(B)。
        // -
        // 若A里有show(A)无show(B)，B里无show(B)有show(A)，则编译时关联到A.show(A)，因B覆盖了A.show(A)，动态绑定到B.show(A)。
        // -
        // 若A里有show(A)无show(B)，B里无show(A)有show(B)，则编译时关联到A.show(A)，因B无覆盖，则直接调用A.show(A)。
        // 查找顺序为：编译时根据引用类型确定所属类 -> 根据重载参数类型定位（类型按子->父->祖逐级往上查找）到类的具体方法（包括继承的方法） ->
        // 运行时实例对象覆盖（覆盖只有子->父一层）了引用类型的同名方法 -> 定位到实例对象的方法。
        System.out.println("4) " + ab.show(b));

        // 5) B and A。ab是B的实例，类型是A。从A类没找到show(C)方法，也没找到A.show(B)方法，找到A.show(A)方法。A.show(A)被B.show(A)覆盖，因此调用B.show(A)。
        System.out.println("5) " + ab.show(c));

        // 6) A and D。A里面有show(D)的方法，直接定位到。
        System.out.println("6) " + ab.show(d));

        // 7) B and B。B里面有show(B)的方法，直接定位到。
        System.out.println("7) " + b.show(b));

        // 8) B and B。B没有show(c)方法，但有show(B)方法。C继承自B，父类型是B，因此调用B.show(B)。
        System.out.println("8) " + b.show(c));

        // 9) A and D。B中没有show(D)方法，B继承A，A里有show(D), 故调用A.show(D)方法。
        System.out.println("9) " + b.show(d));

        // 10) B and A。父类声明子类，存在向上转型。A里有show(A)，被B.show(A)覆盖了，因此定位到B.show(A)。
        System.out.println("10) " + ab.show(a));

    }
}
```

## 各语言完整示例

[PolymorphismExample.java](./PolymorphismExample.java)
[PolymorphismExample.go](./PolymorphismExample.go)
[polymorphism_example.c](./polymorphism_example.c)
[PolymorphismExample.cpp](./PolymorphismExample.cpp)
[PolymorphismExample.js](./PolymorphismExample.js)
[PolymorphismExample.py](./PolymorphismExample.py)
[PolymorphismExample.ts](./PolymorphismExample.ts)

## 简单示例

[PolymorphismSimple.java](./PolymorphismSimple.java)
[PolymorphismSimple.go](./PolymorphismSimple.go)
[polymorphism_simple.c](./polymorphism_simple.c)
[PolymorphismSimple.cpp](./PolymorphismSimple.cpp)
[PolymorphismSimple.js](./PolymorphismSimple.js)
[PolymorphismSimple.py](./PolymorphismSimple.py)
[PolymorphismSimple.ts](./PolymorphismSimple.ts)
