## 代码结构
```shell
- src
  - Shape.js # 基础抽象接口，形状
  - Square.js # 具体实现一，方形
  - Circle.js # 具体实现之一，圆形
  - ShapeDecorator.js # 抽象装饰类，是否实现基础Shape可选
  - RedShapeDecorator.js # 具体装饰器之一，设置Shape红色
  - ShadowShapeDecorator.js # 具体装饰器之一，设置Shape阴影
```

## 测试验证

```shell
$ cd ./decorator-pattern/js
$ node test/test.js
```
