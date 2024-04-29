## 代码结构
```shell
- src
  - func.h # 头文件，定义接口与数据
  - shape.c # 基础抽象接口，定义在head
  - square.c # 具体实现一，方形
  - circle.c # 具体实现之一，圆形
  - shape_decorator.c # 抽象装饰类，定义在head
  - red_shape_decorator.c # 具体装饰器之一，设置Shape红色
  - shadow_shape_decorator.c # 具体装饰器之一，设置Shape阴影
```

## 测试验证

```shell
$ cd ./decorator-pattern/c
$ gcc test/test.c src/*.c
$ ./a.out
```
