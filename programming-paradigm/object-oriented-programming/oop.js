/** 
 * JavaScript面向对象编程
 * JS是基于对象+函数式的编程语言，没有完全意义上的class那种数据类型。
 * es5没有class关键词，es6起新增了class关键字，但这也是一种语法糖，是通过prototype来模拟class。
 * 虽然没有class，但js中除了原始数据类型(string, number, boolean, undefined, null, symbol)外一切皆是对象(Object)
 * 每个Object都拥有prototype属性，并且可以通过new来实例化Function，从而可以轻松实现面向对象编程。
 * JS因为拥有基于对象和函数式的编程特性，从而使得编程能力非常灵巧而强大。
 */

// 以下通过一些实例来展示JS语言的面向对象编程特性，通过实际例子，将加深理解JS对象与原型继承等概念

// 创建类：静态 vs 原型

// 1. static object 静态对象
var child = (function () {
  var _private = '_private';
  var name = 'name';
  this.name = 'this.name';

  function getName() {
    return this.name + ',' + name;
  }
  console.log('getName():', getName())
  return {
    name: name,
    thisName: getName(),
    getName: getName
  }
})();
console.log(child.name, child.thisName, child.getName(), child._private);

// 2. create prototype class 原型对象模拟class
function Child() {};
Child.prototype.name = 'child';
Child.prototype.getName = function () {
  return 'child:' + this.name;
}
var c1 = new Child();
console.log('c1:', c1.name, c1.getName());
Child.prototype.name = 'child2';
var c2 = new Child();
c1.name = 'child3';
console.log('c2:', c2.name, c2.getName());
console.log('c1:', c1.name, c1.getName());

// 3. JavaScript中创建类-构造函数
// constructor class
function Child() {
  this.name = 'child';
  this.getName = function () {
    return 'child:' + this.name;
  }
};
var c1 = new Child();
console.log('c1:', c1.name, c1.getName());
var c2 = new Child();
c1.name = 'child3';
Child.name = 'Child';
console.log('c2:', c2.name, c2.getName());
console.log('c1:', c1.name, c1.getName());
c1.hasOwnProperty('name');
Child.prototype.hasOwnProperty('name');
Child.hasOwnProperty('name');

// 4. JavaScript中创建类-原型对象+构造函数
// create prototype class + constructor
function Child() {
  this._name = '_child';
};
Child._name = '_Child';
Child.prototype.name = 'child';
Child.prototype.getName = function () {
  return 'child:' + this.name;
}
var c1 = new Child();
console.log('c1:', c1.name, c1.getName());
Child.prototype.name = 'child2';
var c2 = new Child();
c1.name = 'child3';
console.log('c2:', c2.name, c2.getName());
console.log('c1:', c1.name, c1.getName());
console.log(c1.hasOwnProperty('name'), c1.hasOwnProperty('_name'));
console.log(c2.hasOwnProperty('name'), c2.hasOwnProperty('_name'));
console.log(Child.name, Child._name, Child.prototype.isPrototypeOf(c1));

/** JavaScript中对象继承实现方式 */

// 1. instancing 原型继承
function Parent(name) {
  this.name = name;
};
Parent.prototype.getName = function () {
  return this.name;
};
var c1 = new Parent('name:c1');
var c2 = new Object();
c2.__proto__ = Parent.prototype;
c2.constructor = Parent;
Parent.call(c2, 'name:c2');
var c3 = Object.create(Parent.prototype, {
  name: {
    value: 'name:c3'
  }
});
console.log(c1, c1.getName(), c1 instanceof Parent, Parent.prototype.isPrototypeOf(c1), c1.constructor);
console.log(c2, c2.getName(), c2 instanceof Parent, Parent.prototype.isPrototypeOf(c2), c2.constructor);
console.log(c3, c3.getName(), c3 instanceof Parent, Parent.prototype.isPrototypeOf(c3), c3.constructor);

