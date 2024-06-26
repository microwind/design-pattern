# 经典设计模式Design Pattern，不同语言实现

- 包括23种经典设计模式不同语言详解，结合实际场景，详细注释说明。每一行代码都经过检验，确保可靠。
- 采用流行的语言，包括C/Java/JavaScript/Python/TypeScript/Go等，尊重语言特性。
- 包含各种架构与设计思想，不断完善和补充，打造编程思想与架构设计的资源库。

## 设计模式结构图

<img src="https://pic2.zhimg.com/80/v2-93c9d173e41a204ae8bb8b391cbbe9b5_1440w.webp">

## 设计模式源码

### 创建型
- **[工厂模式（Factory Pattern） ](./factory-pattern)**，由工厂类提供统一的创建对象的方法。
[C](./factory-pattern/c) |[Java](./factory-pattern/java) | [JavaScript](./factory-pattern/js) | [Python](./factory-pattern/python) | [TypeScript](./factory-pattern/ts)  | [Go](./factory-pattern/go)

- **[抽象工厂模式（Abstract Factory Pattern） ](./abstract-factory)**，是一个超级工厂，用来创建其他工厂方法。
[C](./abstract-factory/c) | [Java](./abstract-factory/java) | [JavaScript](./abstract-factory/js) | [Python](./abstract-factory) | [TypeScript](./abstract-factory/ts)  | [Go](./abstract-factory/go)

- **[原型模式（Prototype Pattern） ](./prototype-pattern)**，利用clone()复制已有对象的实例。
[C](./prototype-pattern/c) | [Java](./prototype-pattern/java) | [JavaScript](./prototype-pattern/js) | [Python](./prototype-pattern/python) | [TypeScript](./prototype-pattern/ts)  | [Go](./prototype-pattern/go)

- **[建造者模式（Builder Pattern） ](./builder-pattern)**，利用多个简单对象逐步构建一个复杂对象，类似建造房子。
[C](./builder-pattern/c) | [Java](./builder-pattern/java) | [JavaScript](./builder-pattern/js) | [Python](./builder-pattern/python) | [TypeScript](./builder-pattern/ts)  | [Go](./builder-pattern/go)

- **[单例模式（Singleton Pattern） ](./singleton-pattern)**，保证创建的类只有一个实例，并提供一个访问该实例的全局节点。
[C](./singleton-pattern/c) | [Java](./singleton-pattern/java) | [JavaScript](./singleton-pattern/js) | [Python](./singleton-pattern/python) | [TypeScript](./singleton-pattern/ts)  | [Go](./singleton-pattern/go)

### 结构型
- **[适配器模式（Adapter Pattern） ](./adapter-pattern)**，为两个不兼容的接口提供专门兼容方案。
[C](./adapter-pattern/c) | [Java](./adapter-pattern/java) | [JavaScript](./adapter-pattern/js) | [Python](./adapter-pattern/python) | [TypeScript](./adapter-pattern/ts)  | [Go](./adapter-pattern/go)

- **[桥接模式（Bridge Pattern） ](./bridge-pattern)**，将类拆分为抽象和实现两个独立的层次结构进行解耦。
[C](./bridge-pattern/c) | [Java](./bridge-pattern/java) | [JavaScript](./bridge-pattern/js) | [Python](./bridge-pattern/python) | [TypeScript](./bridge-pattern/ts)  | [Go](./bridge-pattern/go)

- **[组合模式（Composite Pattern） ](./composite-pattern)**，依据树形结构来组合对象，用不同组件来构建某个部分或整体对象。
[C](./composite-pattern/c) | [Java](./composite-pattern/java) | [JavaScript](./composite-pattern/js) | [Python](./composite-pattern/python) | [TypeScript](./composite-pattern/ts)  | [Go](./composite-pattern/go)

- **[装饰器模式（Decorator Pattern） ](./decorator-pattern)**，将对象放入到一个特殊封装的对象中，赋予其新的能力。
[C](./decorator-pattern/c) | [Java](./decorator-pattern/java) | [JavaScript](./decorator-pattern/js) | [Python](./decorator-pattern/python) | [TypeScript](./decorator-pattern/ts)  | [Go](./decorator-pattern/go)

- **[外观模式（Facade Pattern） ](./facade-pattern)**，给现有的系统添加一个高层接口，隐藏子系统的复杂性。
[C](./facade-pattern/c) | [Java](./facade-pattern/java) | [JavaScript](./facade-pattern/js) | [Python](./facade-pattern/python) | [TypeScript](./facade-pattern/ts)  | [Go](./facade-pattern/go)

- **[享元模式（Flyweight Pattern） ](./flyweight-pattern)**，通过共享多个对象的相同状态，让有限的内存容量载入更多对象。
[C](./flyweight-pattern/c) | [Java](./flyweight-pattern/java) | [JavaScript](./flyweight-pattern/js) | [Python](./flyweight-pattern/python) | [TypeScript](./flyweight-pattern/ts)  | [Go](./flyweight-pattern/go)

