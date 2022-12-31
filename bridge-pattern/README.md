# 简介
桥接模式（Bridge Pattern）是一种结构型设计模式，它通过提供抽象化和实现化之间的桥接结构，来实现二者的解耦。

如果你希望在几个独立维度上扩展一个类，或者你想要拆分、重组一个具有多重功能的复杂类（例如能与多个数据库服务器进行交互的类），或者你想在运行时切换不同的实现方法，可以使用桥接模式。

# 作用
1. 在有多种可能会变化的情况下，用继承扩展起来不灵活.，桥接可以解决类似问题。
2. 桥接模式提高了系统的可扩展性，在两个变化维度中任意扩展一个维度，都不需要修改原有系统。

# 实现步骤
1. 定义一个工具接口，供不同工具类来实现。建立多个具体工具类实现基础工具接口。
2. 定义一个基础抽象类，里面聚合了工具接口，相当于桥接。
3. 再重新定义一个新抽象类，继承自基础抽象类，并补充一些方法。
4. 建立具体对象类继承新抽象类，调用桥接接口里的方法来实现功能。

# UML
<img src="../docs/uml/bridge-pattern.png">