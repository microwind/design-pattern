class A {
  show(obj) {
    if (obj instanceof D) {
      return "A and D";
    } else {
      return "A and A";
    }
  }
}

class B extends A {
  show(obj) {
    if (obj instanceof B) {
      return "B and B";
    } else if (obj instanceof A) {
      return "B and A";
    } else {
      return super.show(obj);
    }
  }
}

class C extends B {}

class D extends B {}

// 测试验证
const a = new A();
const ab = new B();
const b = new B();
const c = new C();
const d = new D();

console.log("1--" + a.show(b)); // 输出：A and A
console.log("2--" + a.show(c)); // 输出：A and A
console.log("3--" + a.show(d)); // 输出：A and D
console.log("4--" + ab.show(b)); // 输出：B and B
console.log("5--" + ab.show(c)); // 输出：B and B
console.log("6--" + ab.show(d)); // 输出：B and B
console.log("7--" + b.show(b)); // 输出：B and B
console.log("8--" + b.show(c)); // 输出：B and B
console.log("9--" + b.show(d)); // 输出：B and B
console.log("10--" + ab.show(a)); // 输出：B and A

/*
jarry@jarrys-MBP polymorphism % node PolymorphismSimple.js 
1--A and A
2--A and A
3--A and D
4--B and B
5--B and B
6--B and B
7--B and B
8--B and B
9--B and B
10--B and A
*/