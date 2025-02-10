# Design Patterns与Programming Paradigms [中文](./README.md)

- A detailed explanation of classic design patterns and programming paradigms, with practical examples and full comments.
- Implementations in different languages, including `C`, `Java`, `JavaScript`, `Python`, `Go`, etc., reflecting language features.
- Continuously updated and improved to create a resource library for design patterns and programming ideas.

## Design Patterns Structure

<img src="https://pic2.zhimg.com/80/v2-93c9d173e41a204ae8bb8b391cbbe9b5_1440w.webp">

## Design Patterns Source Code

### Creational Patterns
| Design Pattern | Description | C Source | Java Source | JS Source | Python Source | TypeScript Source | Go Source |
| --- | --- | --- | --- | --- | --- | --- | --- |
| **[Factory Pattern](./factory-pattern)** | Provides a unified method for creating objects by a factory class. | [C](./factory-pattern/c) | [Java](./factory-pattern/java) | [JavaScript](./factory-pattern/js) | [Python](./factory-pattern/python) | [TypeScript](./factory-pattern/ts) | [Go](./factory-pattern/go) |
| **[Abstract Factory Pattern](./abstract-factory)** | A super factory used to create other factory methods. | [C](./abstract-factory/c) | [Java](./abstract-factory/java) | [JavaScript](./abstract-factory/js) | [Python](./abstract-factory) | [TypeScript](./abstract-factory/ts) | [Go](./abstract-factory/go) |
| **[Prototype Pattern](./prototype-pattern)** | Uses clone() to copy an instance of an existing object. | [C](./prototype-pattern/c) | [Java](./prototype-pattern/java) | [JavaScript](./prototype-pattern/js) | [Python](./prototype-pattern/python) | [TypeScript](./prototype-pattern/ts) | [Go](./prototype-pattern/go) |
| **[Builder Pattern](./builder-pattern)** | Builds a complex object step by step using several simple objects, similar to building a house. | [C](./builder-pattern/c) | [Java](./builder-pattern/java) | [JavaScript](./builder-pattern/js) | [Python](./builder-pattern/python) | [TypeScript](./builder-pattern/ts) | [Go](./builder-pattern/go) |
| **[Singleton Pattern](./singleton-pattern)** | Ensures that a class has only one instance and provides a global node to access that instance. | [C](./singleton-pattern/c) | [Java](./singleton-pattern/java) | [JavaScript](./singleton-pattern/js) | [Python](./singleton-pattern/python) | [TypeScript](./singleton-pattern/ts) | [Go](./singleton-pattern/go) |

### Structural Patterns
| Design Pattern | Description | C Source | Java Source | JS Source | Python Source | TypeScript Source | Go Source |
| --- | --- | --- | --- | --- | --- | --- | --- |
| **[Adapter Pattern](./adapter-pattern)** | Provides a specialized compatibility solution for two incompatible interfaces. | [C](./adapter-pattern/c) | [Java](./adapter-pattern/java) | [JavaScript](./adapter-pattern/js) | [Python](./adapter-pattern/python) | [TypeScript](./adapter-pattern/ts) | [Go](./adapter-pattern/go) |
| **[Bridge Pattern](./bridge-pattern)** | Decouples an abstraction from its implementation by splitting the class into two independent hierarchies. | [C](./bridge-pattern/c) | [Java](./bridge-pattern/java) | [JavaScript](./bridge-pattern/js) | [Python](./bridge-pattern/python) | [TypeScript](./bridge-pattern/ts) | [Go](./bridge-pattern/go) |
| **[Composite Pattern](./composite-pattern)** | Combines objects in a tree structure to represent part-whole hierarchies. | [C](./composite-pattern/c) | [Java](./composite-pattern/java) | [JavaScript](./composite-pattern/js) | [Python](./composite-pattern/python) | [TypeScript](./composite-pattern/ts) | [Go](./composite-pattern/go) |
| **[Decorator Pattern](./decorator-pattern)** | Puts an object into a specially wrapped object to give it new capabilities. | [C](./decorator-pattern/c) | [Java](./decorator-pattern/java) | [JavaScript](./decorator-pattern/js) | [Python](./decorator-pattern/python) | [TypeScript](./decorator-pattern/ts) | [Go](./decorator-pattern/go) |
| **[Facade Pattern](./facade-pattern)** | Adds a high-level interface to an existing system to hide the complexity of its subsystems. | [C](./facade-pattern/c) | [Java](./facade-pattern/java) | [JavaScript](./facade-pattern/js) | [Python](./facade-pattern/python) | [TypeScript](./facade-pattern/ts) | [Go](./facade-pattern/go) |
| **[Flyweight Pattern](./flyweight-pattern)** | Shares identical states among multiple objects to load more objects into limited memory capacity. | [C](./flyweight-pattern/c) | [Java](./flyweight-pattern/java) | [JavaScript](./flyweight-pattern/js) | [Python](./flyweight-pattern/python) | [TypeScript](./flyweight-pattern/ts) | [Go](./flyweight-pattern/go) |
| **[Proxy Pattern](./proxy-pattern)** | Uses a class to proxy the functionality of another class or several classes. | [C](./proxy-pattern/c) | [Java](./proxy-pattern/java) | [JavaScript](./proxy-pattern/js) | [Python](./proxy-pattern/python) | [TypeScript](./proxy-pattern/ts) | [Go](./proxy-pattern/go) |
| **[Filter Pattern](./filter-pattern)** | Uses different standard conditions to filter a group of objects, connecting each condition logically. | [C](./filter-pattern/c) | [Java](./filter-pattern/java) | [JavaScript](./filter-pattern/js) | [Python](./filter-pattern/python) | [TypeScript](./filter-pattern/ts) | [Go](./filter-pattern/go) |

