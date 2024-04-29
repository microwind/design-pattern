## 代码结构
```shell
- src
  - Shape.ts # 原型基础抽象类，负责克隆方法
  - Circle.ts # 具体原型类，克隆方法会创建一个新对象并将其传递给构造函数
  - Rectangle.ts # 具体原型类，克隆方法会创建一个新对象并将其传递给构造函数
  - Square.ts # 具体原型类，克隆方法会创建一个新对象并将其传递给构造函数
  - Application.ts # 客户端调用组合[可选]
```

## 测试验证

```shell
$ cd ./prototype-pattern/ts
$ tsc
$ node test/test.js
```