- **[代理模式（Proxy Pattern） ](./proxy-pattern)**，用一个类来代理另一个类或几个类的功能。
[C](./proxy-pattern/c) | [Java](./proxy-pattern/java) | [JavaScript](./proxy-pattern/js) | [Python](./proxy-pattern/python) | [TypeScript](./proxy-pattern/ts)  | [Go](./proxy-pattern/go)

- **[过滤器模式（Filter Pattern） ](./filter-pattern)**，使用不同的标准条件来过滤一组对象，并通过逻辑运算的方式把各条件连接起来。
[C](./filter-pattern/c) | [Java](./filter-pattern/java) | [JavaScript](./filter-pattern/js) | [Python](./filter-pattern/python) | [TypeScript](./filter-pattern/ts)  | [Go](./filter-pattern/go)

### 行为型
- **[策略模式（Strategy Pattern） ](./strategy-pattern)**，将每一个算法策略封装到接口中，根据需要设定策略，使具体实现和策略解耦。
[C](./strategy-pattern/c) | [Java](./strategy-pattern/java) | [JavaScript](./strategy-pattern/js) | [Python](./strategy-pattern/python) | [TypeScript](./strategy-pattern/ts)  | [Go](./strategy-pattern/go)

- **[观察者模式（Observer Pattern） ](./observer-pattern)**，当主题对象的状态发生改变时，所有依赖对象都得到通知并被自动更新。
[C](./observer-pattern/c) | [Java](./observer-pattern/java) | [JavaScript](./observer-pattern/js) | [Python](./observer-pattern/python) | [TypeScript](./observer-pattern/ts)  | [Go](./observer-pattern/go)

- **[迭代器模式（Iterator Pattern） ](./iterator-pattern)**，给数据对象构建一套按顺序访问集合对象元素的方式。
[C](./iterator-pattern/c) | [Java](./iterator-pattern/java) | [JavaScript](./iterator-pattern/js) | [Python](./iterator-pattern/python) | [TypeScript](./iterator-pattern/ts)  | [Go](./iterator-pattern/go)

- **[模板方法模式（Template Method Pattern） ](./template-pattern)**，定义了一个抽象公开类，包含基本的算法骨架，而将一些步骤延迟到子类中。
[C](./template-pattern/c) | [Java](./template-pattern/java) | [JavaScript](./template-pattern/js) | [Python](./template-pattern/python) | [TypeScript](./template-pattern/ts)  | [Go](./template-pattern/go)

- **[责任链模式（Chain of Responsibility Pattern） ](./chain-responsibility)**，为请求创建了一个接收者对象的链，请求沿着处理者链进行发送和处理。
[C](./chain-responsibility/c) | [Java](./chain-responsibility/java) | [JavaScript](./chain-responsibility/js) | [Python](./chain-responsibility/python) | [TypeScript](./techain-responsibility/ts)  | [Go](./chain-responsibility/go)

- **[命令模式（Command Pattern） ](./command-pattern)**，把请求以命令的形式包裹在对象中，并传给调用对象。
[C](./command-pattern/c) | [Java](./command-pattern/java) | [JavaScript](./command-pattern/js) | [Python](./command-pattern/python) | [TypeScript](./command-pattern/ts)  | [Go](./command-pattern/go)

- **[备忘录模式（Memento Pattern） ](./memento-pattern)**，将对象的状态捕捉住，并以备忘录的形式存储起来，以便合适的时候还原。
[C](./memento-pattern/c) | [Java](./memento-pattern/java) | [JavaScript](./memento-pattern/js) | [Python](./memento-pattern/python) | [TypeScript](./memento-pattern/ts)  | [Go](./memento-pattern/go)

- **[状态模式（State Pattern） ](./state-pattern)**，类的行为是基于它的状态改变的，不同的状态下有不同的行为。
[C](./state-pattern/c) | [Java](./state-pattern/java) | [JavaScript](./state-pattern/js) | [Python](./state-pattern/python) | [TypeScript](./state-pattern/ts)  | [Go](./state-pattern/go)

- **[访问者模式（Visitor Pattern） ](./visitor-pattern)**，封装访问者类，把各元素类的操作集合起来，目的是将数据结构与数据操作分离。
[C](./visitor-pattern/c) | [Java](./visitor-pattern/java) | [JavaScript](./visitor-pattern/js) | [Python](./visitor-pattern/python) | [TypeScript](./visitor-pattern/ts)  | [Go](./visitor-pattern/go)

- **[中介者模式（Mediator Pattern） ](./mediator-pattern)**，它用一个中介对象来封装一系列的动作，以让对象之间进行交流。
[C](./mediator-pattern/c) | [Java](./mediator-pattern/java) | [JavaScript](./mediator-pattern/js) | [Python](./mediator-pattern/python) | [TypeScript](./mediator-pattern/ts)  | [Go](./mediator-pattern/go)