### Behavioral Patterns
| Design Pattern | Description | C Source | Java Source | JS Source | Python Source | TypeScript Source | Go Source |
| --- | --- | --- | --- | --- | --- | --- | --- |
| **[Strategy Pattern](./strategy-pattern)** | Encapsulates each algorithm strategy into an interface, allowing strategies to be set as needed, decoupling concrete implementations from strategies. | [C](./strategy-pattern/c) | [Java](./strategy-pattern/java) | [JavaScript](./strategy-pattern/js) | [Python](./strategy-pattern/python) | [TypeScript](./strategy-pattern/ts) | [Go](./strategy-pattern/go) |
| **[Observer Pattern](./observer-pattern)** | Notifies and automatically updates all dependent objects when the state of the subject object changes. | [C](./observer-pattern/c) | [Java](./observer-pattern/java) | [JavaScript](./observer-pattern/js) | [Python](./observer-pattern/python) | [TypeScript](./observer-pattern/ts) | [Go](./observer-pattern/go) |
| **[Iterator Pattern](./iterator-pattern)** | Provides a way to sequentially access the elements of a collection object. | [C](./iterator-pattern/c) | [Java](./iterator-pattern/java) | [JavaScript](./iterator-pattern/js) | [Python](./iterator-pattern/python) | [TypeScript](./iterator-pattern/ts) | [Go](./iterator-pattern/go) |
| **[Template Method Pattern](./template-pattern)** | Defines an abstract public class containing the basic structure of an algorithm, with some steps deferred to subclasses. | [C](./template-pattern/c) | [Java](./template-pattern/java) | [JavaScript](./template-pattern/js) | [Python](./template-pattern/python) | [TypeScript](./template-pattern/ts) | [Go](./template-pattern/go) |
| **[Chain of Responsibility Pattern](./chain-responsibility)** | Creates a chain of handler objects for processing requests, passing the request along the handler chain. | [C](./chain-responsibility/c) | [Java](./chain-responsibility/java) | [JavaScript](./chain-responsibility/js) | [Python](./chain-responsibility/python) | [TypeScript](./chain-responsibility/ts) | [Go](./chain-responsibility/go) |
| **[Command Pattern](./command-pattern)** | Wraps a request in an object and passes it to the invoking object. | [C](./command-pattern/c) | [Java](./command-pattern/java) | [JavaScript](./command-pattern/js) | [Python](./command-pattern/python) | [TypeScript](./command-pattern/ts) | [Go](./command-pattern/go) |
| **[Memento Pattern](./memento-pattern)** | Captures the state of an object and stores it in a memento for future restoration. | [C](./memento-pattern/c) | [Java](./memento-pattern/java) | [JavaScript](./memento-pattern/js) | [Python](./memento-pattern/python) | [TypeScript](./memento-pattern/ts) | [Go](./memento-pattern/go) |
| **[State Pattern](./state-pattern)** | Changes the behavior of a class based on its state, with different behaviors for different states. | [C](./state-pattern/c) | [Java](./state-pattern/java) | [JavaScript](./state-pattern/js) | [Python](./state-pattern/python) | [TypeScript](./state-pattern/ts) | [Go](./state-pattern/go) |
| **[Visitor Pattern](./visitor-pattern)** | Encapsulates a visitor class, collecting operations for element classes, aiming to separate data structures from data operations. | [C](./visitor-pattern/c) | [Java](./visitor-pattern/java) | [JavaScript](./visitor-pattern/js) | [Python](./visitor-pattern/python) | [TypeScript](./visitor-pattern/ts) | [Go](./visitor-pattern/go) |
| **[Mediator Pattern](./mediator-pattern)** | Uses a mediator object to encapsulate a series of actions and allow communication between objects. | [C](./mediator-pattern/c) | [Java](./mediator-pattern/java) | [JavaScript](./mediator-pattern/js) | [Python](./mediator-pattern/python) | [TypeScript](./mediator-pattern/ts) | [Go](./mediator-pattern/go) |
| **[Interpreter Pattern](./interpreter-pattern)** | Implements an expression interface and interprets variables and statements within a specific context. | [C](./interpreter-pattern/c) | [Java](./interpreter-pattern/java) | [JavaScript](./interpreter-pattern/js) | [Python](./interpreter-pattern/python) | [TypeScript](./interpreter-pattern/ts) | [Go](./interpreter-pattern/go) |

