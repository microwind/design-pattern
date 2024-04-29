## 代码结构
```shell
- src
  - VehicleFactory.ts # 具体工厂类，根据类型创建具体产品
  - Vehicle.ts # 具体产品的抽象类或接口
  - Bus.ts # 具体产品之一，实现或继承抽象
  - Car.ts # 具体产品之一，实现或继承抽象
  - Motorcycle.ts # 具体产品之一，实现或继承抽象
  - Van.ts # 具体产品之一，实现或继承抽象
```

## 测试验证

```shell
$ cd ./factory-pattern/ts
$ tsc
$ node test/test.js
```
