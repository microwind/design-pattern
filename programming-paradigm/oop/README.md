# 面向对象概述

面向对象编程（Object-Oriented Programming，简称 OOP）是一种基于"对象"概念的编程范式。在面向对象编程中，程序由各种对象组成，每个对象都包含数据和方法。

# 面向对象编程的相关概念

## 对象（Object）

对象是类的一个实例，也是面向对象编程的基本单位。对象包含数据（称为属性）和行为（称为方法）

## 类（Class）

万物以类聚，通过分类可以将万事万物归纳起来。类可看作是创建对象的蓝图或模板，它定义了对象的数据属性和行为方法。

## [接口（Interface）](./interface/)

接口是一种抽象方法的集合，与类属于不同的概念。类描述对象的属性和方法，接口则定义类需要实现的方法。
接口和抽象类有点像，都是一种抽象类型，但两者很大不同。抽象类是对一种事物整体的抽象，即对类抽象，包括属性、行为等，子类和抽象类是一种"is-a"的关系。而接口是对行为的抽象，是对类局部（行为）进行抽象，接口表示一种"can-do"的关系。
抽象类作为子类的父类，它是一种模板式设计。接口是一种行为规范，它是一种辐射式设计。

## [封装（Encapsulation）](./encapsulation/)

即隐藏对象的属性和实现细节，只对外公开必要的接口，控制属性的读写访问级别。封装有助于保持代码的模块化和减少代码复杂性。

## [继承（Inheritance）](./inheritance/)

即子类继承父类的特征和行为，使得子类对象（实例）具有父类的属性和方法。继承的类被称为子类，提供继承的类被称为父类或基类，通过继承可以实现代码复用。在面向对象编程中，只在必须的时候使用继承，其他时候尽量使用组合。

## [组合（Composition）](./composition/)

部分与整体的关系。将一个对象是另一个对象的属性，从而实现对象之间的关联。与继承不同，组合强调的是一种“has-a”（拥有）关系，而不是“is-a”（是）的关系。组合通常用于建立复杂对象的内部结构，使得对象的构成更加灵活，并有助于代码的模块化和重用。

## [聚合（Aggregation）](./aggregation/)

也是部分和整体的关系，一个对象（整体）包含或引用其他对象（部分），但这些部分对象在逻辑上可以独立于整体对象。与组合不同，聚合中的部分对象不一定是整体对象的严格组成部分，它们可以在整体对象销毁后继续存在。聚合关系松散，组合关系严密。

## [多态（Polymorphism）](./polymorphism/)

即同一个行为具有多个不同表现形式或形态的能力。表现形式为，子类重写父类方法，实现类实现接口方法，子类重写抽象类方法等。多态三个必要条件：继承、重写、父类引用指向子类对象。多态有效消除类型之间的耦合，并提供灵活的可扩展方案。

## [抽象（Abstraction）](./abstraction/)

是一种简化复杂系统的方法，在更高层次上进行建模。在面向对象编程中，抽象意味着关注对象的模型架构而非具体实现。抽象包括两个方面，一是过程抽象，二是数据抽象。过程抽象，关注于目标的功能是什么，而不是功能是怎么实现的。数据抽象，关注数据的特性、用途和行为，而不是底层实现。

# 例子

```java
/**
 * 体现了面向对象编程的以下概念：
 * 类和对象：Animal是基类，Dog和Cat是从Animal继承的子类。通过创建类的实例，可以生成不同的对象。
 * 继承：Dog和Cat继承了Animal类的属性和方法，同时也可以覆写父类的方法，实现自己特有的行为。
 * 多态：通过父类引用子类对象，代码可以在运行时根据对象的类型调用相应的覆写方法。这允许更灵活的代码复用和扩展。
 * 封装：类的属性被保护级别封装，确保只有子类和自身可以访问。这有助于保持对象的状态和行为的安全。
*/
// 定义一个Animal的基类
class Animal {
    protected String name;  // 封装，保护级别的属性，子类可以访问

    public Animal(String name) {
        this.name = name;  // 初始化动物的名字
    }

    public void speak() {
        System.out.println(name + " makes a sound.");  // 通用的说话方法
    }
}

// 定义一个Dog的子类，继承自Animal
class Dog extends Animal {
    public Dog(String name) {
        super(name);  // 调用父类的构造方法
    }

    @Override  // 覆写父类的方法
    public void speak() {
        System.out.println(name + " barks.");  // 狗特有的说话方式
    }
}

// 定义一个猫的子类，继承自Animal
class Cat extends Animal {
    public Cat(String name) {
        super(name);  // 调用父类的构造方法
    }

    @Override  // 覆写父类的方法
    public void speak() {
        System.out.println(name + " meows.");  // 猫特有的说话方式
    }
}

// 演示多态和继承
public class Test {
    public static void main(String[] args) {
        // 创建一个动物的对象
        Animal genericAnimal = new Animal("Generic Animal");
        genericAnimal.speak();  // 输出：Generic Animal makes a sound.

        // 创建一个狗的对象
        Dog dog = new Dog("Buddy");
        dog.speak();  // 输出：Buddy barks.

        // 创建一个猫的对象
        Cat cat = new Cat("Whiskers");
        cat.speak();  // 输出：Whiskers meows.

        // 演示多态
        Animal polymorphicAnimal;
        // 父类声明子类Dog
        polymorphicAnimal = new Dog("Rover");
        polymorphicAnimal.speak();  // 输出：Rover barks.

        // 对象改为Cat
        polymorphicAnimal = new Cat("Fluffy");
        polymorphicAnimal.speak();  // 输出：Fluffy meows.
    }
}
```
