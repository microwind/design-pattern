package src

import "fmt"

// 观察者主题类，也是发布者，重写具体的通知方法。不同主题可以关联不同的观察者。
type ConcreteSubject struct {
  name      string
  observers map[string]ObserverAPI
}

func (s *ConcreteSubject) Init(name string) {
  s.SetName(name)
  s.observers = make(map[string]ObserverAPI)
}

func (s *ConcreteSubject) GetObservers() map[string]ObserverAPI {
  return s.observers
}

func (s *ConcreteSubject) GetName() string {
  return s.name
}

func (s *ConcreteSubject) SetName(name string) {
  s.name = name
}

func (s *ConcreteSubject) Register(observer ObserverAPI) {
  fmt.Println(s.name + "::Register() [observer.name = " + observer.GetName() + "]")
  s.observers[observer.GetName()] = observer
}

func (s *ConcreteSubject) Remove(observer ObserverAPI) {
  delete(s.observers, observer.GetName())
}

// 通知批量各个观察者
func (s *ConcreteSubject) Notify(content string) {
  fmt.Println(s.name + "::Notify() [content = " + content + "]")
  for _, o := range s.observers {
    o.Update(content)
  }
}
