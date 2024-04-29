## 代码结构
```shell
- src
  - func.h # 头文件，定义接口与数据
  - vehicle_factory.c # 具体工厂类，根据类型创建具体产品
  - vehicle.c # 具体产品的抽象类或接口，定义在头文件
  - bus.c # 具体产品之一，实现或继承抽象
  - car.c # 具体产品之一，实现或继承抽象
  - motorcycle.c # 具体产品之一，实现或继承抽象
  - van.c # 具体产品之一，实现或继承抽象
```

## 测试验证

```shell
$ cd ./factory-pattern/c
$ gcc test/*.c src/*.c
$ ./a.out
```
