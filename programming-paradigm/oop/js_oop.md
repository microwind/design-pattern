# JavaScript 面向对象详解
## 1. JavaScript 实现面向对象方式

### 1.1 静态对象
```javascript
const child = (function () {
  let _private = '_private';  // 私有变量
  let name = 'name';          // 闭包中的变量
  this.name = 'this.name';    // 全局对象的属性

  function getName() {
    return this.name + ',' + name;  // 使用闭包中的 name 和 this.name
  }

  /*
  直接调用 getName()：此时 this 指向全局对象（window），this.name 是 'this.name'。
  name 是闭包中的变量，值为 'name'。
  因此，这里输出: this.name,name。
  */
  console.log('getName():', getName())

  return {
    name: name,          // 公开的属性
    thisName: getName(), // 直接调用 getName()，返回 'this.name,name'
    getName: getName     // 公开的方法
  };
})();

// 输出：name this.name,name name,name undefined
console.log(child.name, child.thisName, child.getName(), child._private);
/* 分析：
child.name：返回child的 name，值为 'name'。
child.thisName：返回child的 thisName 属性，返回时已经执行了，值为 'this.name,name'。
child.getName()：调用child的 getName 方法。这时 getName() 里的 this 指向 child 对象，child的name已被设置为'name'。name 是闭包中的变量，值为 'name'。因此，执行child.getName() 得到 'name,name'。
child._private：_private 是函数内部的局部变量，外部无法访问，因此是 undefined。
*/
```

### 1.2 原型对象模拟类
```js
// Child构造函数+原型作为类
function Child() {};

// 在 Child.prototype 上定义属性和方法，等同于Class属性
Child.prototype.name = 'child';  // 原型上的属性 name，所有实例默认继承该属性
Child.prototype.getName = function () {
  return 'child:' + this.name;  // 使用实例的 name 属性（或原型链上的 name）生成返回值
};

// 创建实例 c1
const c1 = new Child();
console.log('c1:', c1.name, c1.getName());
// c1.name 从原型继承得到，默认值是 'child'
// c1.getName() 返回 'child:child'

Child.prototype.name = 'child2';  // 修改原型上的 name 属性为 'child2'

// 创建实例 c2
const c2 = new Child();
// c2.name 继承自原型，值是 'child2'，因为 c2 是新创建的实例
// c2.getName() 返回 'child:child2'

c1.name = 'child3';  // 修改 c1 实例的 name 属性，覆盖了原型上的 name 属性
// 此时 c1.name 是 'child3'，并不再继承原型上的 'child' 或 'child2'

// 输出 c2 和 c1 的属性
console.log('c2:', c2.name, c2.getName());
// c2.name 继承自原型，值是 'child2'，
// c2.getName() 返回 'child:child2'

console.log('c1:', c1.name, c1.getName());
// c1.name 被修改为 'child3'，
// c1.getName() 返回 'child:child3'
```

### 1.3 构造函数模拟类
```js
// 利用构造函数模拟类
function Child() {
  this.name = 'child';  // 每个实例都有自己的 name 属性，初始化为 'child'
  this.getName = function () {  // 每个实例都有自己的 getName 方法
    return 'child:' + this.name;  // 使用实例的 name 属性
  };
};

const c1 = new Child();
console.log('c1:', c1.name, c1.getName());
// c1.name 是 'child'，c1.getName() 返回 'child:child'

const c2 = new Child();
Child.name = 'Child';  // 修改了构造函数本身的 name 属性，
// 但这并不影响实例的属性。实例的 name 与构造函数的 name 无关。

console.log('c2:', c2.name, c2.getName());
// c2.name 继承自构造函数，值是 'child'，c2.getName() 返回 'child:child'

c1.name = 'child3';  // 修改了 c1 实例的 name 属性，c1.name 变为 'child3'
console.log('c1:', c1.name, c1.getName());
// c1.name 被修改为 'child3'，c1.getName() 返回 'child:child3'
```

### 直接构造器和构造器+prototype模拟类的区别

|      特性        |  直接构造器当做类  |  构造器 + 原型当做类  |
|------------------|------------------|---------------------|
| **方法存储位置** | 每个实例都有自己的方法 | 所有实例共享同一方法（存储在原型上） |
| **内存使用**     | 每个实例都独立保存方法 | 所有实例共享方法，节省内存 |
| **方法修改**     | 修改实例的方法只影响当前实例 | 修改原型方法会影响所有实例 |
| **性能**         | 性能较差，内存消耗较大 | 性能较好，内存消耗较低 |
| **适用场景**     | 需要每个实例有不同方法时 | 方法相同，实例共享方法时 |


### 1.4 原型对象 + 构造函数 实现类
```js
function Child() {
  this._name = '_child';  // 实例私有属性，每个实例都有自己的 _name
};

Child._name = '_Child';  // 构造函数的静态属性，不会影响实例

// 原型属性，所有实例共享
Child.prototype.name = 'child';
Child.prototype.getName = function () {
  return 'child:' + this.name; // 访问 name，先查找实例属性，找不到再查找原型
};

const c1 = new Child();
console.log('c1:', c1.name, c1.getName()); 
// name: 来自原型 'child'
// getName(): 'child:child'（查找原型上的 name）

Child.prototype.name = 'child2'; // 修改原型上的 name

const c2 = new Child();
c1.name = 'child3'; // c1 实例添加 name 属性（屏蔽原型属性）

console.log('c2:', c2.name, c2.getName());
// name: 仍然从原型获取 'child2'
// getName(): 'child:child2'（从原型获取 name）

console.log('c1:', c1.name, c1.getName());
// name: 由于 c1 有自己的 name='child3'，不再访问原型
// getName(): 'child:child3'（优先访问实例属性）

// 检查属性来源
console.log(c1.hasOwnProperty('name'), c1.hasOwnProperty('_name'));
// true, true （c1 有自己的 name 和 _name）

console.log(c2.hasOwnProperty('name'), c2.hasOwnProperty('_name'));
// false, true （c2 没有自己的 name，但有自己的 _name）

// 检查构造函数相关属性
console.log(Child.name, Child._name, Child.prototype.isPrototypeOf(c1));
// 输出：'Child' '_Child' true
// - `Child.name` 是函数的名称（'Child'，默认属性）
// - `Child._name` 是构造函数的静态属性
// - `Child.prototype.isPrototypeOf(c1)` 确认 c1 的原型是 `Child.prototype`

```

