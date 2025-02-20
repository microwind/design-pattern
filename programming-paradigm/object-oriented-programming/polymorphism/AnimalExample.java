/*Java实现多态的例子 */

// 定义一个通用Animal类
class Animal {
  void makeSound() {
    System.out.println("Animal makes a sound");
  }
}

// 或者定义Animal接口，子类来实现
// interface Animal {
// void makeSound();
// }

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

  // Cat自有方法
  void meow() {
    System.out.println("Cat is meowing...");
  }
}

// 定义一个动物园类，管理不同的动物
class Zoo {
  // 传入的是抽象父类或接口，方便扩展
  void letAnimalMakeSound(Animal animal) {
    animal.makeSound();
  }
}

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
    ((Cat)myCat).meow(); // 向下强转，打印自有方法
    Animal myBird = new Bird(); // 向上转型

    // 通过多态性，动物园可以使用相同的方法处理不同种类的动物
    zoo.letAnimalMakeSound(myDog); // 输出 "Dog barks"
    zoo.letAnimalMakeSound(myCat); // 输出 "Cat meows"
    zoo.letAnimalMakeSound(myBird); // 输出 "Bird chirps"
  }
}