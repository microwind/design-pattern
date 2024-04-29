## 代码结构
```shell
- src
  - Visitor.ts # 访问者Visitor抽象接口，定义不同的visit方法
  - ObjectStructure.ts # 结构对象(ObjectStructure)聚合了其他元素，传入访问者分发给其他元素
  - Element.ts # 抽象元素(Element)，定义accept方法，传入抽象访问者
  - ConcreteElementA.ts # 具体的元素实现者，继承抽象元素
  - ConcreteElementB.ts # 具体的元素实现者，继承抽象元素
  - ConcreteVisitorA.ts # 具体访问者，实现或继承抽象接口/基类
  - ConcreteVisitorB.ts # 具体访问者，实现或继承抽象接口/基类
```

## 测试验证

```shell
$ cd ./visitor-pattern/ts
$ tsc
$ node test/test.js
```
