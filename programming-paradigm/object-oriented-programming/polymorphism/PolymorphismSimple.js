// 定义父类
class A {
  show(obj) {
    if (obj instanceof D) {
      return "A and D";
    } else if (obj instanceof A) {
      return "A and A";
    } else {
      return "A and default";
    }
  }
}

// 子类B继承A
class B extends A {
  show(obj) {
    if (obj instanceof C) {
      return "B and C";
    } else if (obj instanceof A) {
      return "B and A";
    } else {
      return super.show(obj);
    }
  }
}

// 子类C继承B
class C extends B {}

// 子类C继承B
class D extends B {}

// 测试验证
const a = new A();
// 这里ab与b没什么不同，JS没有严格类型，也没有接口，相比Java更加灵活
const ab = new B();
const b = new B();
const c = new C();
const d = new D();

// 1) A.show函数判断了A，b父类是A
console.log("1) " + a.show(b)); // 输出：A and A

// 2) A.show函数判断了A，c的祖父类是A
console.log("2) " + a.show(c)); // 输出：A and A

// 3) A.show函数判断了D类型，直接打印
console.log("3) " + a.show(d)); // 输出：A and D

// 4) B.show函数判断了A，b的父类是A
console.log("4) " + ab.show(b)); // 输出：B and A

// 5) B.show函数判断了C，直接打印
console.log("5) " + ab.show(c)); // 输出：B and C

// 6) B.show函数判断了A，d的祖父类是A
console.log("6) " + ab.show(d)); // 输出：B and A

// 7) B.show函数判断了A，b的父类是A
console.log("7) " + b.show(b)); // 输出：B and A

// 8) B.show函数判断了C，直接打印
console.log("8) " + b.show(c)); // 输出：B and C

// 9) B.show函数判断了A，d的祖父类是A
console.log("9) " + b.show(d)); // 输出：B and A

// 10) B.show函数判断了A，直接打印
console.log("10) " + ab.show(a)); // 输出：B and A

/*
jarry@jarrys-MBP polymorphism % node PolymorphismSimple.js 
1) A and A
2) A and A
3) A and D
4) B and A
5) B and C
6) B and A
7) B and A
8) B and C
9) B and A
10) B and A
*/