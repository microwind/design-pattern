# 简介
过滤器模式（Filter Pattern）或标准模式（Criteria Pattern），是一种结构型模式。这种模式允许使用不同的标准条件来过滤一组对象，并通过逻辑运算的方式把各条件连接起来，它结合多个标准来获得单一标准。

例子将创建一个 Person 对象、Criteria 接口和实现了该接口的实体类，来过滤 Person 对象的列表。Test 类使用 Criteria 对象，基于各种标准和它们的结合来过滤 Person 对象的列表。

# 作用
1. 可以通过层层筛选，过滤出自己想要的结果。
2. 面向接口编程，将对象过滤，接口不依赖对象；对象无入侵，每次只需要增加规则就行了，不用修改过滤对象类。

# 实现步骤
1. 创建Criteria基础接口，定义过滤方法。
2. 创建多个条件类，实现过滤逻辑。
3. 客户端调用时，通条件类过滤数据。

# UML
<img src="../docs/uml/filter-pattern.png">