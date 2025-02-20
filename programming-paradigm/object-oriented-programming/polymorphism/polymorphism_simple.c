/**
C语言并不直接支持面向对象编程（OOP）的特性，如类、继承、多态等。
可以使用结构体和函数指针来模拟这些特性。
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 定义结构体和函数指针
typedef struct A A;
typedef struct B B;
typedef struct C C;
typedef struct D D;

struct A
{
  char *(*show_A)(A *self, A *object);
  char *(*show_D)(A *self, D *object);
};

struct B
{
  A super;
  char *(*show_B)(B *self, B *object);
};

// 子类C和D的定义不需要额外的方法，只需要继承B即可
struct C
{
  B super;
};

struct D
{
  B super;
};

// 函数实现
char *A_show_A(A *self, A *object)
{
  return "A and A";
}

char *A_show_D(A *self, D *object)
{
  return "A and D";
}

char *B_show_A(B *self, A *object)
{
  return "B and A";
}

char *B_show_B(B *self, B *object)
{
  return "B and B";
}

// 初始化A函数
void init_A(A *a)
{
  a->show_A = A_show_A;
  a->show_D = A_show_D;
}

// 初始化B函数
void init_B(B *b)
{
  init_A(&b->super);
  b->super.show_A = (char *(*)(A *, A *))B_show_A;
  b->show_B = B_show_B;
}

// 初始化C函数
void init_C(C *c)
{
  init_B(&c->super);
}

// 初始化D函数
void init_D(D *d)
{
  init_B(&d->super);
}

/**
解释说明：
结构体定义：定义了结构体 A、B、C 和 D。B 结构体继承 A 结构体，C 和 D 结构体继承 B 结构体。
函数指针：在结构体中定义了函数指针，以模拟 Java 中的方法。函数指针的类型和签名与相应的 Java 方法对应。
函数实现：实现了 A 和 B 结构体的各个方法。
初始化函数：用于初始化结构体实例，设置相应的函数指针。
主函数：在 main 函数中，创建各个结构体实例并初始化它们，然后调用相应的方法，模拟 Java 中的多态行为。
通过这种方式，虽然C语言没有直接的继承和多态机制，但可以使用结构体和函数指针来模拟这些特性，实现类似于Java多态的功能。
*/

// 测试验证
int main()
{
  A a;
  B b;
  C c;
  D d;
  B ab;

  init_A(&a);
  init_B(&b);
  init_C(&c);
  init_D(&d);
  init_B(&ab);

  printf("1--%s\n", a.show_A(&a, (A *)&b));              // A and A
  printf("2--%s\n", a.show_A(&a, (A *)&c));              // A and A
  printf("3--%s\n", a.show_D(&a, &d));                   // A and D
  printf("4--%s\n", ab.super.show_A((A *)&ab, (A *)&b)); // B and A
  printf("5--%s\n", ab.super.show_A((A *)&ab, (A *)&c)); // B and A
  printf("6--%s\n", ab.super.show_D((A *)&ab, &d));      // A and D
  printf("7--%s\n", b.show_B(&b, &b));                   // B and B
  printf("8--%s\n", b.show_B(&b, (B *)&c));              // B and B
  printf("9--%s\n", b.super.show_D((A *)&b, &d));        // A and D
  printf("10--%s\n", ab.super.show_A((A *)&ab, &a));     // B and A

  return 0;
}

/**
jarry@jarrys-MBP polymorphism % gcc polymorphism_simple.c
jarry@jarrys-MBP polymorphism % ./a.out
1--A and A
2--A and A
3--A and D
4--B and A
5--B and A
6--A and D
7--B and B
8--B and B
9--A and D
10--B and A
 */