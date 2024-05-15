package main

import "fmt"

// Person 类表示人物
type Person struct {
  name string
  age  int
}

// GetName 返回人物名称
func (p *Person) GetName() string {
  return p.name
}

// GetAge 返回人物年龄
func (p *Person) GetAge() int {
  return p.age
}

// Employee 雇员抽象类
type Employee struct {
  id     int
  title  string
  person *Person
}

// Work 模拟雇员工作
func (e *Employee) Work() bool {
  return true
}

// Engineer 工程师类继承自雇员类
type Engineer struct {
  *Employee
}

// NewEngineer 创建一个新的工程师实例
func NewEngineer(id int, title string, person *Person) *Engineer {
  return &Engineer{
    Employee: &Employee{
      id:     id,
      title:  title,
      person: person,
    },
  }
}

// Work 实现工程师的工作方法
func (e *Engineer) Work() bool {
  fmt.Printf("Engineer is working. id = %d, title = %s, name = %s, age = %d\n", e.id, e.title, e.person.GetName(), e.person.GetAge())
  return true
}

// Manager 管理者类继承自雇员类
type Manager struct {
  *Employee
}

// NewManager 创建一个新的管理者实例
func NewManager(id int, title string, person *Person) *Manager {
  return &Manager{
    Employee: &Employee{
      id:     id,
      title:  title,
      person: person,
    },
  }
}

// Work 实现管理者的工作方法
func (m *Manager) Work() bool {
  fmt.Printf("Manager is working. id = %d, title = %s, name = %s, age = %d\n", m.id, m.title, m.person.GetName(), m.person.GetAge())
  return true
}

// 测试验证
func main() {
  person := &Person{name: "Tom", age: 25}
  engineer := NewEngineer(1001, "senior engineer", person)
  engineer.Work()

  manager := NewManager(2002, "advanced director", &Person{name: "Jerry", age: 45})
  manager.Work()
}
