/*
聚合是一个对象（整体）包含或引用其他对象（部分），但这些部分对象在逻辑上可以独立于整体对象。
本示例：
- 聚合关系：Department类聚合了Employee。Department类包含一个Employee列表，但这些员工的生命周期不依赖于部门。如果部门被销毁，员工对象仍然可以继续存在。这种关系是典型的聚合关系。
- 松散耦合：聚合允许整体和部分对象之间具有较低的耦合度，这使得系统更易于维护和扩展。部分对象可以独立存在，整体对象只是引用它们。
- 部分-整体关系：部门包含员工，但员工可以属于多个部门，也可以独立存在。这种关系使得代码更加灵活，并允许部分对象在整体对象之外被重用。
*/

package main

import "fmt"

// 定义一个员工结构体
type Employee struct {
  name string
}

// 创建员工对象的函数
func NewEmployee(name string) *Employee {
  return &Employee{name}
}

// 获取员工名字的方法
func (e *Employee) GetName() string {
  return e.name
}

// 定义一个部门结构体
type Department struct {
  departmentName string      // 部门名称
  employees      []*Employee // 部门包含的员工列表
}

// 创建部门对象的函数
func NewDepartment(departmentName string) *Department {
  return &Department{departmentName, make([]*Employee, 0)}
}

// 添加员工到部门的方法
func (d *Department) AddEmployee(employee *Employee) {
  d.employees = append(d.employees, employee)
}

// 获取部门的所有员工名字的方法
func (d *Department) ListEmployees() {
  fmt.Println("Employees in", d.departmentName+":")
  for _, employee := range d.employees {
    fmt.Println(employee.GetName()) // 输出员工名字
  }
}

// 测试验证
func main() {
  // 创建几个员工对象
  tom := NewEmployee("Tom")
  jerry := NewEmployee("Jerry")

  // 创建一个部门，并将员工添加到部门
  itDepartment := NewDepartment("IT Resources")
  itDepartment.AddEmployee(tom)
  itDepartment.AddEmployee(jerry)

  // 列出部门中的员工
  itDepartment.ListEmployees() // 输出：Employees in IT Resources: Tom, Jerry

  // 即使部门被销毁，员工对象仍然可以继续存在
  itDepartment = nil // 删除部门对象

  fmt.Println("Employee Tom still exists:", tom.GetName()) // 输出：Tom
}