// 2. JavaScript构造函数继承
// constructor inherits
function Parent(name, age) {
  this.name = name;
  this.age = age;
  this.getName = function () {
    return 'parent:' + this.name;
  }
  this.getAge = function () {
    return 'parent:' + this.age;
  }
};

function Child() {
  Parent.apply(this, arguments);
  this.getAge = function () {
    return 'child:' + this.age;
  }
};
var child1 = new Child('child1', 10);
console.log(child.getName(), child.getAge());

// 3. JavaScript对象扩展继承
// extend
function extend(to, from, deep) {
  function isObjectOrArray(obj) {
    var toString = Object.prototype.toString;
    var isObject = ('[object Object]' == toString.call(obj));
    var isArray = ('[object Array]' == toString.call(obj));
    return (isObject || isArray);
  }
  for (var item in from) {
    if (from.hasOwnProperty(item)) {
      if (deep && isObjectOrArray(from[item])) {
        to[item] = extend(to[item], from[item], deep);
      } else {
        to[item] = from[item];
      }
    }
  }
  return to;
}
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
// extend(a, b);
extend(a, b, true);

// 4. JavaScript原型继承
// inherits new
function Parent(name) {
  this.name = name;
}
Parent.prototype.getName = function () {
  return 'parent:' + this.name;
}
Parent.prototype.getAge = function () {
  return 'parent:' + this.age;
}

function Child(name) {
  // Parent.apply(this, arguments);
  this.age = '20';
}
Child = Parent.prototype.constructor;
Child.prototype = new Parent();
Child.prototype = Parent.prototype;
Child.prototype.getName = function () {
  return 'child:' + this.name;
}
var c1 = new Child('child1');
console.log('c1:', c1.getName(), c1.getAge());
Child.prototype.name = 'child2';
var c2 = new Child('child2-b');
console.log('c2:', c2.getName(),
  c2.__proto__.getName());

// inherits create
/*
var Parent = { name: 'parent', getName: function() {
     return this.name;
   }
};
var child1 = Object.create(Parent, { name: {value: 'child1'}});
*/
function Parent(name) {
  this.name = name || 'parent';
};
Parent.prototype.getName = function () {
  return 'parent:' + this.name;
};
var child1 = Object.create(Parent.prototype, {
  name: {
    value: 'child1'
  }
});
console.log(child1.getName(), child1);

function Child(name) {
  Parent.apply(this, arguments);
};
Child.prototype = Object.create(Parent.prototype, {
  getName: {
    value: function () {
      return 'child.prototype:' + this.name;
    }
  }
});
var child2 = new Child('child2');
console.log(child2.getName(), child2);

// 5. JavaScript原型继承注意事项
// 1) 改写prototype会更改constructor
function Parent() {}
Parent.prototype = {
  getName: function () {
    return 'child:' + this.name;
  }
};

function Child() {}
Child.prototype.getName = function () {
  return 'child:' + this.name;
};
var parent = new Parent();
var child = new Child();
console.log(parent.constructor, child.constructor);

// 2) prototype追加方法，而不是覆盖全部
function Parent() {}
Parent.prototype = {
  getName: function () {
    return 'child:' + this.name;
  }
};

function Child() {}
Child.prototype.getName = function () {
  return 'child:' + this.name;
};
var parent = new Parent();
var child = new Child();
console.log(parent.constructor, child.constructor);
Child.prototype = new Parent();
var child = new Child();
console.log(parent.constructor, child.constructor);

// 3) 重置constructor的问题
function Parent() {}
Parent.prototype.getName = function () {
  return 'parent:' + this.name;
};

function Child() {}
Child.prototype = new Parent();
Child.prototype.constructor = Child;
var parent = new Parent();
var child = new Child();
console.log(parent.constructor, child.constructor);

// 继承之后要更改prototype
function Parent(name) {}
Parent.prototype = {
  getName: function () {
    return 'parent:' + this.name;
  }
};

