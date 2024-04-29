## 代码结构
```shell
- src
  - Shape.java # 原型基础抽象类，负责克隆方法
  - Circle.java # 具体原型类，克隆方法会创建一个新对象并将其传递给构造函数
  - Rectangle.java # 具体原型类，克隆方法会创建一个新对象并将其传递给构造函数
  - Square.java # 具体原型类，克隆方法会创建一个新对象并将其传递给构造函数
  - Application.java # 客户端调用组合[可选]
```

## 测试验证

```shell
$ cd ./prototype-pattern/java
$ javac test/Test.java
$ java test/Test
```
