## 代码结构
```shell
- src
  - func.h # 头文件，定义接口与数据
  - abstract_user.c # 抽象用户类，定义在head，可选
  - common_user.c # 普通用户继承了抽象用户，实现了具体功能
  - member_user.c # 会员用户继承了抽象用户，实现了具体功能
  - room_mediator.c # 定义中介者接口或抽象类
  - general_room.c # 中介者的具体实现类，作为中介者负责传递信息
```

## 测试验证

```shell
$ cd ./mediator-pattern/c
$ gcc test/test.c ./src/*.c
$ ./a.out
```