function Child() {
  this.name = name;
}
Child.prototype = new Parent();
var child = new Child();
console.log(child instanceof Child, child.getName());
Child.prototype = {
  getName: function () {
    return 'child:' + this.name;
  }
};
console.log(child instanceof Child, child.getName());


// 4) 新建空function prototype继承
function extend(Child, Parent) {
  var F = function () {};
  F.prototype = Parent.prototype;
  Child.prototype = new F();
  Child.prototype.constructor = Child;
  Child.super = Parent.prototype;
}

function A(name) {
  this.name = name;
};

function B() {};
B.prototype.getName = function () {
  return 'B:' + this.name;
};
extend(A, B);
var a = new A('a');
console.log(a, a.getName(), a.constructor.super);
console.log(a.constructor, a instanceof A, a instanceof B);

// var Child = {};
// console.log(A.constructor);  // output:
// console.log(B.constructor);  // output:
// var a = new A();           
// var b = new A();           
// b.constructor = A.constructor;
// console.log(a.constructor == A);  // output:
// console.log(b instanceof a.constructor);     // output:
// console.log(a.constructor == b.constructor);  // output:

// 6. 原型继承+复制constructor完整例子
function inherits(Child, Parent) {
  var ChildProto = Child.prototype;
  var ParentProto = Parent.prototype;

  // create a temp clazz, call parent constructor
  // apply or execute constructor to extend constructor
  // apply such as copy constructor to Child instance, execution will copy it to Child constructor
  /* function Super() { Parent.apply(this, arguments); } */
  function Super() {}
  Super.constructor = ParentProto.constructor();

  // assignment prototype
  Super.prototype = ParentProto;

  // Child = ParentProto.constructor;
  // instance temp clazz for Child prototype
  Child.prototype = new Super();
  // copy prototy from th origin Child
  for (var item in ChildProto) {
    Child.prototype[item] = ChildProto[item];
  }
  Child.__super__ = ParentProto;
  // reset Child constructor
  Child.prototype.constructor = Child;
  return Child;
}

function Parent() {
  this.title = 'Parent';
  this.name = 'Parent';
}
Parent.prototype.alias = 'Father';
Parent.prototype.getParentName = function () {
  return 'Parent:' + this.name;
}

function Child() {
  this.name = 'Child';
}
Child.prototype.alias = 'Son';
Child.prototype.getName = function () {
  return 'Child:' + this.name;
}
Child.prototype.getParentAlias = function () {
  return 'getParentAlias:' + Child.__super__.alias;
}
Parent.prototype.getParentName = function () {
  return 'getParentName:' + Child.__super__.name;
}
inherits(Child, Parent);
var c3 = new Child();
Parent.prototype.alias = 'FatherChanged';
console.log(c3, c3.constructor, c3.__proto__, c3.prototype);
console.log(Child.prototype.isPrototypeOf(c3),
  Parent.prototype.isPrototypeOf(c3), Object.getPrototypeOf(c3));


// 7. 来自crockford的原型继承例子
// http://www.crockford.com/javascript/inheritance.html
Function.prototype.method = function (name, func) {
  this.prototype[name] = func;
  return this;
};
Function.method('inherits', function (parent) {
  this.prototype = new parent();
  var d = {},
    p = this.prototype;
  this.prototype.constructor = parent;
  this.method('uber', function uber(name) {
    if (!(name in d)) {
      d[name] = 0;
    }
    var f, r, t = d[name],
      v = parent.prototype;
    if (t) {
      while (t) {
        v = v.constructor.prototype;
        t -= 1;
      }
      f = v[name];
    } else {
      f = p[name];
      if (f == this[name]) {
        f = v[name];
      }
    }
    d[name] += 1;
    r = f.apply(this, Array.prototype.slice.apply(arguments, [1]));
    d[name] -= 1;
    return r;
  });
  return this;
});

