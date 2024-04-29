## 代码结构
```shell
- src
  - Visitor.py # 访问者Visitor抽象接口，定义不同的visit方法
  - ObjectStructure.py # 结构对象(ObjectStructure)聚合了其他元素，传入访问者分发给其他元素
  - Element.py # 抽象元素(Element)，定义accept方法，传入抽象访问者
  - ConcreteElementA.py # 具体的元素实现者，继承抽象元素
  - ConcreteElementB.py # 具体的元素实现者，继承抽象元素
  - ConcreteVisitorA.py # 具体访问者，实现或继承抽象接口/基类
  - ConcreteVisitorB.py # 具体访问者，实现或继承抽象接口/基类
```

## 测试验证

```shell
$ cd ./visitor-pattern/python
$ python test/test.py
```
