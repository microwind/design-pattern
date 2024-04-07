package src

import "fmt"

// 具体的观察者实现类，也可以看成订阅者，关联对应的主题类。
type ConcreteObserver struct {
  name    string
  subject Subject
}

// 给观察者绑定主题，同时把观察者添加到主题列表
func (c *ConcreteObserver) Init(subject Subject, name string) {
  c.name = name
  c.SetSubject(subject)
  c.subject.Register(c)
}

func (c *ConcreteObserver) SetName(name string) {
  c.name = name
}

func (c *ConcreteObserver) SetSubject(subject Subject) {
  c.subject = subject
}

func (c *ConcreteObserver) GetName() string {
  return c.name
}

// 发布者(主题)发出更新通知后，观察者(订阅者)自行监听和实现动作
func (c *ConcreteObserver) Update(content string) {
  fmt.Println("ConcreteObserver::Update() [subject.name = " + c.subject.GetName() + " content = " + content + "]")
}
