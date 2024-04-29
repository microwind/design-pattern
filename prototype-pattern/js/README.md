## 代码结构
```shell
- src
  - Shape.js # 原型基础抽象类，负责克隆方法
  - Circle.js # 具体原型类，克隆方法会创建一个新对象并将其传递给构造函数
  - Rectangle.js # 具体原型类，克隆方法会创建一个新对象并将其传递给构造函数
  - Square.js # 具体原型类，克隆方法会创建一个新对象并将其传递给构造函数
  - Application.js # 客户端调用组合[可选]
```

## 测试验证

```shell
$ cd ./prototype-pattern/js
$ node test/test.js
```
