## 代码结构
```shell
- src
  - func.h # 头文件，定义接口与数据
  - image.c # 基础接口，供代理类和真实类实现，定义在head
  - proxy_image.c # 代理类也实现了基础接口，代理调用真实类
  - real_image.c # 真实类也实现基础接口或继承自抽象
```

## 测试验证

```shell
$ cd ./proxy-pattern/c
$ gcc test/test.c ./src/*.c
$ ./a.out
```
