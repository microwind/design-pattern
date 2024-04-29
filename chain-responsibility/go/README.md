## 代码结构
```shell
- src
  - AbstractHandler.go # 责任链抽象类或接口，定义调用链，供具体类继承和实现
  - AuthHandler.go # 具体事件处理类之一，继承抽象类
  - RequestHandler.go # 具体事件处理类之一，继承抽象类
  - UserHandler.go # 具体事件处理类之一，继承抽象类
```

## 测试验证

```shell
$ cd ./chain-responsibility/go
$ go run test/test.go
```
