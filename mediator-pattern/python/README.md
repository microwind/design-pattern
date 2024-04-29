## 代码结构
```shell
- src
  - AbstractUser.py # 定义抽象用户类，聚合中介者
  - CommonUser.py # 普通用户继承了抽象用户，实现了具体功能
  - MemberUser.py # 会员用户继承了抽象用户，实现了具体功能
  - RoomMediator.py # 定义中介者接口或抽象类
  - GeneralRoom.py # 中介者的具体实现类，作为中介者负责传递信息
```

## 测试验证

```shell
$ cd ./mediator-pattern/python
$ python test/test.py
```
