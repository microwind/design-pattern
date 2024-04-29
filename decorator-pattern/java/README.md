## 代码结构
```shell
- src
  - Shape.java # 基础抽象接口，形状
  - Square.java # 具体实现一，方形
  - Circle.java # 具体实现之一，圆形
  - ShapeDecorator.java # 抽象装饰类，是否实现基础Shape可选
  - RedShapeDecorator.java # 具体装饰器之一，设置Shape红色
  - ShadowShapeDecorator.java # 具体装饰器之一，设置Shape阴影
```

## 测试验证

```shell
$ cd ./decorator-pattern/java
$ javac test/Test.java
$ java test/Test
```