### 1.5 class关键词的实现类
```js
class Child {
  constructor() {
    this._name = '_child'; // 实例私有属性，每个实例都有自己的 _name
  }

  static _name = '_Child'; // 静态属性，属于类本身，不会影响实例

  name = 'child'; // 实例属性，不共享，每个实例都有自己的 name

  getName() {
    return 'child:' + this.name; // 访问实例属性 name
  }
}

let c1 = new Child();
console.log('c1:', c1.name, c1.getName());

Child.prototype.name = 'child2'; // 修改原型上的 name（不会影响已创建的实例的实例属性）

let c2 = new Child();
c1.name = 'child3'; // c1 实例添加 name 属性（屏蔽原型的 name）

console.log('c2:', c2.name, c2.getName());
console.log('c1:', c1.name, c1.getName());

// 检查属性来源
console.log(c1.hasOwnProperty('name'), c1.hasOwnProperty('_name')); // true, true
console.log(c2.hasOwnProperty('name'), c2.hasOwnProperty('_name')); // true, true

// 检查构造函数相关属性
console.log(Child.name, Child._name, Child.prototype.isPrototypeOf(c1));
```

## **class与(function+prototype)对比**
### class是语法糖，本质上就是function+prototype
| 特性           | `function + prototype` 方式       | `class` 方式 |
|---------------|--------------------------------|-------------|
| **定义方式**   | 通过 `function` + `prototype` | 直接使用 `class` 关键字 |
| **实例属性**   | 在 `constructor` 里定义 `this.property` | 在 `constructor` 或类体内定义 |
| **方法共享**   | `Child.prototype.method = function () {}` | `method() {}` 定义在 `class` 内，相当于 `prototype` 方法 |
| **静态属性**   | `Child.property = value` | `static property = value` |
| **继承方式**   | `Child.prototype = Object.create(Parent.prototype)` | `class Child extends Parent` |


## 2. JavaScript 中的继承
### 2.1 原型继承
```js
function Parent(name) {
  this.name = name; // 实例属性，每个实例都有独立的 name
}

Parent.prototype.getName = function () {
  return this.name; // 访问实例的 name 属性
};

// 方式 1：正常构造函数创建实例
var c1 = new Parent('name:c1');

// 方式 2：手动修改 `__proto__` 进行原型继承
var c2 = new Object(); // 创建一个普通对象
c2.__proto__ = Parent.prototype; // 让 c2 继承 Parent 的原型方法
c2.constructor = Parent; // 修正 constructor 指向
Parent.call(c2, 'name:c2'); // 调用 Parent 构造函数，赋值实例属性

// 方式 3：使用 `Object.create` 进行原型继承
var c3 = Object.create(Parent.prototype, {
  name: { // 直接在新对象上定义 name
    value: 'name:c3'
  }
});

console.log(c1, c1.getName(), c1 instanceof Parent, Parent.prototype.isPrototypeOf(c1), c1.constructor);
/* 
// 输出：
Parent {name: 'name:c1'}name: "name:c1"[[Prototype]]: Object 'name:c1' true true ƒ Parent(name) {
  this.name = name; // 实例属性，每个实例都有独立的 name
}
*/

console.log(c2, c2.getName(), c2 instanceof Parent, Parent.prototype.isPrototypeOf(c2), c2.constructor);
/*
// 输出：
Parent {name: 'name:c2'} 'name:c2' true true ƒ Parent(name) {
  this.name = name; // 实例属性，每个实例都有独立的 name
}
*/

console.log(c3, c3.getName(), c3 instanceof Parent, Parent.prototype.isPrototypeOf(c3), c3.constructor);
/*
// 输出：
Parent {name: 'name:c3'} 'name:c3' true true ƒ Parent(name) {
  this.name = name; // 实例属性，每个实例都有独立的 name
}
*/
```

### 2.2 构造函数继承
```js
// 父类构造函数
function Parent(name, age) {
  this.name = name; // 实例属性，每个实例都有自己的 name
  this.age = age;   // 实例属性，每个实例都有自己的 age

  this.getName = function () {
    return 'parent:' + this.name; // 返回 name
  };

  this.getAge = function () {
    return 'parent:' + this.age; // 返回 age
  };
};

// 子类构造函数
function Child() {
  // **构造函数继承**：调用 Parent 构造函数，并把 `this` 绑定到 Child 实例上
  Parent.apply(this, arguments);

  // **重写 getAge 方法**：覆盖从 Parent 继承的方法
  this.getAge = function () {
    return 'child:' + this.age;
  };
};

var child1 = new Child('child1', 10);

console.log(child1.getName(), child1.getAge());
// 输出：'parent:child1 child:10'
```

### 2.3 对象扩展继承，实现extend函数
```js
/**
 * 递归（可选）扩展对象 `to`，将 `from` 对象的属性复制到 `to` 对象。
 * @param {Object} to - 目标对象，扩展后的属性将存入此对象。
 * @param {Object} from - 源对象，提供扩展属性。
 * @param {boolean} deep - 是否进行深拷贝（如果为 true，则递归拷贝嵌套对象）。
 * @returns {Object} 返回扩展后的 `to` 对象。
 */
function extend(to, from, deep) {
  /**
   * 判断是否为对象或数组
   * @param {any} obj - 需要判断的值
   * @returns {boolean} - 如果是对象或数组，则返回 true，否则返回 false
   */
  function isObjectOrArray(obj) {
    var toString = Object.prototype.toString;
    var isObject = ('[object Object]' == toString.call(obj)); // 判断是否是对象
    var isArray = ('[object Array]' == toString.call(obj));   // 判断是否是数组
    return (isObject || isArray);
  }

  // 遍历 `from` 对象的自身属性
  for (var item in from) {
    if (from.hasOwnProperty(item)) { // 确保属性是 `from` 对象自身的，而非原型链上的
      if (deep && isObjectOrArray(from[item])) { 
        // 若 deep 为 true 且 `from[item]` 是对象或数组，则递归扩展
        to[item] = extend(to[item], from[item], deep);
      } else {
        // 直接赋值（浅拷贝）
        to[item] = from[item];
      }
    }
  }

  return to; // 返回扩展后的 `to` 对象
}

// 测试对象 a 和 b
var a = {
  "key": {
    "key1": "key1"
  }
};

var b = {
  "key": {
    "key2": "key2"
  }
};

// 执行深度合并
extend(a, b, true);
console.log(a); // 输出: { key: { key2: 'key2' } }
```

