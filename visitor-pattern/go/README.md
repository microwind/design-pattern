## 代码结构
```shell
- src
  - Visitor.go # 访问者Visitor抽象接口，定义不同的visit方法
  - ObjectStructure.go # 结构对象(ObjectStructure)聚合了其他元素，传入访问者分发给其他元素
  - Element.go # 抽象元素(Element)，定义accept方法，传入抽象访问者
  - ConcreteElementA.go # 具体的元素实现者，继承抽象元素
  - ConcreteElementB.go # 具体的元素实现者，继承抽象元素
  - ConcreteVisitorA.go # 具体访问者，实现或继承抽象接口/基类
  - ConcreteVisitorB.go # 具体访问者，实现或继承抽象接口/基类
```

## 测试验证

```shell
$ cd ./visitor-pattern/go
$ go run test/test.go
```