## Design Principles

| **Principle** | **Description** | **Example Code** | **Counter Example Code** |
| --- | --- | --- | --- |
| **[1. Open/Closed Principle (OCP)](./design-principles/open-closed)** | Open for extension, closed for modification. This means adding functionality through extensions without modifying existing code. | [Example](./design-principles/open-closed) | [Counter Example](./design-principles/open-closed/java/src/OpenClosed_counter.java) |
| **[2. Single Responsibility Principle (SRP)](./design-principles/single-responsibility)** | A class should have only one responsibility, and avoid multiple responsibilities. | [Example](./design-principles/single-responsibility) | [Counter Example](./design-principles/single-responsibility/java/src/SingleResponsibility_counter.java) |
| **[3. Dependency Inversion Principle (DIP)](./design-principles/dependency-inversion)** | High-level modules should not depend on low-level modules. Both should depend on abstractions. Concrete implementations should depend on abstract interfaces, not directly on concrete classes. | [Example](./design-principles/dependency-inversion) | [Counter Example](./design-principles/dependency-inversion/java/src/DependencyInversion_counter.java) |
| **[4. Interface Segregation Principle (ISP)](./design-principles/interface-segregation)** | A class should depend on the smallest interface possible, avoiding unnecessary interface dependencies. It emphasizes high cohesion and low coupling. | [Example](./design-principles/interface-segregation) | [Counter Example](./design-principles/interface-segregation/java/src/InterfaceSegregation_counter.java) |
| **[5. Composite/Aggregate Reuse Principle (CARP)](./design-principles/composite-reuse)** | When reusing code, prefer composition over inheritance. Composition is more flexible than inheritance in most cases. | [Example](./design-principles/composite-reuse) | [Counter Example](./design-principles/composite-reuse/java/src/CompositeReuse_counter.java) |
| **[6. Law of Demeter (LoD)](./design-principles/law-of-demeter)** | An entity should minimize its knowledge of other entities to reduce coupling between system modules. | [Example](./design-principles/law-of-demeter) | [Counter Example](./design-principles/law-of-demeter/java/src/LawDemeter_counter.java) |
| **[7. Liskov Substitution Principle (LSP)](./design-principles/liskov-substitution)** | Subclasses should be able to replace their base classes without affecting the program's correctness. Subclasses can override abstract methods of the base class but should not override non-abstract methods. | [Example](./design-principles/liskov-substitution) | [Counter Example](./design-principles/liskov-substitution/java/src/LiskovSubstitution_counter.java) |


## Programming Paradigms