### 2.4 原型继承注意事项
```js
// 1) 改写 prototype 会更改 constructor 的指向

/**
 * Parent 构造函数
 * 父类的原型中定义了 `getName` 方法
 */
function Parent() {}

// 修改 Parent 的原型，所有 Parent 的实例会继承该原型方法
Parent.prototype = {
  // 重新定义 `getName` 方法
  getName: function () {
    return 'child:' + this.name; // 返回以 'child:' 开头的 name 属性
  }
};

/**
 * Child 构造函数
 * 子类也有自己的 `getName` 方法，覆盖了 Parent 原型中的方法
 */
function Child() {}

// 在 Child 的原型上定义 `getName` 方法，这会覆盖 Parent 中的 `getName`
Child.prototype.getName = function () {
  return 'child:' + this.name; // 返回以 'child:' 开头的 name 属性
};

// 创建 Parent 和 Child 实例
var parent = new Parent();
var child = new Child();

// 打印 parent 和 child 的构造函数
console.log(parent.constructor, child.constructor);
// 输出：ƒ Object() { [native code] } ƒ Child() {}
```

### 2.5 原型继承 + 复制 constructor 完整例子
```js
/**
 * `inherits` 函数实现原型继承，并确保子类继承父类的属性和方法，同时复制 constructor。
 * @param {Function} Child - 子类构造函数
 * @param {Function} Parent - 父类构造函数
 * @returns {Function} - 返回修改后的子类构造函数
 */
function inherits(Child, Parent) {
  var ChildProto = Child.prototype; // 获取子类的原型
  var ParentProto = Parent.prototype; // 获取父类的原型

  // 创建一个空构造函数，用来继承父类的原型
  function Super() {}
  Super.prototype = ParentProto;

  // 子类原型继承父类的原型
  Child.prototype = new Super();

  // 将子类原型上的自有属性拷贝到新的子类原型上
  for (var item in ChildProto) {
    Child.prototype[item] = ChildProto[item];
  }

  // 给子类添加 `__super__` 属性，指向父类的原型
  Child.__super__ = ParentProto;

  // 修复子类的 constructor 属性，指向子类本身
  Child.prototype.constructor = Child;

  // 返回修改后的子类构造函数
  return Child;
}

/**
 * 父类构造函数
 */
function Parent() {
  this.title = 'Parent';
  this.name = 'Parent';
}
Parent.prototype.alias = 'Father';
Parent.prototype.getParentName = function () {
  return 'Parent:' + this.name;
}

/**
 * 子类构造函数
 */
function Child() {
  this.name = 'Child';
}
Child.prototype.alias = 'Son';
Child.prototype.getName = function () {
  return 'Child:' + this.name;
}
Child.prototype.getParentAlias = function () {
  return 'getParentAlias:' + Child.__super__.alias; // 访问父类的 alias 属性
}

// 使用 `inherits` 实现原型继承
inherits(Child, Parent);

// 创建一个 Child 实例
var c3 = new Child();

// 修改父类的 alias 属性
Parent.prototype.alias = 'FatherChanged';

// 打印 c3 实例及其构造函数
console.log(c3);                // 输出 c3 实例：Child {name: 'Child'}，包含子类和父类的属性。
console.log(c3.constructor);    // 输出 c3 构造函数，应该是 Child() { this.name = 'Child'; }
console.log(c3.__proto__);     // 输出 c3 的原型，应该是 Child.prototype，指向Parent实例
console.log(c3.prototype);     // 输出 c3 的原型属性：undefined

// 判断 Child.prototype 是否是 c3 的原型
console.log(Child.prototype.isPrototypeOf(c3));  // 输出 true
// 判断 Parent.prototype 是否是 c3 的原型
console.log(Parent.prototype.isPrototypeOf(c3)); // 输出 true
// 获取 c3 的原型链，输出 Parent.prototype
console.log(Object.getPrototypeOf(c3));          // 输出 Child.prototype (即 Parent.prototype)
```

### 2.6 仿照 Crockford 的原型继承例子
```js
// http://www.crockford.com/javascript/inheritance.html
// 为 Function 添加 method 方法
Function.prototype.method = function (name, func) {
    this.prototype[name] = func;
    return this;
};

// 为 Function 添加 inherits 方法
Function.prototype.inherits = function (parent) {
    // 创建一个中间构造函数，避免直接调用父类构造函数
    function F() {}
    F.prototype = parent.prototype;

    // 设置子类的原型为父类的原型
    this.prototype = new F();

    // 修复子类的 constructor 指向
    this.prototype.constructor = this;

    // 为子类添加 uber 方法，用于调用父类方法
    this.method('uber', function uber(name) {
        var f, r;
        var v = parent.prototype; // 获取父类的原型
        f = v[name]; // 获取父类的目标方法

        // 检查父类中是否存在该方法
        if (typeof f === 'function') {
            // 创建一个临时对象，其原型为父类原型
            var tempObj = Object.create(v);
            // 调用父类构造函数初始化临时对象
            parent.call(tempObj);
            r = f.apply(tempObj, Array.prototype.slice.call(arguments, 1));
            return r;
        } else {
            throw new Error(`Method ${name} not found in parent class (${parent.name}).`);
        }
    });

    return this; // 支持链式调用
};

// 父类构造函数
function Parent() {
    this.name = 'Parent';
}

// 父类方法
Parent.prototype.getName = function () {
    return this.name;
};

// 子类构造函数
function Child() {
    this.name = 'Child';
}

// 让子类继承父类
Child.inherits(Parent);

// 创建子类实例
var childInstance = new Child();

// 调用子类的 getName 方法，输出 "Child"
console.log(childInstance.getName());

// 使用 uber 调用父类的 getName 方法，输出 "Parent"
console.log(childInstance.uber('getName'));
```

