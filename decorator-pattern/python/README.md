## 代码结构
```shell
- src
  - Shape.py # 基础抽象接口，形状
  - Square.py # 具体实现一，方形
  - Circle.py # 具体实现之一，圆形
  - ShapeDecorator.py # 抽象装饰类，是否实现基础Shape可选
  - RedShapeDecorator.py # 具体装饰器之一，设置Shape红色
  - ShadowShapeDecorator.py # 具体装饰器之一，设置Shape阴影
```

## 测试验证

```shell
$ cd ./decorator-pattern/python
$ python test/test.py
```
