package src

import "fmt"

// 具体的观察者实现类2，也可以看成订阅者，关联对应的主题类。
type ConcreteObserver2 struct {
  name    string
  subject Subject
}

func (c *ConcreteObserver2) SetSubject(subject Subject) {
  c.subject = subject
}

func (c *ConcreteObserver2) SetName(name string) {
  c.name = name
}

func (c *ConcreteObserver2) GetName() string {
  return c.name
}

func (c *ConcreteObserver2) GetSubjectName() string {
  if c.subject != nil {
    return c.subject.GetName()
  }
  return "unknow"
}

// 观察者发出更新通知，观察者自行监听
func (c *ConcreteObserver2) Update(content string) {
  fmt.Println("ConcreteObserver2::Update() [subject.name = " + c.GetSubjectName() + " content = " + content + "]")
}
