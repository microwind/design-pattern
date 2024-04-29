## 代码结构
```shell
- src
  - VehicleFactory.js # 具体工厂类，根据类型创建具体产品
  - Vehicle.js # 具体产品的抽象类或接口
  - Bus.js # 具体产品之一，实现或继承抽象
  - Car.js # 具体产品之一，实现或继承抽象
  - Motorcycle.js # 具体产品之一，实现或继承抽象
  - Van.js # 具体产品之一，实现或继承抽象
```

## 测试验证

```shell
$ cd ./factory-pattern/js
$ node test/test.js
```
