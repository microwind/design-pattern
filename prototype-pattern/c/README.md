## 代码结构
```shell
- src
  - func.h # 头文件，定义接口与数据
  - shape.c # 原型基础抽象类，负责克隆方法
  - circle.c # 具体原型类，克隆方法会创建一个新对象并将其传递给构造函数
  - rectangle.c # 具体原型类，克隆方法会创建一个新对象并将其传递给构造函数
  - square.c # 具体原型类，克隆方法会创建一个新对象并将其传递给构造函数
  - application.c # 客户端调用组合[可选]
```

## 测试验证

```shell
$ cd ./prototype-pattern/c
$ gcc test/test.c ./src/*.c
$ ./a.out
```
