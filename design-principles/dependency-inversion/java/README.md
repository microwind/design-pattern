## 代码结构
```shell
- src
  - Sender.java # 发送者的接口或抽象类，供实际发送者对象实现
  - MailSender.java # MailSender实现了Sender接口
  - MessageSender.java # MessageSender实现了Sender接口
  - PushSender.java # PushSender实现了Sender接口
  - Notification.java # 消息通知业务应用类，依赖低层模块的接口，而不是实现

  - DependencyInversion_counter.java # 反例，违反了依赖反转原则。为了演示方便把其他类作为子类放在一起
```

## 测试验证

```shell
$ cd ./dependency-inversion/java
$ javac test/Test.java
$ java test/Test
```
