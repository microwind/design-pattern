// 定义父类 A
class A {
  show(obj: any): string {
    if (obj instanceof D) {
      return 'A and D'
    } else {
      return 'A and A'
    }
  }
}

// 定义子类 B，继承自 A
class B extends A {
  show(obj: any): string {
    if (obj instanceof B) {
      return 'B and B'
    } else if (obj instanceof A) {
      return 'B and A'
    } else {
      return super.show(obj)
    }
  }
}

// 定义子类 C，继承自 B
class C extends B {}

// 定义子类 D，继承自 B
class D extends B {}

// 测试验证
const a = new A()
const ab = new B()
const b = new B()
const c = new C()
const d = new D()

console.log('1--' + a.show(b)) // 输出：A and A
console.log('2--' + a.show(c)) // 输出：A and A
console.log('3--' + a.show(d)) // 输出：A and D
console.log('4--' + ab.show(b)) // 输出：B and B
console.log('5--' + ab.show(c)) // 输出：B and B
console.log('6--' + ab.show(d)) // 输出：B and B
console.log('7--' + b.show(b)) // 输出：B and B
console.log('8--' + b.show(c)) // 输出：B and B
console.log('9--' + b.show(d)) // 输出：B and B
console.log('10--' + ab.show(a)) // 输出：B and A
