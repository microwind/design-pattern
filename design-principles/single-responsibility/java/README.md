## 代码结构
```shell
- src
  - OrderProcessor.java # 订单业务类，含有订单处理逻辑方法
  - OrderValidator.java # 订单校验类，校验订单的合法性和有效性等
  - OrderDao.java # Order数据库访问类，负责处理订单的CRUD操作

  - SingleResponsibility_counter.java # 反例，违反了单一职责原则。为了演示方便把其他类作为子类放在一起
```

## 测试验证

```shell
$ cd ./single-responsibility/java
$ javac test/Test.java
$ java test/Test
```