// 8. 来自john的原型继承完整例子
// http://ejohn.org/blog/simple-javascript-inheritance/
(function () {
  var initializing = false,
    fnTest = /xyz/.test(function () {
      xyz;
    }) ? /\b_super\b/ : /.*/;

  // The base Class implementation (does nothing)
  this.Class = function () {};

  // Create a new Class that inherits from this class
  Class.extend = function (prop) {
    var _super = this.prototype;

    // Instantiate a base class (but only create the instance,
    // don't run the init constructor)
    initializing = true;
    var prototype = new this();
    initializing = false;

    // Copy the properties over onto the new prototype
    for (var name in prop) {
      // Check if we're overwriting an existing function
      prototype[name] = typeof prop[name] == "function" &&
        typeof _super[name] == "function" && fnTest.test(prop[name]) ?
        (function (name, fn) {
          return function () {
            var tmp = this._super;

            // Add a new ._super() method that is the same method
            // but on the super-class
            this._super = _super[name];

            // The method only need to be bound temporarily, so we
            // remove it when we're done executing
            var ret = fn.apply(this, arguments);
            this._super = tmp;

            return ret;
          };
        })(name, prop[name]) :
        prop[name];
    }

    // The dummy class constructor
    function Class() {
      // All construction is actually done in the init method
      if (!initializing && this.init)
        this.init.apply(this, arguments);
    }

    // Populate our constructed prototype object
    Class.prototype = prototype;

    // Enforce the constructor to be what we expect
    Class.prototype.constructor = Class;

    // And make this class extendable
    Class.extend = arguments.callee;

    return Class;
  };
})();

// 8. 简单版JS继承例子
// http://ejohn.org/blog/simple-javascript-inheritance/
(function () {
  var initializing = false,
    fnTest = /xyz/.test(function () {
      xyz;
    }) ? /\b_super\b/ : /.*/;
  this.Class = function () {};
  Class.extend = function (prop) {
    var _super = this.prototype;
    initializing = true;
    var prototype = new this();
    initializing = false;
    for (var name in prop) {
      prototype[name] = typeof prop[name] == "function" &&
        typeof _super[name] == "function" && fnTest.test(prop[name]) ?
        (function (name, fn) {
          return function () {
            var tmp = this._super;
            this._super = _super[name];
            var ret = fn.apply(this, arguments);
            this._super = tmp;
            return ret;
          };
        })(name, prop[name]) :
        prop[name];
    }

    function Class() {
      if (!initializing && this.init)
        this.init.apply(this, arguments);
    }
    Class.prototype = prototype;
    Class.prototype.constructor = Class;
    Class.extend = arguments.callee;
    return Class;
  };
})();



// 9. 模拟Object.create函数创建
function create(o) {
  function F() {}
  F.prototype = o;
  return new F();
}
var a = {
  a: 'a',
  b: [1, 2, 3]
};
var b = create(a);
var c = Object.create(a);
console.log(b, c);
// https://developer.mozilla.org/zh-CN/docs/Web/JavaScript/Reference/Global_Objects/Object/create
if (typeof Object.create != 'function') {
  // Production steps of ECMA-262, Edition 5, 15.2.3.5
  // Reference: http://es5.github.io/#x15.2.3.5
  Object.create = (function () {
    //为了节省内存，使用一个共享的构造器
    function Temp() {}

    // 使用 Object.prototype.hasOwnProperty 更安全的引用 
    var hasOwn = Object.prototype.hasOwnProperty;

    return function (O) {
      // 1. 如果 O 不是 Object 或 null，抛出一个 TypeError 异常。
      if (typeof O != 'object') {
        throw TypeError('Object prototype may only be an Object or null');
      }

      // 2. 使创建的一个新的对象为 obj ，就和通过
      //    new Object() 表达式创建一个新对象一样，
      //    Object是标准内置的构造器名
      // 3. 设置 obj 的内部属性 [[Prototype]] 为 O。
      Temp.prototype = O;
      var obj = new Temp();
      Temp.prototype = null; // 不要保持一个 O 的杂散引用（a stray reference）...

      // 4. 如果存在参数 Properties ，而不是 undefined ，
      //    那么就把参数的自身属性添加到 obj 上，就像调用
      //    携带obj ，Properties两个参数的标准内置函数
      //    Object.defineProperties() 一样。
      if (arguments.length > 1) {
        // Object.defineProperties does ToObject on its first argument.
        var Properties = Object(arguments[1]);
        for (var prop in Properties) {
          if (hasOwn.call(Properties, prop)) {
            obj[prop] = Properties[prop];
          }
        }
      }

      // 5. 返回 obj
      return obj;
    };
  })();
}