### 2.7 来自 John 的原型继承完整例子
```js
// https://johnresig.com/blog/simple-javascript-inheritance/
(function () {
  // 标记是否正在初始化
  var initializing = false,

    // 判断函数中是否包含 'xyz' 的正则表达式，用于测试超类函数的调用
    fnTest = /xyz/.test(function () {
      xyz;
    }) ? /\b_super\b/ : /.*/;

  // 定义一个空的类基础函数
  this.Class = function () {};

  // 扩展现有类
  Class.extend = function (prop) {
    // 获取当前类的原型对象
    var _super = this.prototype;

    // 设置初始化标记为 true，表示正在创建类
    initializing = true;

    // 创建一个新的类的原型对象（继承父类的原型）
    var prototype = new this();
    
    // 设置初始化标记为 false，表示初始化完成
    initializing = false;

    // 遍历传入的属性对象
    for (var name in prop) {
      // 如果当前属性是函数并且是对超类函数的重写
      prototype[name] = typeof prop[name] == "function" &&
        typeof _super[name] == "function" && fnTest.test(prop[name]) ?
        
        // 创建一个包装函数，保留对超类函数的访问
        (function (name, fn) {
          return function () {
            // 保存当前对象的 _super 属性
            var tmp = this._super;

            // 将 _super 属性指向父类的同名方法
            this._super = _super[name];

            // 执行当前类的方法，并将 _super 恢复
            var ret = fn.apply(this, arguments);
            this._super = tmp;

            return ret;
          };
        })(name, prop[name]) :
        // 如果不是重写超类的函数，直接赋值
        prop[name];
    }

    // 定义扩展后的 Class 构造函数
    function Class() {
      // 如果没有在初始化中，并且类中有 init 方法，则执行 init 方法
      if (!initializing && this.init)
        this.init.apply(this, arguments);
    }

    // 设置新类的原型为创建的 prototype
    Class.prototype = prototype;
    
    // 修复 constructor 属性
    Class.prototype.constructor = Class;

    // 将 extend 方法设置为递归调用自身，以支持多次扩展
    Class.extend = arguments.callee;

    return Class;  // 返回扩展后的类
  };
})();
// 创建一个基础类 Animal
var Animal = Class.extend({
  init: function (name) {
    this.name = name;
  },
  speak: function () {
    console.log(this.name + " makes a sound.");
  }
});

// 创建一个继承自 Animal 的子类 Dog
var Dog = Animal.extend({
  init: function (name, breed) {
    // 调用父类构造函数
    this._super(name);  // 调用父类的 init 方法
    this.breed = breed;
  },
  speak: function () {
    // 调用父类的 speak 方法并扩展
    this._super();
    console.log(this.name + " barks.");
  }
});

// 创建 Dog 的实例
var myDog = new Dog("Rex", "Golden Retriever");
myDog.speak();  // 输出: Rex makes a sound. Rex barks.
```

### 2.8 简单版 JS 继承例子
```js
(function () {
  // 初始化标志，表示是否正在初始化类
  var initializing = false,

    // 检测函数是否包含 'xyz'，用来识别需要特殊处理的父类方法
    fnTest = /xyz/.test(function () {
      xyz; // 这段代码用来检测是否含有 _super 的引用
    }) ? /\b_super\b/ : /.*/;

  // 创建一个基础的 Class 构造函数，供后续扩展
  this.Class = function () {};

  // 扩展类的方法
  Class.extend = function (prop) {
    // 保存父类的原型，用于后续访问父类方法
    var _super = this.prototype;

    // 标记正在初始化类
    initializing = true;

    // 创建一个新的类原型对象（继承父类的原型）
    var prototype = new this();

    // 标记初始化完成
    initializing = false;

    // 遍历传入的属性对象，进行扩展
    for (var name in prop) {
      // 如果属性是函数并且是对父类方法的重写
      prototype[name] = typeof prop[name] == "function" &&
        typeof _super[name] == "function" && fnTest.test(prop[name]) ?
        
        // 创建一个包装函数，保留对父类方法的引用
        (function (name, fn) {
          return function () {
            // 保存当前对象的 _super 属性
            var tmp = this._super;

            // 将 _super 指向父类的同名方法
            this._super = _super[name];

            // 调用当前方法，并将 _super 恢复
            var ret = fn.apply(this, arguments);
            this._super = tmp;

            return ret;
          };
        })(name, prop[name]) :
        // 否则直接赋值给属性
        prop[name];
    }

    // 创建一个新的类构造函数
    function Class() {
      // 如果当前不是初始化阶段，并且类中定义了 init 方法，则执行 init
      if (!initializing && this.init)
        this.init.apply(this, arguments);
    }

    // 将新类的原型指向扩展后的 prototype
    Class.prototype = prototype;

    // 修正类构造函数的 constructor 属性
    Class.prototype.constructor = Class;

    // 允许类继续被扩展
    Class.extend = arguments.callee;

    return Class;  // 返回扩展后的类
  };
})();

// 创建一个基础类 Animal
var Animal = Class.extend({
  init: function (name) {
    this.name = name;
  },
  speak: function () {
    console.log(this.name + " makes a sound.");
  }
});

// 创建一个继承自 Animal 的子类 Dog
var Dog = Animal.extend({
  init: function (name, breed) {
    // 调用父类构造函数
    this._super(name);  // 调用父类的 init 方法
    this.breed = breed;
  },
  speak: function () {
    // 调用父类的 speak 方法
    this._super();
    console.log(this.name + " barks.");
  }
});

// 创建 Dog 的实例
var myDog = new Dog("汪汪", "中华田园");
myDog.speak();  // 输出: 汪汪 makes a sound. 汪汪 barks.
```

