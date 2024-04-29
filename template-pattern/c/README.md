## 代码结构
```shell
- src
  - func.h # 头文件，定义接口与数据
  - game_template.c # 定义抽象模板类的公共部分，这里用struct替代
  - basketball.c # 具体的模板实现，覆盖父类
  - football.c # 具体的模板实现，覆盖父类
  - tennis.c # 具体的模板实现，覆盖父类
```

## 测试验证

```shell
$ cd ./template-pattern/c
$ gcc test/test.c ./src/*.c
$ ./a.out
```
