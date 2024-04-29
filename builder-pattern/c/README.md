## 代码结构
```shell
- src
  - func.h # 头文件，定义接口与数据
  - builder.c # 建造者抽象类或接口，供具体建造者继承和实现
  - manual_builder.c # 具体建造之一，建造某个具体产品
  - mhone_builder.c # 具体建造之一，建造某个具体产品
  - director.c # 指挥调度类，负责利用建造者建造产品，隔离需求
  - manual.c # 具体产品类，由对应早建造者生产
  - phone.c # 具体产品类，由对应早建造者生产
  - application.c # 客户调用类，将建造过程再封装【可选】
```

## 测试验证

```shell
$ cd ./builder-pattern/c
$ gcc src/*.c test/test.c
$ ./a.out
```