### 2.9 模拟 Object.create 函数创建
```js
// 模拟 Object.create 函数
function create(o) {
  // 定义一个空构造函数 F
  function F() {}
  
  // 将传入的对象 o 设置为 F 的原型，F.prototype = o;
  // 这样 F 的实例将会继承对象 o 的属性
  F.prototype = o;
  
  // 通过 new F() 创建一个新的对象，并将其返回
  // 这个新对象的原型指向 o
  return new F();
}

var a = {
  a: 'a',  // 对象 a 的属性 a
  b: [1, 2, 3]  // 对象 a 的属性 b（数组）
};

// 使用自定义的 create 函数创建对象 b，b 的原型指向 a
var b = create(a);

// 使用 Object.create 函数创建对象 c，c 的原型指向 a
var c = Object.create(a);

console.log(b, c);
/*
// 输出 b 和 c 的值
b: F {}[[Prototype]]: Objecta: "a"b: (3) [1, 2, 3][[Prototype]]: Object 
c: {}[[Prototype]]: Objecta: "a"b: (3) [1, 2, 3][[Prototype]]: Object
*/
```

### 2.10 ECMAScript6 中的 class 使用
```js
// 定义一个 User 类
class User {
  // 构造函数，初始化对象的属性
  constructor(firstName, lastName) {
    this.firstName = firstName;  // 设置 firstName 属性
    this.lastName = lastName;    // 设置 lastName 属性
  }

  // 类的实例方法，用于返回完整姓名
  fullName() {
    return `${this.firstName} ${this.lastName}`;  // 拼接 firstName 和 lastName 作为 fullName
  }
}

// 创建 User 类的一个实例，传入参数 'Jarry' 和 'Li'
var user = new User('Jarry', 'Li');

// 调用实例方法 fullName，输出结果为 'Jarry Li'，并输出实例的类型
console.log(user.fullName(), typeof user);

// 检查 user 实例的构造函数和其是否为 User 类的实例
console.log(user.constructor, user instanceof User);

// 检查 user 是否有 firstName 属性，User.prototype 是否有 fullName 方法
console.log(user.hasOwnProperty('firstName'), User.prototype.hasOwnProperty('fullName'));

// 检查 user.__proto__（即 User.prototype）是否有 constructor 属性，以及 fullName 方法是否存在于 prototype 上
console.log(user.__proto__.constructor, user.__proto__.hasOwnProperty('fullName'));

/*
输出：
Jarry Li object
class User {
  // 构造函数，初始化对象的属性
  constructor(firstName, lastName) {
    this.firstName = firstName;  // 设置 firstName 属性
    this.lastName = lastName;    // 设置 lastName 属性
}

// 类的实例方法，用于返回完整姓名
fullN… true
true true
class User {
  // 构造函数，初始化对象的属性
  constructor(firstName, lastName) {
    this.firstName = firstName;  // 设置 firstName 属性
    this.lastName = lastName;    // 设置 lastName 属性
  }

  // 类的实例方法，用于返回完整姓名
  fullN… true
*/
```

### 2.11 JS 原型链详解
```js
// 定义一个构造函数 Foo
function Foo(y) {
  this.y = y;  // 设置实例的属性 y
}

// 给 Foo 的原型添加属性 x 和方法 calculate
Foo.prototype.x = 10;  // 原型上的属性 x，所有实例共享
Foo.prototype.calculate = function (z) {
  return this.x + this.y + z;  // 计算并返回 x + y + z 的结果
};

// 创建两个 Foo 的实例 b 和 c
var b = new Foo(20);  // b 的 y 属性是 20
var c = new Foo(30);  // c 的 y 属性是 30

console.log(
  // 检查 b 和 c 的原型是否指向 Foo.prototype
  b.__proto__ === Foo.prototype,  // true，b 的原型是 Foo.prototype
  c.__proto__ === Foo.prototype,  // true，c 的原型是 Foo.prototype

  // 检查 b 和 c 的 constructor 是否是 Foo
  b.constructor === Foo,  // true，b 的构造函数是 Foo
  c.constructor === Foo,  // true，c 的构造函数是 Foo
  
  // 检查 Foo.prototype.constructor 是否是 Foo
  Foo.prototype.constructor === Foo,  // true，Foo.prototype.constructor 还是 Foo

  // 检查 b.calculate 是否指向 Foo.prototype.calculate
  b.calculate === b.__proto__.calculate,  // true，b 的 calculate 方法来自 Foo.prototype
  
  // 检查 Foo.prototype.calculate 是否等于 b.__proto__.calculate
  b.__proto__.calculate === Foo.prototype.calculate,  // true，b 的 calculate 方法来自 Foo.prototype
  
  // 调用 calculate 方法，计算 b 和 c 的结果
  b.calculate(5),  // 20（b.y）+ 10（Foo.prototype.x）+ 5 = 35
  c.calculate(5)   // 30（c.y）+ 10（Foo.prototype.x）+ 5 = 45
);
// 输出：
// true true true true true true true 35 45
```

### 3. JavaScript 中的多态与重载
```js
// 定义 Parent 类
class Parent {
  // 构造函数，接受 name 参数并赋值给实例属性 name
  constructor(name) {
    this.name = name;
  }
  
  // 获取名字的方法
  getName() {
    return `Parent Name:${this.name}`;  // 返回父类的名字
  }
}

// 定义 Child 类，继承自 Parent
class Child extends Parent {
  // 构造函数，接受 name 和 age 参数，调用父类构造函数并设置实例属性
  constructor(name, age) {
    super(name);  // 调用父类的构造函数来设置 name
    this.age = age;  // 设置子类特有的 age 属性
  }
  
  // 获取父类和子类名字的方法
  getParentAndChildName() {
    // 调用父类的 getName 方法，并且加上子类的 getName 方法
    return super.getName() + this.getName();
  }
  
  // 重写父类的 getName 方法，支持多态
  getName() {
    // 如果传入参数个数为 1，调用子类的方法来返回父子类的名字
    if (arguments.length == 1) {
      return this.getParentAndChildName();
    } else {
      // 否则返回子类的名字
      return `Child Name:${this.name}`;
    }
  }
}

// 创建 Child 类的实例，name 为 'Jack'，age 为 20
var child = new Child('Jack', 20);

// 调用 getName 方法，输出子类的名字
console.log(child.getName());  // Child Name:Jack

// 调用 getName 方法，传入一个参数，输出父子类名字的组合
console.log(child.getName(1));  // Parent Name:JackChild Name:Jack
```

