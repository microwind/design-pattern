## 代码结构
```shell
- src
  - Builder.go # 建造者抽象类或接口，供具体建造者继承和实现
  - ManualBuilder.go # 具体建造之一，建造某个具体产品
  - PhoneBuilder.go # 具体建造之一，建造某个具体产品
  - Director.go # 指挥调度类，负责利用建造者建造产品，隔离需求
  - Manual.go # 具体产品类，由对应早建造者生产
  - Phone.go # 具体产品类，由对应早建造者生产
  - Application.go # 客户调用类，将建造过程再封装【可选】
```

## 测试验证

```shell
$ cd ./builder-pattern/go
$ go run test/test.go
```
