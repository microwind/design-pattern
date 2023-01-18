package src

import "fmt"

// 实现部件的叶子节点，叶子节点不能再含有子节点
type EmployeeLeaf struct {
  Name string
}

// 叶子节点不能再增加内容
func (e *EmployeeLeaf) Add(component OrganizationComponent) {
  fmt.Println("Leaf can't Add.")
}

// 叶子节点没有移除内容
func (e *EmployeeLeaf) Remove(component OrganizationComponent) {
  fmt.Println("Leaf can't Remove.")
}

// 叶子节点无获取子节点
func (e *EmployeeLeaf) GetChild(index int) OrganizationComponent {
  fmt.Println("Leaf can't GetChild.")
  return nil
}

func (e *EmployeeLeaf) SetName(name string) {
  e.Name = name
}

func (e *EmployeeLeaf) GetName() string {
  return e.Name
}

func (e *EmployeeLeaf) Operation() {
  fmt.Println("EmployeeLeaf::Operation() " + e.Name)
}
