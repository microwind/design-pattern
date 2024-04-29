## 代码结构
```shell
- src
  - Shape.ts # 基础抽象接口，形状
  - Square.ts # 具体实现一，方形
  - Circle.ts # 具体实现之一，圆形
  - ShapeDecorator.ts # 抽象装饰类，是否实现基础Shape可选
  - RedShapeDecorator.ts # 具体装饰器之一，设置Shape红色
  - ShadowShapeDecorator.ts # 具体装饰器之一，设置Shape阴影
```

## 测试验证

```shell
$ cd ./decorator-pattern/ts
$ tsc
$ node test/test.js
```
