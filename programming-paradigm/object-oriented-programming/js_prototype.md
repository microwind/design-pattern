
# JS prototype 详解

## prototype验证
```js
// 验证 Object 是 Function 的实例
console.log(Object instanceof Function); // 输出: true

// 验证 Function 继承自 Object.prototype
console.log(Function.prototype.__proto__ === Object.prototype); // 输出: true

// 自定义函数和对象
function A() {}
const a = new A();

// 验证自定义函数是 Function 的实例
console.log(A instanceof Function); // 输出: true

// 验证自定义对象的原型是自定义函数的 prototype
console.log(a.__proto__ === A.prototype); // 输出: true

// 验证自定义函数的原型的原型是 Object.prototype
console.log(A.prototype.__proto__ === Object.prototype); // 输出: true
```

## prototype图形展示
```text
// 参考：https://developer.mozilla.org/zh-CN/docs/Web/JavaScript/Inheritance_and_the_prototype_chain

+----------------+  constructor  +---------------------+
|   Function     | <------------ |  Function.prototype |
| (Function 本身) | ------------> |    (Function 原型)   |
+----------------+   prototype   +---------------------+
                     __proto__       ^     |
                                     |     |
       |------------------------------     | __proto__
       |          __proto__                |
       |                                   v
+----------------+  constructor   +------------------+               +--------+
|    Function    | <----------  |  Object.prototype | --------->   |  终点   | 
| (Object 函数)   | ---------->  |  (所有对象的基类)   |  __proto__   |  null  |
+----------------+  prototype   +------------------+               +--------+
                                          ^
                                          |
                                          | __proto__
                                          |
+----------------+  constructor +----------------------+
| function Foo() |  <---------  |   Foo.prototype      |
|  (自定义函数)    |  ----------> |  (自定义函数原型对象)   |
+----------------+   prototype  +----------------------+
                                          ^
                                          |
                                          |
+----------------+                        |
|   new Foo()    | -----------------------| 
|  (函数实例对象)  |      __proto__
+----------------+           
```
<!-- 
## 函数对象实例化步骤
```js
const newFoo = new Foo()
1、创建一个新对象
function Foo() {}
// `newFoo` 是新创建的空对象
const newFoo = {};

2、将新对象的原型指向构造函数的 constructor.prototype 属性
// 此时 `newFoo` 的原型链指向了 `Foo.prototype`，
// 这意味着 `newFoo` 可以继承 `Foo.prototype` 上的属性和方法。
newFoo.__proto__ = Foo.prototype;  

3、执行构造函数，并将 this 绑定到新对象上
// `apply` 方法将 `newFoo` 作为 `this` 传入 `Foo` 构造函数。
// 如果 `Foo` 构造函数返回一个对象，那么 `result` 就会是该对象。
const result = Foo.apply(newFoo, args);  

4、// 返回新创建的对象
return newFoo;  // 如果 `Foo` 构造函数没有显式返回一个对象，则返回 `newFoo`。
``` -->

## 实例化对象步骤
实例化 `const newFoo = new Foo();` 时的步骤
```javascript
function Foo() {}
const newFoo = new Foo();
```

### **1. 创建一个新对象**  
JavaScript 先创建一个新的空对象 `newFoo`。
```javascript
const newFoo = {};
```

### **2. 设置新对象的原型**  
`newFoo.__proto__` 被设置为 `Foo.prototype`，即 `newFoo` 继承了 `Foo.prototype` 的属性和方法。
```javascript
newFoo.__proto__ = Foo.prototype;
```

### **3. 执行构造函数，并绑定 `this`**  
调用 `Foo` 构造函数，并将 `newFoo` 作为 `this` 传入。  
若 `Foo` 显式返回一个对象，则 `new` 操作符返回该对象；否则返回 `newFoo`。
```javascript
const result = Foo.apply(newFoo, args);
return typeof result === "object" ? result : newFoo;
```

---

# **原型链分析**
```javascript
newFoo.__proto__ === Foo.prototype   // ✅ `newFoo` 的原型是 `Foo.prototype`
Foo.prototype.__proto__ === Object.prototype   // ✅ `Foo.prototype` 的原型是 `Object.prototype`
Object.prototype.__proto__ === null   // ✅ `Object.prototype` 的原型是 `null`（即原型链的终点）
```

---

# **构造器关系**
```javascript
newFoo.constructor === Foo.prototype.constructor   // ✅ `newFoo` 的构造函数是 `Foo`
Foo.prototype.constructor === Foo   // ✅ `Foo.prototype` 的 `constructor` 指向 `Foo` 本身
Foo.prototype.constructor.prototype === Foo.prototype   // ✅ `Foo.prototype.constructor` 的 `prototype` 仍然是 `Foo.prototype`
```

---

# **`Function` 和 `Object` 互相指向**
```javascript
Foo.prototype.__proto__.constructor.__proto__ === Function.prototype   // ✅ `Object` 构造函数的 `__proto__` 指向 `Function.prototype`
Function.prototype === Object.__proto__   // ✅ `Function.prototype` 就是 `Object` 的 `__proto__`
Function.prototype.__proto__.__proto__ === null   // ✅ `Function.prototype.__proto__` 是 `Object.prototype`，再往上是 `null`
```

---

# **构造器和原型链的循环指向**
```javascript
Foo.prototype.constructor.prototype.constructor === Foo   // ✅ 循环指向 `Foo`
Foo.prototype.constructor.prototype.constructor.prototype === Foo.prototype   // ✅ 再次循环指向 `Foo.prototype`
Foo.prototype.constructor === Foo   // ✅ `Foo.prototype.constructor` 仍然指向 `Foo`
```

---

# **`Object` 和 `Function` 之间的关系**
```javascript
Object.prototype.constructor === Object   // ✅ `Object.prototype` 的 `constructor` 是 `Object`
Object.prototype.constructor.__proto__ === Function.prototype   // ✅ `Object` 构造函数本身是 `Function` 的一个实例
Function.constructor.__proto__ === Function.prototype   // ✅ `Function` 构造函数的 `__proto__` 也是 `Function.prototype`
Function.prototype.__proto__ === Object.prototype   // ✅ `Function.prototype` 继承自 `Object.prototype`
Function.__proto__.__proto__ === Object.prototype   // ✅ `Function.__proto__` 继承自 `Function.prototype`，最终指向 `Object.prototype`
Object.prototype.__proto__ === null   // ✅ `Object.prototype` 是原型链终点
```

---

# **总结**
- **`new` 关键字的作用**
  1. 创建一个新对象 `newFoo`
  2. 设置 `newFoo.__proto__ = Foo.prototype`
  3. 执行 `Foo` 并绑定 `this`
  4. 返回 `newFoo` 或构造函数返回的对象

- **构造函数、原型和 `Object` 的关系**
  - `Foo.prototype` 继承自 `Object.prototype`
  - `Object.prototype` 是所有对象的原型链终点
  - `Object` 和 `Function` 互相指向，`Object` 也是 `Function` 的一个实例
  - `Function.prototype.__proto__ === Object.prototype`，最终 `Function` 也继承自 `Object`

