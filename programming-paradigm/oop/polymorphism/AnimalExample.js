/* JS实现多态例子 */
// 定义一个通用Animal类
class Animal {
  makeSound() {
      console.log("Animal makes a sound");
  }
}

// 定义Dog类，它是动物的子类
class Dog extends Animal {
  makeSound() {
      console.log("Dog barks");
  }
}

// 定义Cat类，它是动物的子类
class Cat extends Animal {
  makeSound() {
      console.log("Cat meows");
  }
  // Cat自有函数
  meow() {
      console.log(this.constructor.name + " is meowing...", this);
  }
}

// 定义Bird类，也继承自Animal
class Bird extends Animal {
    makeSound() {
        console.log("Bird chirps");
    }
}

// 定义一个动物园类，管理不同的动物
class Zoo {
  // JS没有严格类型，除原始数据类型外，其他均是Object。
  // 参数无需类型声明，传入的对象只要有makeSound方法即可。
  letAnimalMakeSound(animal) {
      animal.makeSound();
  }
}

// 测试代码
const zoo = new Zoo();
// JS没有父类定义子类概念，直接声明即可，无需向上转型
// 通过instanceof类型判断时可得到子类和父类类型
const myDog = new Dog();
const myCat = new Cat();
const myBird = new Bird();

// 直接调用自有函数
myCat.meow();

// 可以动态给对象设置函数并绑定对象 
myDog.meow = myCat.meow.bind(myDog); 
myDog.meow();

// 动物园可以使用相同的方法处理不同种类的动物
// 当需要增加其他动物时，直接建立新的类继承Animal，而无需修改Zoo。
zoo.letAnimalMakeSound(myDog); // 输出 "Dog barks"
zoo.letAnimalMakeSound(myCat); // 输出 "Cat meows"
zoo.letAnimalMakeSound(myBird); // 输出 "Bird chirps"

/*
jarry@jarrys-MacBook-Pro polymorphism % node AnimalExample.js
Cat is meowing... Cat {}
Cat is meowing... Dog { meow: [Function: bound meow] }
Dog barks
Cat meows
Bird chirps
*/