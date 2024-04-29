## 代码结构
```shell
- src
  - func.h # 头文件，定义接口与数据
  - handler.c # 责任链抽象类或接口，定义调用链，供具体类继承和实现
  - auth_handler.c # 具体事件处理类之一，继承抽象类
  - request_handler.c # 具体事件处理类之一，继承抽象类
  - user_handler.c # 具体事件处理类之一，继承抽象类
```

## 测试验证

```shell
$ cd ./chain-responsibility/c
$ gcc test/*.c src/*.c
$ ./a.out
```
