# 什么是多态

多态是指程序在运行时，同一方法的调用在不同对象上可以表现出不同的行为来。具体来说，子类继承和覆盖父类属性和方法后，并用父类引用声明子类对象，在调用父子类的同名方法时，会根据实际对象的类型来确定执行对应的方法，而不是声明时的类型，这样就实现了多态。

# 多态的分类

- 编译时多态，也叫静态绑定。即在编译时，编译器会检查引用类型（也称为声明类型或静态类型）的方法是否存在，但它不会检查实际对象（也称为运行时类型或动态类型）是否确实支持该方法。这使得可以支持方法重载。

- 运行时多态，即动态绑定。在运行时根据对象的实际类型确定调用哪个方法，而不是在编译时确定。这意味着方法的具体实现取决于对象的实际类型，而不是引用的类型。相同的方法调用可以产生不同的行为。


# 多态的实现方式

- 方法重载（Overloading）：同一个类中可以有多个方法，它们具有相同的名字但参数列表不同（参数的数量或类型不同）。

- 方法重写（Override）：子类可以重写父类的方法，以提供特定的实现。当子类对象被向上转型为父类类型时，调用该方法时会执行子类重写后的版本。

- 向上转型（Upcasting）和向下转型（Downcasting）：向上转型是将子类对象赋值给父类引用，这不会改变对象的实际类型，但可以用父类的引用来调用子类的方法（前提是方法在父类中已声明）。向下转型是将父类引用转换为子类引用，需要进行类型检查，通常使用 instanceof 关键字。


# 多态示例

## 编译时多态，方法重载例子
```java
// Calculator.java
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

## 运行时多态，方法重写例子

### 严格多态三个必要条件：
    1. 继承
    2. 重写
    3. 父类引用指向子类对象

```java
// RuntimePolymorphismExample.java

// 父类
class Animal {
    // 基类的 makeSound 方法
    public void makeSound() {
        System.out.println("动物发出声音");
    }
}

// 子类Dog
class Dog extends Animal {
    // Dog 类重写了基类的 makeSound 方法
    @Override
    public void makeSound() {
        System.out.println("汪汪汪");
    }
}

// 子类Cat
class Cat extends Animal {
    // Cat 类重写了基类的 makeSound 方法
    @Override
    public void makeSound() {
        System.out.println("喵喵喵");
    }
}

public class RuntimePolymorphismExample {

    public static void main(String[] args) {
        // 创建一个 Dog 对象，并将其引用赋值给 Animal 类型的变量 animal1，体现多态
        Animal animal1 = new Dog();
        // 创建一个 Cat 对象，并将其引用赋值给 Animal 类型的变量 animal2，体现多态
        Animal animal2 = new Cat();

        // 通过 animal1 调用 makeSound 方法，实际执行的是 Dog 类中重写的方法
        animal1.makeSound();
        // 通过 animal2 调用 makeSound 方法，实际执行的是 Cat 类中重写的方法
        animal2.makeSound();
    }
}
```

# 不同语言多态的例子，请查看源码
## 完整示例
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
