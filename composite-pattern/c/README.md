## 代码结构
```shell
- src
  - func.h # 头文件，定义接口与数据
  - organization_component.c # 组合部件抽象类或接口
  - company_composite.c # 具体部件实现之一，树枝构件
  - department_composite.c # 具体部件实现之一，树枝构件
  - employee_leaf.c # 具体部件的叶子节点，叶子节点不能再含有子节点
```

## 测试验证

```shell
$ cd ./composite-pattern/c
$ gcc test/test.c src/*.c
$ ./a.out
```