// https://developer.mozilla.org/en/docs/Web/JavaScript/Reference/Global_Objects/Object/create
// Usage:
// Child.prototype = create(Parent.prototype);
if (typeof Object.create != 'function') {
  Object.create = (function () {
    var Temp = function () {};
    return function (o) {
      Temp.prototype = o;
      var result = new Temp();
      Temp.prototype = null;
      return result;
    };
  })();
}

// actually just does
function Foo() {}
var o = new Foo();
var o = new Object();
o. [
  [Prototype]
] = Foo.prototype;
Foo.call(o);

// 10. ECMAScript6 中的class使用
class User {
  constructor(firstName, lastName) {
    this.firstName = firstName;
    this.lastName = lastName;
  }

  fullName() {
    return `${this.firstName} ${this.lastName}`;
  }
}

var user = new User('Jarry', 'Li');
console.log(user.fullName(), typeof user);
console.log(user.constructor, user instanceof User);
console.log(user.hasOwnProperty('firstName'), User.prototype.hasOwnProperty('fullName'));
console.log(user.__proto__.constructor, user.__proto__.hasOwnProperty('fullName'));

// ECMAScript6 inherits
class Parent {
  constructor(name) {
    this.name = name;
  }
  getName() {
    return `Parent Name:${this.name}`;
  }
}
class Child extends Parent {
  constructor(name, age) {
    super(name, age);
    this.age = age;
  }
  getAge() {
    return `Child Age: ${this.age}`;
  }
}
var child = new Child('Tom', 19);
console.log(Object.getPrototypeOf(Child) === Parent, child instanceof Parent);
console.log(child.hasOwnProperty('name'), Child.prototype.hasOwnProperty('name'));
console.log(child.__proto__.hasOwnProperty('getName'), Child.prototype.hasOwnProperty('getAge'));
console.log(child, child.getName(), child.getAge());
console.log(typeof child, child.constructor, child.__proto__.constructor);


// 11. JS原型链详解
// @see
// http://dmitrysoshnikov.com/ecmascript/javascript-the-core/
function Foo(y) {
  this.y = y;
}
Foo.prototype.x = 10;
Foo.prototype.calculate = function (z) {
  return this.x + this.y + z;
};
var b = new Foo(20);
var c = new Foo(30);
console.log(
  b.__proto__ === Foo.prototype,
  c.__proto__ === Foo.prototype,
  b.constructor === Foo,
  c.constructor === Foo,
  Foo.prototype.constructor === Foo,
  b.calculate === b.__proto__.calculate,
  b.__proto__.calculate === Foo.prototype.calculate,
  b.calculate(5), c.calculate(5)
);

// 面向对象里的重写与重载
class Parent {
  constructor(name) {
    this.name = name;
  }
  getName() {
    return `Parent Name:${this.name}`;
  }
}
class Child extends Parent {
  constructor(name, age) {
    super(name, age);
    this.age = age;
  }
  getParentAndChildName() {
    return super.getName() + this.getName();
  }
  getName() {
    if (arguments.length == 1) {
      return this.getParentAndChildName();
    } else {
      return `Child Name:${this.name}`;
    }
  }
}
var child = new Child('Jack', 20);
console.log(child.getName())
console.log(child.getName(1));

