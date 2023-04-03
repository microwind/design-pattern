package src

import "fmt"

// 实现部件的树枝构件2
type DepartmentComposite struct {
  Name     string
  children []OrganizationComponent
}

func (d *DepartmentComposite) Add(component OrganizationComponent) {
  d.children = append(d.children, component)
}

func (d *DepartmentComposite) Remove(component OrganizationComponent) {
  // 删除组件
  for i := 0; i < len(d.children); i++ {
    com := d.children[i]
    if com == component {
      d.children = append(d.children[:i], d.children[i+1:]...)
      break
    }
  }
}

func (d *DepartmentComposite) GetChild(index int) OrganizationComponent {
  return d.children[index]
}

func (d *DepartmentComposite) SetName(name string) {
  d.Name = name
}

func (d *DepartmentComposite) GetName() string {
  return d.Name
}

func (d *DepartmentComposite) Operation() {
  fmt.Println("DepartmentComposite::Operation() " + d.Name)
  for _, component := range d.children {
    component.Operation()
  }
}
