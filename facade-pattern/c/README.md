## 代码结构
```shell
- src
  - func.h # 头文件，定义接口与数据
  - abstract_facade.c # 外观模式的接口或抽象类，可选
  - facade.c # 外观模式实现类，继承基础抽象，是外部调用与内部子系统的衔接层
  - encode_module.c # 内部模块类之一
  - file_module.c # 内部模块类之一
  - network_module.c # 内部模块类之一
```

## 测试验证

```shell
$ cd ./facade-pattern/c
$ gcc test/test.c src/*.c
$ ./a.out
```
