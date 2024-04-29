## 代码结构
```shell
- src
  - Builder.ts # 建造者抽象类或接口，供具体建造者继承和实现
  - ManualBuilder.ts # 具体建造之一，建造某个具体产品
  - PhoneBuilder.ts # 具体建造之一，建造某个具体产品
  - Director.ts # 指挥调度类，负责利用建造者建造产品，隔离需求
  - Manual.ts # 具体产品类，由对应早建造者生产
  - Phone.ts # 具体产品类，由对应早建造者生产
  - Application.ts # 客户调用类，将建造过程再封装【可选】
```

## 测试验证

```shell
$ cd ./builder-pattern/ts
$ tsc
$ node test/test.js
```
