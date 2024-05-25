#include <iostream>
#include <string>

// 父类A
class A
{
public:
  // 参考Java版本改写，C++中不能直接在类内部使用派生类D作为参数类型，
  // 因为在A的声明时D还未被声明。
  // 我们可以使用模板或基类指针/引用来实现类似的功能。

  // 虚拟析构函数确保当通过基类指针删除派生类对象时，派生类的析构函数也会被调用
  virtual ~A() {}
  // virtual std::string show(D *object)
  // {
  //     return "A and D";
  // }

  virtual std::string show(A *object)
  {
    return "A and A";
  }

  // 可开启关闭测试下
  // std::string show(B* object) {
  //     return "A and B";
  // }
};

// 子类B
class B : public A
{
public:
  // std::string show(B *object) override
  // { // 注意：这里不能使用override，因为A中没有show(B*)
  //   return "B and B";
  // }

  // 需要重写基类中的show方法，使用基类指针
  std::string show(A *object) override
  {
    return "B and A";
  }
};

// 孙子类C
class C : public B
{
  // C不需要额外的show方法，因为它会继承B的show方法
};

// 孙子类D
class D : public B
{
  // D也不需要额外的show方法
};

// 测试验证
int main()
{
  A *a = new A();
  A *ab = new B(); // 使用基类指针指向派生类对象
  B *b = new B();
  C *c = new C();
  D *d = new D();

  std::cout << "1--" << a->show(b) << std::endl;                    // A and A
  std::cout << "2--" << a->show(c) << std::endl;                    // A and A，因为c被当作A*传递
  std::cout << "3--" << a->show(d) << std::endl;                    // A and A，同样因为d被当作A*传递
  std::cout << "4--" << ab->show(b) << std::endl;                   // B and A
  std::cout << "5--" << ab->show(c) << std::endl;                   // B and A
  std::cout << "6--" << ab->show(static_cast<A *>(d)) << std::endl; // B and A，强制转换为A*

  // 下面的调用将不会编译，因为B中没有show(B*)的声明
  // std::cout << "7--" << b->show(b) << std::endl; // 错误：没有匹配的show函数

  // 但是，我们可以通过动态类型识别来调用特定的函数
  // 例如，我们可以检查指针或引用的实际类型

  std::cout << "8--" << dynamic_cast<B *>(b)->show(dynamic_cast<B *>(c)) << std::endl; // B and A，因为c被当作B*传递，但show方法使用的是基类指针

  // 强制将D转换为A指针来调用A中的show
  std::cout << "9--" << ab->show(static_cast<A *>(d)) << std::endl; // B and A

  // ab指向B，因此show(A*)将调用B的show方法
  std::cout << "10--" << ab->show(a) << std::endl; // B and A

  // 清理内存
  delete a;
  delete ab;
  delete b;
  delete c;
  delete d;

  return 0;
}

/**
jarry@jarrys-MBP polymorphism % g++ --version
Configured with: --prefix=/Applications/Xcode.app/Contents/Developer/usr --with-gxx-include-dir=/Library/Developer/CommandLineTools/SDKs/MacOSX10.15.sdk/usr/include/c++/4.2.1
Apple clang version 12.0.0 (clang-1200.0.32.29)
Target: x86_64-apple-darwin19.6.0
Thread model: posix
InstalledDir: /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin
jarry@jarrys-MBP polymorphism % g++ -std=c++11 PolymorphismSimple.cpp -o PolymorphismSimple_cpp
jarry@jarrys-MBP polymorphism % ./PolymorphismSimple_cpp
1--A and A
2--A and A
3--A and A
4--B and A
5--B and A
6--B and A
8--B and A
9--B and A
10--B and A
 */