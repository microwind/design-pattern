#include <iostream>

// 定义动物基类
class Animal
{
public:
  std::string name = "Animal";

  virtual void eat()
  {
    std::cout << "Animal is eating..." << std::endl;
  }

  // 方法重载：同名方法，不同参数列表
  virtual void eat(std::string food)
  {
    std::cout << "Animal is eating " << food << "..." << std::endl;
  }

  virtual std::string getName()
  {
    return name;
  }
};

// 定义狗类，继承自动物基类
class Dog : public Animal
{
public:
  std::string name = "Dog";

  // 方法重写：子类重写父类的方法
  void eat() override
  {
    std::cout << "Dog is eating..." << std::endl;
  }

  // 方法重写：子类重写父类的方法
  void eat(std::string food) override
  {
    std::cout << "Dog is eating " << food << "..." << std::endl;
  }

  // 子类自有方法
  void bark()
  {
    std::cout << "Dog is barking..." << std::endl;
  }

  // 方法重写：子类重写父类的方法
  std::string getName() override
  {
    return name;
  }
};

// 定义猫类，继承自动物基类
class Cat : public Animal
{
public:
  std::string name = "Cat";

  // 方法重写：子类重写父类的方法
  void eat() override
  {
    std::cout << "Cat is eating..." << std::endl;
  }

  // 方法重写：子类重写父类的方法
  void eat(std::string food) override
  {
    std::cout << "Cat is eating " << food << "..." << std::endl;
  }

  // 子类自有方法
  void meow()
  {
    std::cout << "Cat is meowing..." << std::endl;
  }

  // 方法重写：子类重写父类的方法
  std::string getName() override
  {
    return name;
  }
};

// 定义猪类，继承自动物基类
class Pig : public Animal
{
public:
  // 方法重写：子类重写父类的方法
  void eat() override
  {
    std::cout << "Pig is eating..." << std::endl;
  }

  // 方法重写：子类重写父类的方法
  void eat(std::string food) override
  {
    std::cout << "Pig is eating " << food << "..." << std::endl;
  }

  // 子类自有方法
  void oink()
  {
    std::cout << "Pig is oinking..." << std::endl;
  }
};

int main()
{
  // 创建动物数组，类型向上转型，都是 Animal
  Animal *animals[4];
  animals[0] = new Dog();    // 第一个元素是 Dog 对象
  animals[1] = new Cat();    // 第二个元素是 Cat 对象
  animals[2] = new Pig();    // 第三个元素是 Pig 对象
  animals[3] = new Animal(); // 第四个元素是 Animal 对象

  // 遍历动物数组，调用各自的方法
  for (int i = 0, count = sizeof(animals) / sizeof(animals[0]); i < count; i++)
  {
    Animal *animal = animals[i];
    std::cout << "name: " << animal->getName() << std::endl;
    // 调用对象的 eat 方法
    animal->eat();
    // 调用对象的 eat 方法的重载形式
    animal->eat("some food");
    // 类型强制转换，从而可以调用子类的自有方法
    if (dynamic_cast<Dog *>(animal))
    {
      Dog *dog = dynamic_cast<Dog *>(animal);
      dog->bark();
    }
    else if (dynamic_cast<Cat *>(animal))
    {
      Cat *cat = dynamic_cast<Cat *>(animal);
      cat->meow();
    }
    else if (dynamic_cast<Pig *>(animal))
    {
      Pig *pig = dynamic_cast<Pig *>(animal);
      pig->oink();
    }
  }

  /*** 分割线 ***/

  Animal *dog = new Dog(); // 向上转型
  Animal *cat = new Cat(); // 向上转型
  Animal *pig = new Pig(); // 向上转型

  // 多态特性，在运行时根据对象的实际类型来确定，而不是引用的类型。
  dog->eat();
  ((Dog *)dog)->bark();

  cat->eat();
  ((Cat *)cat)->meow();

  pig->eat();
  ((Pig *)pig)->oink();

  for (Animal *animal : animals)
  {
    delete animal;
  }

  return 0;
}
/**
jarry@jarrys-MBP polymorphism % g++ --version
Configured with: --prefix=/Applications/Xcode.app/Contents/Developer/usr --with-gxx-include-dir=/Library/Developer/CommandLineTools/SDKs/MacOSX10.15.sdk/usr/include/c++/4.2.1
Apple clang version 12.0.0 (clang-1200.0.32.29)
Target: x86_64-apple-darwin19.6.0
Thread model: posix
InstalledDir: /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin
jarry@jarrys-MBP polymorphism % g++ -std=c++11 PolymorphismExample.cpp -o polymorphism_example_cpp
jarry@jarrys-MBP polymorphism % ./polymorphism_example_cpp                                        
name: Dog
Dog is eating...
Dog is eating some food...
Dog is barking...
name: Cat
Cat is eating...
Cat is eating some food...
Cat is meowing...
name: Animal
Pig is eating...
Pig is eating some food...
Pig is oinking...
name: Animal
Animal is eating...
Animal is eating some food...
Dog is eating...
Dog is barking...
Cat is eating...
Cat is meowing...
Pig is eating...
Pig is oinking...
 */