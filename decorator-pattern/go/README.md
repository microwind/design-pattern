## 代码结构
```shell
- src
  - Shape.go # 基础抽象接口，形状
  - Square.go # 具体实现一，方形
  - Circle.go # 具体实现之一，圆形
  - ShapeDecorator.go # 抽象装饰类，是否实现基础Shape可选
  - RedShapeDecorator.go # 具体装饰器之一，设置Shape红色
  - ShadowShapeDecorator.go # 具体装饰器之一，设置Shape阴影
```

## 测试验证

```shell
$ cd ./decorator-pattern/go
$ go run test/test.go
```
