## 代码结构
```shell
- src
  - OrganizationComponent.go # 组合部件抽象类或接口
  - CompanyComposite.go # 具体部件实现之一，树枝构件
  - DepartmentComposite.go # 具体部件实现之一，树枝构件
  - EmployeeLeaf.go # 具体部件的叶子节点，叶子节点不能再含有子节点
```

## 测试验证

```shell
$ cd ./composite-pattern/go
$ go run test/test.go
```
