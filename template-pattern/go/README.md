## 代码结构
```shell
- src
  - GameTemplate.go # 定义抽象模板类的公共部分，这里用struct替代
  - TemplateInterface.go # 定义抽象模板接口，包括各种动作，供子类去实现
  - Basketball.go # 具体的模板实现，覆盖父类
  - Football.go # 具体的模板实现，覆盖父类
  - Tennis.go # 具体的模板实现，覆盖父类
```

## 测试验证

```shell
$ cd ./template-pattern/go
$ go run test/test.go
```
