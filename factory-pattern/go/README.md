## 代码结构
```shell
- src
  - VehicleFactory.go # 具体工厂类，根据类型创建具体产品
  - Vehicle.go # 具体产品的抽象类或接口
  - Bus.go # 具体产品之一，实现或继承抽象
  - Car.go # 具体产品之一，实现或继承抽象
  - Motorcycle.go # 具体产品之一，实现或继承抽象
  - Van.go # 具体产品之一，实现或继承抽象
```

## 测试验证

```shell
$ cd ./factory-pattern/go
$ go run test/test.go
```