- **[解释器模式（Interpreter Pattern） ](./interpreter-pattern)**，实现了一个表达式接口，并能解释特定的上下文里面的变量和语句。
[C](./interpreter-pattern/c) [Java](./interpreter-pattern/java) | [JavaScript](./interpreter-pattern/js) | [Python](./interpreter-pattern/python) | [TypeScript](./interpreter-pattern/ts)  | [Go](./interpreter-pattern/go)

## 设计模式7大原则

### 1. 开闭原则(Open Closed Principle，OCP)
- 对扩展开放，对修改关闭。希望程序扩展功能的时候，通过开放的接口来实现，而不是修改代码。[例子](./design-principles/open-closed) | [反例](./design-principles/open-closed/java/src/OpenClosed_counter.java)

### 2. 单一职责原则(Single Responsibility Principle，缩写为SRP)
- 对一个类来说的，职责应该单一，只做一件或一类具体的事情。 [例子](./design-principles/single-responsibility) | [反例](./design-principles/single-responsibility/java/src/SingleResponsibility_counter.java)

### 3. 依赖倒置（也叫依赖反转）原则（Dependency inversion principle，DIP）
- 是开闭原则的基础。指针对接口编程，高层模块不应该依赖低层模块，二者都依赖于抽象而不依赖于具体实现编程。[例子](./design-principles/dependency-inversion) | [反例](./design-principles/dependency-inversion/java/src/DependencyInversion_counter.java)

### 4. 接口隔离原则（Interface Segregation Principle, 简称ISP）
- 一个类对另一个类的依赖应该建立在最小的接口上，不依赖不需要的接口。尽量强调降低依赖，降低耦合。[例子](./design-principles/interface-segregation) | [反例](./design-principles/interface-segregation/java/src/InterfaceSegregation_counter.java)

### 5. 组合/聚合复用原则（Composite/Aggregate Reuse Principle，CARP）
- 写代码会涉及到代码复用，尽量使用组合而少使用继承。大多数情况下组合可以替代继承。[例子](./design-principles/composite-reuse) | [反例](./design-principles/composite-reuse/java/src/CompositeReuse_counter.java)

### 6. 迪米特法则（Law of Demeter，LoD）
- 又称最少知道原则，一个实体应当尽量少地与其他实体之间发生相互作用，使得系统功能模块相对独立。[例子](./design-principles/law-of-demeter) | [反例](./design-principles/law-of-demeter/java/src/LawDemeter_counter.java)

### 7. 里氏代换原则（Liskov Substitution Principle，LSP）
- 任何父类出现的地方，子类也可以出现。子类可以实现父类的抽象方法，但不能覆盖父类的非抽象方法。[例子](./design-principles/liskov-substitution) | [反例](./design-principles/liskov-substitution/java/src/LiskovSubstitution_counter.java)

## 编程范式
### 面向过程编程[(Procedural Programming, PP)](./programming-paradigm/pp)
  是一种以事物为中心的编程思想，描述程序的每个步骤。主要关注“怎么做”。

### 面向对象编程[(Object-Oriented Programming, OOP)](./programming-paradigm/oop)
  是一种以对象为基础的编程思想，万物以类聚，确定每个类的职责。主要关注“谁来做”。
  [封装（Encapsulation）](./programming-paradigm/oop/encapsulation/) | [继承（Inheritance）](./programming-paradigm/oop/inheritance/) | [组合（Composition）](./programming-paradigm/oop/composition/) | [多态（Polymorphism）](./programming-paradigm/oop/polymorphism/)

### 函数式编程[(Functional programming, FP)](./programming-paradigm/fp)
  以函数作为一等公民的编程思想，通过纯函数和函数组合来构建程序。描述”做什么”，而不是“怎么做”。

### 面向切面编程[(Aspect-Oriented Programming, AOP)](./programming-paradigm/aop)
  通过预编译和动态插入，将代码挂载到类的指定方法、指定位置上，以便实现业务与基础功能的解耦。

### 事件驱动编程[(Event-Driven Programming, EDP)](./programming-paradigm/edp)
  核心思想是程序的执行流程由事件来驱动，即程序通过监听和响应事件来执行每一个步骤。

### 响应式编程[(Reactive Programming, RP)](./programming-paradigm/rp)
  是一种面向数据流和变化传播的编程范式。响应式编程通常会用在事件流相场景中，一旦触发一个事件，后续的事件会被依次触发。

## 编程设计思想
- MVC  [演示例子](./mvx/mvc)
- MVP  [演示例子](./mvx/mvp)
- MVVM [演示例子](./mvx/mvvm)

### [查看全部源码](https://microwind.github.io/design-pattern/)

### Contact 联系
欢迎共建 Welcome to join
- Wechat:  **springbuild**
- QQ: **12263539**
- Mail: lichunping@buaa.edu.cn