| **Programming Paradigm** | **Description** | **Use Cases** |
| --- | --- | --- |
| **[Procedural Programming (PP)](./programming-paradigm/pp)** | Focuses on executing a sequence of steps, emphasizing program flow and each operation step, often implemented using functions or procedures. | Suitable for small projects or tasks with clear functionality, common in script programming or system tool development. |
| **[Object-Oriented Programming (OOP)](./programming-paradigm/oop)** | Organizes programs using classes and objects, emphasizing encapsulation, inheritance, composition, and polymorphism. Focuses on "who does what" rather than "how to do it". | Suitable for large and complex projects, especially those requiring good modularity and scalability. |
| **[Encapsulation](./programming-paradigm/oop/encapsulation/)** | Bundles data and the functions that operate on that data, controlling access from the outside to ensure data security. | Used to ensure data integrity and security, typically used in complex object modeling. |
| **[Inheritance](./programming-paradigm/oop/inheritance/)** | Uses the parent-child relationship between classes, where subclasses inherit properties and methods from the parent class to reuse code. | Used for building shared code and functional hierarchies, such as inheriting from multiple types of animal classes. |
| **[Composition](./programming-paradigm/oop/composition/)** | Reuses functionality by using a relationship between objects rather than inheritance. | Suitable for flexible modular designs, especially when inheritance relationships become too complex. |
| **[Polymorphism](./programming-paradigm/oop/polymorphism/)** | Allows the use of the same interface to call different objects, enabling dynamic method binding. | Commonly used to handle uniform interfaces for various types of objects, especially in event handling and strategy patterns. |
| **[Functional Programming (FP)](./programming-paradigm/fp)** | Describes programs using pure functions and immutable data, focusing on "what to do" rather than "how to do it". | Suitable for scenarios requiring high concurrency and maintainability, commonly used in data processing and stream processing systems. |
| **[Aspect-Oriented Programming (AOP)](./programming-paradigm/aop)** | Involves pre-compiling and dynamic insertion to mount code at specified points without modifying core business logic. | Suitable for decoupling concerns like logging, transaction management, etc., and typically used in enterprise applications. |
| **[Event-Driven Programming (EDP)](./programming-paradigm/edp)** | The execution flow of the program is driven by events, with operations triggered by listening and responding to events. | Common in GUI development, server-side applications, and real-time applications (like WebSocket, UI responses, etc.). |
| **[Reactive Programming (RP)](./programming-paradigm/rp)** | Focuses on data flows and propagation of changes, implementing reactive operations through asynchronous data streams that automatically respond to data changes. | Used for real-time data flows, UI updates, and asynchronous operations, commonly in real-time monitoring systems and stream data processing applications. |


## Programming Design Philosophies
| **Design Philosophy** | **Description** | **Use Cases** | **Example Code** |
| --- | --- | --- | --- |
| **[MVC (Model-View-Controller)](./mvx/mvc)** | MVC is a common design pattern that splits an application into three parts: the Model handles data, the View displays the user interface, and the Controller handles user input, updating both the model and the view. | Suitable for applications that need to separate the presentation layer from business logic, such as web development or desktop applications. It improves maintainability and scalability by separating concerns. | [Example](./mvx/mvc) |
| **[MVP (Model-View-Presenter)](./mvx/mvp)** | MVP is a variation of MVC, where the Controller is replaced by a Presenter. The Presenter handles passing data from the model to the view, and the view only displays content, not directly interacting with the model. | Suitable for applications requiring fine-grained control over view display and user interaction, especially when the view needs frequent updates or changes. | [Example](./mvx/mvp) |
| **[MVVM (Model-View-ViewModel)](./mvx/mvvm)** | MVVM is a design pattern that separates the view from its state and business logic. By introducing the ViewModel, it separates display logic from business logic, with the ViewModel providing data to the view and responding to user actions. | Suitable for applications requiring responsive data binding, such as modern front-end frameworks (like Angular, Vue.js) and desktop applications (like WPF). | [Example](./mvx/mvvm) |


### [View All Source Code](https://microwind.github.io/design-pattern/)

### Contact
Welcome to Join
- WeChat:  **springbuild**
- QQ: **12263539**
- Email: lichunping@buaa.edu.cn