// 11. 理解this,call,apply,bind
// this
var age = 11;

function Foo() {
  this.age = 22;
  this.getAge = function () {
    return this.age + '|' + age;
  }
  var getAge = this.getAge;
  console.log('getAge()', getAge());
}
var foo = new Foo();
console.log('foo:', foo.getAge());

// apply
var age = 11;

function Foo() {
  this.age = 22;
  this.getAge = function () {
    return this.age + '|' + age;
  }
  var getAge = this.getAge;
  console.log('getAge()', getAge.call(this));
}
var foo = new Foo();
console.log('foo:', foo.getAge());

// bind
var Tom = {
  name: 'Tom',
  age: 20
};
var Jarry = {
  name: 'Jarry',
  age: 19
}

function say(words) {
  return words + this.name + this.age;
}
var s1 = say.bind(Tom);
var s2 = say.bind(Jarry);
console.log(s1('你好,'), s1('Hello,'));
console.log(s2('你好,'), s2('Hello,'));

// 简写
var unboundJoin = Array.prototype.join;
var join = Function.prototype.call.bind(unboundJoin);
console.log(join([1, 2, 3], '|'));
console.log(join([1, 2, 3], '&'));

function bindArrayJoinDot(flag, arr) {
  return join(this.concat(arr), flag || '.');
}
var joinDot = bindArrayJoinDot.bind([1, 2, 3], null);
console.log(joinDot([4, 5, 6]));

// 看下java里面interface and abstract
/*
public interface Drivable {
  public void drive();
  public void sound();
}
public abstract class AbstractCar {
  public abstract Engine getEngine();
  public abstract Wheel getWheel();
}
public class Car extends AbstractCar implements Drivable {
  public void drive() {
    throw new UnsupportedOperationException();
  }
  public void sound() {}
  @Override
  public Engine getWheel() {}
}
*/

// 12. 用javascript模拟interface
// https://ryot.gitbooks.io/pro-javascript-design-patterns/content/chapter2.html
// http://www.cnblogs.com/softlover/archive/2012/07/20/2601067.html
function Interface(name, methods) {
  this.name = name;
  this.methods = [];
  for (var i = 0, l = methods.length; i < l; i++) {
    if (typeof methods[i] !== 'string') {
      throw new Error("方法名必须是字符串");
    }
    this.methods.push(methods[i]);
  }
}
Interface.ensureImplements = function (object, interface) {
  for (var j = 0, methodsLen = interface.methods.length; j < methodsLen; j++) {
    var method = interface.methods[j];
    if (typeof object[method] !== 'function') {
      throw new Error('接口:' + interface.name +
        ' 方法:' + method + ' 没有实现.');
    }
  }
};
var DrivableInterface = new Interface('DrivableInterface',
  ['drive', 'sound']);

class AbstractCar {
  constructor(name, color) {
    this.Engine = function () {};
    this.Wheel = function () {};
    this.name = name;
    this.color = color;
  }
  getInfo() {
    return this.name + this.color;
  }
}
class Car extends AbstractCar {
  constructor(name, color) {
    super(name, color);
    Interface.ensureImplements(this, DrivableInterface);
  }
  drive() {
    console.log('drive');
  }
  sound() {
    return '滴滴';
  }
};
var car = new Car('Bird', 'red');
console.log(DrivableInterface, car, car.getInfo(), car.drive());



// 13. JavaScript 函数参数传递
function add(a, b, process) {
  process = process || function (a, b) {
    return a + b;
  }
  return process(a, b);
}
add(5, 5);
add(4.8, 5.3, function (a, b) {
  return Math.round(a) + Math.floor(b);
});

// 14. javascript多态之模拟类型
class Animal {
  constructor(name) {
    this.name = name;
  }
  sound() {
    console.log('AAA');
  }
  setName(name) {
    this.name = name;
  }
  getName(name) {
    return this.name;
  }
}
var global = this;
Animal.make = function (type, params) {
  return new global[type](params);
}
Animal.makeSound = function (animal) {
  if (animal instanceof Animal) {
    animal.sound();
  }
}
Animal.getName = function (animal) {
  if (animal instanceof Animal) {
    console.log(animal.name);
  }
}

