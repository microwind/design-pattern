## 代码结构
```shell
- src
  - func.h # 头文件，定义接口与数据
  - abstract_shape.c # 桥接抽象类，关联具体的操作接口，供具体类实现
  - refined_shape.c # 具体桥接类，继承抽象桥接类，扩充了自己的方法
  - draw_tool.c # 工具基础接口，供具体工具类实现
  - draw_styeA.c # 具体工具类一，负责某类专门处理
  - draw_styleB.c # 具体工具类二，负责某类专门处理

```

## 测试验证

```shell
$ cd ./bridge-pattern/c
$ gcc test/test.c src/*.c
$ ./a.out
```
