## 代码结构
```shell
- src
  - Employee.java # 雇员抽象类，供其他角色继承，并聚合关联类
  - Engineer.java # 工程师类继承雇员类
  - Manager.java # 管理者类继承雇员类
  - Person.java # 独立人员类，被雇员类聚合

  - CompositeReuse_counter.java # 反例，违反了组合复用原则。为了演示方便把其他类作为子类放在一起
```

## 测试验证

```shell
$ cd ./composite-reuse/java
$ javac test/Test.java
$ java test/Test
```
