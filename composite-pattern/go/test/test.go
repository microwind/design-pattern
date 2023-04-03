package main

import (
  "fmt"

  "microwind/src"
)

// main包下的main入口方法
func main() {
  fmt.Println("test start:")
  /**
   * 组合模式依据树形结构来组合对象，用不同组件来构建整体对象。
   * 不同组件之间有相同的接口约束，有不同的具体实现。
   * 先定义顶级节点，然后陆续加入枝叶节点和叶子节点，这样不断添加，将零散的个体组成一个整体。ss
   */

  // 通过组合模型组合了一个部件，分支和节点可以随意增删
  var com = &src.CompanyComposite{Name: "西天旅游有限公司"}
  var com1 = &src.DepartmentComposite{Name: "总裁办"}
  var com2 = &src.DepartmentComposite{Name: "行动队"}
  var com3 = &src.DepartmentComposite{Name: "后勤组"}
  var leaf1 = &src.EmployeeLeaf{Name: "唐三藏"}
  var leaf2 = &src.EmployeeLeaf{Name: "孙悟空"}
  var leaf3 = &src.EmployeeLeaf{Name: "猪悟能"}
  var leaf4 = &src.EmployeeLeaf{Name: "沙悟净"}

  com.Add(com1)
  com.Add(com2)
  com.Add(com3)

  // leaf1属于com1
  com1.Add(leaf1)
  // leaf2, leaf3属于com2
  com2.Add(leaf2)
  com2.Add(leaf3)

  // 添加再删除
  var dept1 = &src.DepartmentComposite{Name: "小分队"}
  com2.Add(dept1)
  var tmp1 = &src.EmployeeLeaf{Name: "临时工"}
  dept1.Add(tmp1)
  dept1.Remove(tmp1)

  // leaf4属于com3
  com3.Add(leaf4)

  // 执行全部节点动作
  com.Operation()

  // 获取某个节点
  var employee = com.GetChild(1).GetChild(0)
  fmt.Println(employee.GetName())
}

/**
jarry@jarrys-MacBook-Pro go % go build src/*.go
jarry@jarrys-MacBook-Pro go % go run test/test.go
test start:
CompanyComposite::Operation() 西天旅游有限公司
DepartmentComposite::Operation() 总裁办
EmployeeLeaf::Operation() 唐三藏
DepartmentComposite::Operation() 行动队
EmployeeLeaf::Operation() 孙悟空
EmployeeLeaf::Operation() 猪悟能
DepartmentComposite::Operation() 小分队
DepartmentComposite::Operation() 后勤组
EmployeeLeaf::Operation() 沙悟净
孙悟空
*/
