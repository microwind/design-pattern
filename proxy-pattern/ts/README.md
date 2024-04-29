## 代码结构
```shell
- src
  - Image.ts # 定义一个接口或抽象类，供代理和实际调用来使用
  - ProxyImage.ts # 代理类也实现了基础接口，代理调用真实类
  - RealImage.ts # 真实类也实现基础接口或继承自抽象
```

## 测试验证

```shell
$ cd ./proxy-pattern/ts
$ tsc
$ node test/test.js
```
