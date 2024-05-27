# 概述
编程范式是指编程中的基本风格或模式，它定义了如何组织和表达计算过程。不同的编程范式具有不同的理念和特点，不同的语言有适合自己风格的方式，在面对不同场景时也可以选择不同的编程范式。

# 范式
- 面向过程编程[(Procedural Programming, PP)](./pp)
  是一种基于过程（也称为函数、子程序或方法）的编程范式。在面向过程编程中，程序被分解为一系列的过程，每个过程执行特定的任务。这些过程通常按照顺序执行，直接操作程序的状态和数据。

- 面向对象编程[(Object-Oriented Programming, OOP)](./oop)
  将程序中的各种功能和数据封装成对象，通过类与对象之间的关系来组织和管理代码。OOP 提倡使用封装、继承和多态等特性，以提高代码的重用性和可维护性。
  [接口](./oop/interface/) [抽象](./oop/abstraction/) [封装](./oop/encapsulation/) [继承](./oop/inheritance/) [多态](./oop/polymorphism/) [组合](./oop/composition/) [聚合](./oop/aggregation/)

- 函数式编程[(Functional programming, FP)](./fp)
  将计算视为数学函数的求值过程，避免使用状态和可变数据，强调函数的纯粹性和不可变性。函数式编程语言通常支持高阶函数、匿名函数和不可变数据结构等特性，比如Erlang、clojure、Scala、F#，以及流行的Python、Ruby、Javascript等。

- 面向切面编程[(Aspect-Oriented Programming, AOP)](./aop)
  AOP 的核心思想是将横切关注点（Cross-Cutting Concerns）从核心业务逻辑中分离出来，动态地将代码切入到类的指定方法、指定位置上，以便统一管理和处理，旨在提高软件系统的模块化和可维护性。

- 事件驱动编程[(Event-Driven Programming, EDP)](./edp)
  基于事件的发生和处理来组织程序逻辑，程序的执行流程是由事件的发生和相应的处理程序来驱动的。事件驱动编程的核心是事件循环。

- 响应式编程[(Reactive Programming, RP)](./rp)
  通过使用异步数据流和函数式编程的思想，以响应事件和数据变化为中心，构建具有高度交互性和实时性的应用程序。响应式编程关注数据流的变化和处理方式，以提高代码的灵活性和响应性。