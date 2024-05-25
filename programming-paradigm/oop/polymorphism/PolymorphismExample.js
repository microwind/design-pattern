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

// JS是基于对象的编程语言，不是完整意义上的面向对象，因此在实现多态时不能拿Java/C++的眼光来看待。
// 多态的核心概念是：同一个行为作用于不同的对象上时，可以产生不同的解释和不同的执行结果。
// JS的class里没有重载，也没有类型定义。JS本身是动态的，也不限制传入参数的类型，JS也可以随时进行类型转换。
// JS里面还有bind, apply, call等动态改变调用者的指针的能力，更加强大和灵活。
// 因此JS无法模拟面向对象的多态，这里仅通过继承来表示。

// 定义动物基类
class Animal {
  constructor() {
    this.name = "Animal";
  }

  eat() {
    console.log("Animal is eating...");
  }

  // 方法重载：同名方法，不同参数列表
  eat_food(food) {
    console.log(`Animal is eating ${food}...`);
  }

  getName() {
    return this.name;
  }
}

// 定义狗类，继承自动物基类
class Dog extends Animal {
  constructor() {
    super();
    this.name = "Dog";
  }

  // 方法重写：子类重写父类的方法
  eat() {
    console.log("Dog is eating...");
  }

  // 方法重写：子类重写父类的方法
  eat_food(food) {
    console.log(`Dog is eating ${food}...`);
  }

  // 子类自有方法
  bark() {
    console.log("Dog is barking...");
  }
}

// 定义猫类，继承自动物基类
class Cat extends Animal {
  constructor() {
    super();
    this.name = "Cat";
  }

  // 方法重写：子类重写父类的方法
  eat() {
    console.log("Cat is eating...");
  }

  // 方法重写：子类重写父类的方法
  eat_food(food) {
    console.log(`Cat is eating ${food}...`);
  }

  // 子类自有方法
  meow() {
    console.log("Cat is meowing...");
  }
}

// 定义猪类，继承自动物基类
class Pig extends Animal {
  // 方法重写：子类重写父类的方法
  eat() {
    console.log("Pig is eating...");
  }

  // 方法重写：子类重写父类的方法
  eat_food(food) {
    console.log(`Pig is eating ${food}...`);
  }

  // 子类自有方法
  oink() {
    console.log("Pig is oinking...");
  }
}

// 测试验证
const dog = new Dog();
const cat = new Cat();
const pig = new Pig();

// 创建动物数组，没有类型强转，都是Animal的子类
const animals = [dog, cat, pig, new Animal()];

// 遍历动物数组，调用各自的方法
animals.forEach(animal => {
  console.log("name:", animal.getName());
  // 调用对象的eat方法
  animal.eat();
  // 调用对象的eat方法的重载形式
  animal.eat_food("some food");
  // 类型强制转换，从而可以调用子类的私有方法
  if (animal instanceof Dog) {
    animal.bark(); // 调用Dog类的bark方法
  } else if (animal instanceof Cat) {
    animal.meow(); // 调用Cat类的meow方法
  } else if (animal instanceof Pig) {
    animal.oink(); // 调用Pig类的oink方法
  }
});

/*** 分割线 ***/
// JS 没有对象类型的概念，使用上相当灵活，无需向上转型，即可相互转换使用。
const dogPtr = new Dog();
const catPtr = new Cat();
const pigPtr = new Pig();

// 多态特性，在编译时按引用类型确定，在运行时根据对象的实际类型来确定，而不是引用的类型。
dogPtr.eat(); // 调用Dog类的eat方法
dogPtr.bark(); // 类型强制转换并调用Dog类的bark自有方法

catPtr.eat(); // 调用Cat类的eat方法
catPtr.meow(); // 类型强制转换并调用Cat类的meow自有方法

pigPtr.eat(); // 调用Pig类的eat方法
pigPtr.oink(); // 类型强制转换并调用Pig类的oink自有方法

/** 分割线，执行父类的例子 **

// 在这个示例中，Dog 和 Cat 类都重写了 eat 方法，在每个子类的 eat 方法中，
// 除了输出信息外，还调用了 super.eat()，这样在调用 eat 方法时，
// 不同类型的对象会表现出不同的行为，从而体现多态性。

// 定义动物基类
class Animal {
    constructor(name = 'Animal') {
        this.name = name;
    }

    // eat 方法
    eat() {
        console.log(`${this.name} is eating...`);
    }
}

// 定义狗类，继承自 Animal
class Dog extends Animal {
    constructor(name = 'Dog') {
        super(name);
    }

    // 方法重写：重写父类的 eat 方法
    eat() {
        console.log(`${this.name} is eating...`);
        console.log(`${this.name} is barking...`);
    }
}

// 定义猫类，继承自 Animal
class Cat extends Animal {
    constructor(name = 'Cat') {
        super(name);
    }

    // 方法重写：重写父类的 eat 方法
    eat() {
        console.log(`${this.name} is eating...`);
        console.log(`${this.name} is meowing...`);
    }
}

// 创建动物实例
const dog = new Dog('Buddy');
const cat = new Cat('Kitty');

// 调用 eat 方法，会根据实际对象的类型动态调用对应类的方法
dog.eat(); // 输出：Buddy is eating... Buddy is barking...
cat.eat(); // 输出：Kitty is eating... Kitty is meowing...

*/