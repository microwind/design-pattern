## 代码结构
```shell
- src
  - func.h # 头文件，定义接口与数据
  - visitor.c # 访问者Visitor抽象接口，定义visit方法，传递具体元素对象。定义在head
  - object_structure.c # 结构对象(ObjectStructure)聚合了其他元素，传入访问者分发给其他元素
  - element.c # 抽象元素(Element)，定义accept方法。定义在head
  - concrete_element_a.c # 具体的元素实现者，继承抽象元素
  - concrete_element_b.c # 具体的元素实现者，继承抽象元素
  - concrete_visitor_a.c # 具体访问者，实现或继承抽象接口/基类
  - concrete_visitor_b.c # 具体访问者，实现或继承抽象接口/基类
```

## 测试验证

```shell
$ cd ./visitor-pattern/c
$ gcc test/test.c ./src/*.c
$ ./a.out
```