## 4. JavaScript 中的 this、call、apply、bind
```js
// 1. this 关键字
var age = 11;  // 定义全局变量 age

function Foo() {
  this.age = 22;  // 定义 Foo 构造函数中的属性 age
  this.getAge = function () {
    // getAge 方法返回 this.age 和外部的 age
    return this.age + '|' + age;
  }
  var getAge = this.getAge;  // 将 getAge 方法赋值给局部变量 getAge
  console.log('getAge()', getAge());  // 此时 this 指向全局对象，因此会输出全局 age 值 11
}
var foo = new Foo();  // 创建 Foo 的实例 foo
console.log('foo:', foo.getAge());  // 调用 foo 的 getAge 方法，输出其 age 值 22

// 输出说明：
// 第一个 console.log 会输出 "getAge() 22|11"，因为 getAge 方法调用时 this 指向了 Foo 实例，age 为 22。
// 第二个 console.log 会输出 "foo: 22|11"，调用 foo.getAge 时，this 指向的是 foo 实例，age 为 22。


// 2. 使用 call 方法
var age = 11;  // 全局变量 age

function Foo() {
  this.age = 22;  // Foo 构造函数中的属性 age
  this.getAge = function () {
    // getAge 方法返回 this.age 和外部的 age
    return this.age + '|' + age;
  }
  var getAge = this.getAge;  // 将 getAge 方法赋值给局部变量 getAge
  console.log('getAge()', getAge.call(this));  // 使用 call 方法明确指定 this
}
var foo = new Foo();  // 创建 Foo 的实例 foo
console.log('foo:', foo.getAge());  // 调用 foo 的 getAge 方法，输出其 age 值 22

// 输出说明：
// 第一个 console.log 会输出 "getAge() 22|11"，因为通过 call 明确指定了 this 指向 Foo 实例，age 为 22。
// 第二个 console.log 会输出 "foo: 22|11"，调用 foo.getAge 时，this 指向的是 foo 实例，age 为 22。


// 3. 使用 bind 方法
var Tom = {
  name: 'Tom',  // 定义对象 Tom
  age: 20
};
var Jarry = {
  name: 'Jarry',  // 定义对象 Jarry
  age: 19
};

function say(words) {
  // say 方法返回传入的 words 和 this 对象的 name 与 age
  return words + this.name + this.age;
}

var s1 = say.bind(Tom);  // 使用 bind 将 say 方法的 this 绑定为 Tom
var s2 = say.bind(Jarry);  // 使用 bind 将 say 方法的 this 绑定为 Jarry

console.log(s1('你好,'), s1('Hello,'));  // 输出绑定到 Tom 的结果
console.log(s2('你好,'), s2('Hello,'));  // 输出绑定到 Jarry 的结果

// 输出说明：
// s1('你好,') 会输出 "你好,Tom20"，s1('Hello,') 会输出 "Hello,Tom20"。
// s2('你好,') 会输出 "你好,Jarry19"，s2('Hello,') 会输出 "Hello,Jarry19"。


// 4. 简写版本：使用 Function.prototype.call 和 bind
var unboundJoin = Array.prototype.join;  // 获取数组 join 方法
var join = Function.prototype.call.bind(unboundJoin);  // 使用 call 和 bind 创建 join 方法的简写

console.log(join([1, 2, 3], '|'));  // 输出 "1|2|3"
console.log(join([1, 2, 3], '&'));  // 输出 "1&2&3"

// 5. 使用 bind 方法结合数组
function bindArrayJoinDot(flag, arr) {
  // 结合 bind 创建一个方法用于连接数组元素
  return join(this.concat(arr), flag || '.');
}
var joinDot = bindArrayJoinDot.bind([1, 2, 3], null);  // 绑定数组 [1, 2, 3] 到函数
console.log(joinDot([4, 5, 6]));  // 输出 "1.2.3.4.5.6"

// 输出说明：
// join([1, 2, 3], '|') 会输出 "1|2|3"，join([1, 2, 3], '&') 会输出 "1&2&3"。
// joinDot([4, 5, 6]) 会输出 "1.2.3.4.5.6"，这是因为 joinDot 结合了 [1, 2, 3] 和 [4, 5, 6]，并用 '.' 连接。
```

## 5. JavaScript 中的接口与抽象类
```js
// 1. 定义 Interface 构造函数，用于创建接口
function Interface(name, methods) {
  this.name = name;  // 接口的名称
  this.methods = [];  // 用于存储接口的方法名
  // 遍历 methods 数组，确保每个方法名是字符串类型
  for (var i = 0, l = methods.length; i < l; i++) {
    if (typeof methods[i] !== 'string') {
      throw new Error("方法名必须是字符串");  // 如果方法名不是字符串，则抛出错误
    }
    this.methods.push(methods[i]);  // 将方法名添加到接口的 methods 数组中
  }
}

// 2. 定义 Interface.ensureImplements 方法，确保对象实现了接口
Interface.ensureImplements = function (object, interface) {
  // 遍历接口的所有方法，检查对象是否实现了这些方法
  for (var j = 0, methodsLen = interface.methods.length; j < methodsLen; j++) {
    var method = interface.methods[j];
    if (typeof object[method] !== 'function') {
      throw new Error('接口:' + interface.name +
        ' 方法:' + method + ' 没有实现.');  // 如果对象没有实现某个方法，抛出错误
    }
  }
};

// 3. 创建一个名为 DrivableInterface 的接口，包含 drive 和 sound 方法
var DrivableInterface = new Interface('DrivableInterface',
  ['drive', 'sound']);

// 4. 创建一个抽象类 AbstractCar
class AbstractCar {
  constructor(name, color) {
    this.Engine = function () {};  // 抽象属性 Engine
    this.Wheel = function () {};  // 抽象属性 Wheel
    this.name = name;  // 汽车的名称
    this.color = color;  // 汽车的颜色
  }
  // 获取汽车信息的方法
  getInfo() {
    return this.name + '_' + this.color;
  }
}

// 5. 创建一个 Car 类继承自 AbstractCar
class Car extends AbstractCar {
  constructor(name, color) {
    super(name, color);  // 调用父类构造函数
    // 确保实现 DrivableInterface 接口
    Interface.ensureImplements(this, DrivableInterface);
  }
  // 实现接口中的 drive 方法
  drive() {
    return 'drive';
  }
  // 实现接口中的 sound 方法
  sound() {
    return '滴滴';
  }
};

// 6. 创建 Car 类的实例，并调用方法
var car = new Car('Bird', 'red');
console.log(DrivableInterface, car, car.getInfo(), car.drive());  // 输出接口、对象和方法结果
/*
// 输出:
Interface {name: 'DrivableInterface', methods: Array(2)} 
Car {name: 'Bird', color: 'red', Engine: ƒ, Wheel: ƒ}
'Bird_red'
'drive'
*/
```

