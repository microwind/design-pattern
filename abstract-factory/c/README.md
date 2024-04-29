## 代码结构
```shell
- src
  - func.h # 头文件，定义接口和数据类型
  - abstract_factory.c # 抽象工厂接口，定义在header
  - shop_factory.c # 具体工厂类之一，负责Shop生产，继承抽象工厂
  - vehicle_factory.c # 具体工厂类之一，负责Vehichle生产，继承抽象工厂
  - factory_creator.c # 工厂创建类，根据产品类别创建不同的工厂
  + shop # Shop类产品文件夹
    - shop.c # Shop接口，定义在header
    - sgency_shop.ajva # Shop具体实现之一
    - direct_sale.c # Shop具体实现之一
    - supermarket_shop.c # Shop具体实现之一
  + vehicle # Vehicle类产品文件夹
    - vehicle.c # Vehicle接口，定义在header
    - bus.c # Vehicle具体实现之一
    - car.c # Vehicle具体实现之一
    - motorcycle.c # Vehicle具体实现之一
    - van # Vehicle具体实现之一
```

## 测试验证

```shell
$ cd ./abstract-factory/c
$ gcc src/**/*.c test/*.c
$ ./a.out
```