var Duck = class Duck extends Animal {
  constructor(name) {
    super(name);
  }
  sound() {
    console.log('DDD');
  }
}
var Chicken = class Chicken extends Animal {
  constructor(name) {
    super(name);
  }
  sound() {
    console.log('CCC');
  }
}

var chicken = Animal.make('Chicken', 'chicken');
var duck = Animal.make('Duck', 'duck');
Animal.makeSound(chicken);
Animal.getName(chicken);
chicken.setName('chicken1');
Animal.getName(chicken);
Animal.makeSound(duck);
Animal.getName(duck);

// 15. JS里继承与组合对比
// 继承
class Fruit {
  constructor(name) {
    this.name = name;
  }
  peel() {
    console.log('peel:' + this.name);
  }
}
class Banana extends Fruit {
  constructor(name) {
    super(name);
  }
}
var banana = new Banana('Banana1');
banana.peel();
// 组合
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

// 组合改变1
class Peeler {
  peel() {
    console.log('peel:' + this.name);
  }
}
class Banana {
  constructor(name, peeler) {
    this.name = name;
    this.peeler = peeler || new Peeler();
  }
  peel() {
    this.peeler.peel.call(this);
  }
}
var banana = new Banana('Banana3', new Peeler());
banana.peel();

// 组合改变2
class Peeler {
  constructor(count) {
    this.count = count;
  }
  peel() {
    console.log('peel count:' + this.getCount());
  }
  getCount() {
    return this.count;
  }
}
class Fruit {
  constructor(name) {
    this.name = name;
  }
  getName() {
    return this.name;
  }
  peeler(count) {
    return new Peeler(count);
  }
}
class Banana {
  constructor(name, count) {
    this.fruit = new Fruit(name);
    this.peeler = this.fruit.peeler(count);
  }
  peel() {
    console.log('peel:' + this.fruit.getName());
    this.peeler.peel();
  }
}
var banana = new Banana('Banana3', 33);
banana.peel();

// 16. 继承与组合联合
class Vehicle {
  constructor(options) {
    this.name = options.name;
    this.weight = options.weight;
  }
  setName(name) {
    this.name = name;
  }
  getName() {
    return this.name;
  }
  setWeight(weight) {
    return this.weight = weight;
  }
  getWeight() {
    return this.weight;
  }
}

class Engine {
  launch() {
    console.log('this Engine is launching.');
  }
}
class Wheel {
  rotate() {
    console.log('this Wheel is rotating.');
  }
}

class Car extends Vehicle {
  constructor(options) {
    super(options);
    this.price = options.price;
    this.engin = options.engin || new Engine();
    this.wheel = options.wheel || new Wheel();
    this.setBrand(options.brand);
  }
  launch() {
    this.engin.launch.call(this);
  }
  run() {
    this.launch();
    this.wheel.rotate.call(this);
    console.log('The car is running.');
  }
  setPrice(price) {
    this.price = price;
  }
  getPrice(price) {
    return this.price;
  }
  setBrand(brand) {
    this.brand = brand;
  }
  getBrand() {
    return this.brand;
  }
}

class BMWCar extends Car {
  constructor(options) {
    options.brand = options.brand || 'BMW';
    super(options);
    this.series = options.series;
    this.type = options.type;
  }
  setSeries(series) {
    this.series = series;
  }
  getSeries() {
    return this.series;
  }
  setType(type) {
    this.type = type;
  }
  getType() {
    return this.type;
  }
}

var bmw5 = new BMWCar({
  name: 'bmw5',
  type: 'x'
});
bmw5.setWeight(3000);
bmw5.setPrice(1520000.00);
console.log(bmw5, bmw5.getType(), bmw5.run());