## 6. JavaScript 多态模拟
```js
// 1. 定义 Animal 类，表示一个动物
class Animal {
  constructor(name) {
    this.name = name;  // 初始化动物的名称
  }

  // 动物发出的声音，默认输出 'AAA'
  sound() {
    console.log('AAA');
  }

  // 设置动物的名称
  setName(name) {
    this.name = name;
  }

  // 获取动物的名称
  getName() {
    return this.name;
  }
}

// 2. Animal 类的静态方法，创建特定类型的动物对象
var global = this;  // 获取全局对象（在浏览器中是 window）
Animal.make = function (type, params) {
  // 根据传入的 type 创建相应的动物类型对象
  return new global[type](params);
}

// 3. Animal 类的静态方法，用来调用动物的 sound 方法
Animal.makeSound = function (animal) {
  if (animal instanceof Animal) {
    animal.sound();  // 如果参数是 Animal 的实例，调用其 sound 方法
  }
}

// 4. Animal 类的静态方法，获取动物的名称
Animal.getName = function (animal) {
  if (animal instanceof Animal) {
    console.log(animal.name);  // 如果参数是 Animal 的实例，输出动物的名称
  }
}

// 5. 定义 Duck 类，继承自 Animal 类，并重写 sound 方法
var Duck = class Duck extends Animal {
  constructor(name) {
    super(name);  // 调用父类构造函数
  }
  sound() {
    console.log('DDD');  // 重写 sound 方法，输出 'DDD'
  }
}

// 6. 定义 Chicken 类，继承自 Animal 类，并重写 sound 方法
var Chicken = class Chicken extends Animal {
  constructor(name) {
    super(name);  // 调用父类构造函数
  }
  sound() {
    console.log('CCC');  // 重写 sound 方法，输出 'CCC'
  }
}

// 7. 创建 Chicken 和 Duck 的实例
var chicken = Animal.make('Chicken', 'chicken');
var duck = Animal.make('Duck', 'duck');

// 8. 调用 Animal 的静态方法
Animal.makeSound(chicken);  // 输出 'CCC'，因为鸡发出的声音是 'CCC'
Animal.getName(chicken);  // 输出 'chicken'，鸡的名称是 'chicken'

// 9. 修改鸡的名称
chicken.setName('chicken1');
Animal.getName(chicken);  // 输出 'chicken1'，因为鸡的名称已被修改

// 10. 调用 Animal 的静态方法
Animal.makeSound(duck);  // 输出 'DDD'，因为鸭发出的声音是 'DDD'
Animal.getName(duck);  // 输出 'duck'，鸭的名称是 'duck'
```

## 7. 继承与组合的对比
### 7.1 继承
```js
// 1. 定义 Fruit 类，表示水果
class Fruit {
  constructor(name) {
    this.name = name;  // 初始化水果的名称
  }

  // 定义 peel 方法，输出水果的名称
  peel() {
    console.log('peel:' + this.name);
  }
}

// 2. 定义 Banana 类，继承自 Fruit 类
class Banana extends Fruit {
  constructor(name) {
    super(name);  // 调用父类的构造函数，初始化水果名称
  }
}

// 3. 创建 Banana 类的实例，并调用 peel 方法
var banana = new Banana('Banana1');
banana.peel();  // 输出 'peel:Banana1'，调用继承自 Fruit 的 peel 方法
```

### 7.2 组合
```js
class Fruit {
  constructor(name) {
    this.name = name;
  }
  peel() {
    console.log('peel:' + this.name);
  }
}
class Banana {
  constructor(name) {
    this.fruit = new Fruit(name);
  }
  peel() {
    this.fruit.peel();
  }
}
var banana = new Banana('Banana2');
banana.peel();
```

### 7.3 组合改变1
```js
// 1. 定义 Fruit 类，表示水果
class Fruit {
  constructor(name) {
    this.name = name;  // 初始化水果的名称
  }

  // 定义 peel 方法，输出水果的名称
  peel() {
    console.log('peel:' + this.name);
  }
}

// 2. 定义 Banana 类，表示香蕉，使用组合方式持有一个 Fruit 实例
class Banana {
  constructor(name) {
    this.fruit = new Fruit(name);  // 创建一个 Fruit 实例并赋值给 fruit 属性
  }

  // 定义 peel 方法，调用 fruit 实例的 peel 方法
  peel() {
    this.fruit.peel();  // 调用组合的 Fruit 对象的 peel 方法
  }
}

// 3. 创建 Banana 类的实例，并调用 peel 方法
var banana = new Banana('Banana2');
banana.peel();  // 输出 'peel:Banana2'，调用 Fruit 的 peel 方法
```

### 7.4 组合改变2
```js
// 1. 定义 Peeler 类，表示一个削皮器，具有计数功能
class Peeler {
  constructor(count) {
    this.count = count;  // 初始化计数值
  }

  // 定义 peel 方法，输出皮削的次数
  peel() {
    console.log('peel count:' + this.getCount());  // 调用 getCount 输出计数
  }

  // 获取计数值
  getCount() {
    return this.count;
  }
}

// 2. 定义 Fruit 类，表示水果，具有名称和获取名称的功能
class Fruit {
  constructor(name) {
    this.name = name;  // 初始化水果的名称
  }

  // 获取水果的名称
  getName() {
    return this.name;
  }

  // 创建 Peeler 实例并返回
  peeler(count) {
    return new Peeler(count);  // 返回一个新的 Peeler 实例
  }
}

// 3. 定义 Banana 类，表示香蕉，组合了 Fruit 和 Peeler 类
class Banana {
  constructor(name, count) {
    this.fruit = new Fruit(name);  // 创建一个 Fruit 实例
    this.peeler = this.fruit.peeler(count);  // 使用 Fruit 实例创建一个 Peeler 实例
  }

  // 定义 peel 方法，调用水果的名称和削皮器的 peel 方法
  peel() {
    console.log('peel:' + this.fruit.getName());  // 输出水果的名称
    this.peeler.peel();  // 调用 Peeler 的 peel 方法，输出皮削次数
  }
}

// 4. 创建 Banana 类的实例，并调用 peel 方法
var banana = new Banana('Banana3', 33);
banana.peel();  // 输出 'peel:Banana3' 和 'peel count:33'
```

