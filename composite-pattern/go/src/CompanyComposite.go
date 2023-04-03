package src

import "fmt"

// 实现部件的树枝构件1
type CompanyComposite struct {
  Name     string
  children []OrganizationComponent
}

func (c *CompanyComposite) Add(component OrganizationComponent) {
  c.children = append(c.children, component)
}

func (c *CompanyComposite) Remove(component OrganizationComponent) {
  // 删除成员
  for i := 0; i < len(c.children); i++ {
    com := c.children[i]
    if com == component {
      c.children = append(c.children[:i], c.children[i+1:]...)
      break
    }
  }
}

func (c *CompanyComposite) GetChild(index int) OrganizationComponent {
  return c.children[index]
}

func (c *CompanyComposite) SetName(name string) {
  c.Name = name
}

func (c *CompanyComposite) GetName() string {
  return c.Name
}

func (c *CompanyComposite) Operation() {
  fmt.Println("CompanyComposite::Operation() " + c.Name)
  for _, component := range c.children {
    component.Operation()
  }
}