### 7.5 继承与组合联合
```js
// 1. 定义 Vehicle 类，表示车辆，具有名称和重量
class Vehicle {
  constructor(options) {
    this.name = options.name;  // 车辆名称
    this.weight = options.weight;  // 车辆重量
  }

  // 设置和获取名称
  setName(name) {
    this.name = name;
  }
  getName() {
    return this.name;
  }

  // 设置和获取重量
  setWeight(weight) {
    return this.weight = weight;
  }
  getWeight() {
    return this.weight;
  }
}

// 2. 定义 Engine 类，表示发动机
class Engine {
  launch() {
    console.log('this Engine is launching.');  // 启动发动机
  }
}

// 3. 定义 Wheel 类，表示轮子
class Wheel {
  rotate() {
    console.log('this Wheel is rotating.');  // 轮子旋转
  }
}

// 4. 定义 Car 类，继承自 Vehicle，组合 Engine 和 Wheel
class Car extends Vehicle {
  constructor(options) {
    super(options);  // 调用父类 Vehicle 的构造函数
    this.price = options.price;  // 车辆价格
    this.engine = options.engine || new Engine();  // 默认有一个 Engine 实例
    this.wheel = options.wheel || new Wheel();  // 默认有一个 Wheel 实例
    this.setBrand(options.brand);  // 设置品牌
  }

  // 启动汽车（发动机）
  launch() {
    this.engine.launch.call(this);  // 调用 Engine 类的 launch 方法
  }

  // 运行汽车
  run() {
    this.launch();  // 启动发动机
    this.wheel.rotate.call(this);  // 让轮子旋转
    console.log('The car is running.');  // 输出汽车正在运行
  }

  // 设置和获取价格
  setPrice(price) {
    this.price = price;
  }
  getPrice() {
    return this.price;
  }

  // 设置和获取品牌
  setBrand(brand) {
    this.brand = brand;
  }
  getBrand() {
    return this.brand;
  }
}

// 5. 定义 BMWCar 类，继承自 Car，添加系列和类型
class BMWCar extends Car {
  constructor(options) {
    options.brand = options.brand || 'BMW';  // 默认品牌为 'BMW'
    super(options);  // 调用 Car 类的构造函数
    this.series = options.series;  // 系列
    this.type = options.type;  // 类型
  }

  // 设置和获取系列
  setSeries(series) {
    this.series = series;
  }
  getSeries() {
    return this.series;
  }

  // 设置和获取类型
  setType(type) {
    this.type = type;
  }
  getType() {
    return this.type;
  }
}

// 6. 创建 BMWCar 实例并设置属性
var bmw5 = new BMWCar({
  name: 'bmw5',
  type: 'x',
  series: '5 series',  // BMW 5 系列
});
bmw5.setWeight(3000);  // 设置重量
bmw5.setPrice(1520000.00);  // 设置价格

// 输出实例属性和运行情况
console.log(bmw5, bmw5.getType(), bmw5.run());

/*
// 输出：
this Engine is launching.
this Wheel is rotating.
The car is running.
BMWCar {name: 'bmw5', weight: 3000, price: 1520000, engine: Engine, wheel: Wheel, …} 'x' undefined
*/
```

## 继承、组合与继承+组合对比

| 特性           | 继承                             | 组合                           | 继承 + 组合                        |
|----------------|----------------------------------|--------------------------------|-----------------------------------|
| **优点**       | - 简单易懂，代码层次清晰<br>- 可通过父类复用行为和属性       | - 提供更大的灵活性，类之间耦合度低<br>- 可以动态更换组合的组件         | - 结合了继承的代码复用和组合的灵活性<br>- 方便扩展和维护，功能可以灵活替换   |
| **缺点**       | - 继承的层级过深可能导致代码复杂<br>- 子类不能灵活更换父类功能       | - 可能需要更多的类和构造函数<br>- 不能像继承那样直接共享功能     | - 代码可能较复杂，需要管理继承与组合的关系<br>- 可能会增加理解和维护的难度         |
| **适用场景**   | - 当类之间存在明显的"是一个"关系<br>- 需要简化代码，减少重复时       | - 当需要灵活变更组件和功能时<br>- 对类功能有多个实现选项时     | - 当需要复用父类功能且希望灵活替换部分组件时<br>- 对象的行为和属性需要兼顾复用与灵活性时 |
| **实例**       | `Banana extends Fruit`           | `Banana has a Fruit`            | `BMWCar extends Car and has Engine, Wheel` |



### 继承与组合联合的好处

1. **灵活性**：
   - **继承**让 `BMWCar` 继承了 `Car` 的功能。
   - **组合**让 `Car` 类通过组合 `Engine` 和 `Wheel` 来实现不同功能。

   这样，我们可以复用 `Car` 的功能，并且根据需要灵活更换 `Engine` 或 `Wheel`。

2. **代码复用**：
   - **继承**：`BMWCar` 不用重复写 `Car` 类已有的方法。
   - **组合**：`Car` 不用重复写 `Engine` 和 `Wheel` 的方法，直接用组合的方式复用它们。

   这减少了重复代码，节省开发时间。

3. **可维护性**：
   - 修改 `Car` 类的功能，只需要改 `Car` 类，`BMWCar` 会自动继承新的功能。
   - 修改 `Engine` 或 `Wheel` 只需改这两个类，`Car` 不受影响。

   这样更容易维护和修改代码。

4. **扩展性**：
   - **继承**：可以很容易地在 `BMWCar` 类中增加新的功能。
   - **组合**：可以随时替换不同的 `Engine` 或 `Wheel`。