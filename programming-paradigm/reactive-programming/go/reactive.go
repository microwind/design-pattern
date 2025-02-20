package main

import "fmt"

type Observer interface {
  Update(string)
}

type MyObserver struct {
  name string
}

func (o *MyObserver) Update(message string) {
  fmt.Printf("%s 接到新消息: %s\n", o.name, message)
}

type Subject struct {
  name      string
  observers []Observer
}

func (s *Subject) AddObserver(observer Observer) {
  s.observers = append(s.observers, observer)
}

func (s *Subject) RemoveObserver(observer Observer) {
  for i, obs := range s.observers {
    if obs == observer {
      s.observers = append(s.observers[:i], s.observers[i+1:]...)
      break
    }
  }
}

func (s *Subject) Notify(message string) {
  for _, observer := range s.observers {
    observer.Update(message)
  }
}

func main() {
  subject1 := &Subject{name: "Subject1"}
  observer1 := &MyObserver{name: "Observer1"}
  observer2 := &MyObserver{name: "Observer2"}

  subject1.AddObserver(observer1)
  subject1.AddObserver(observer2)

  subject1.Notify("发布消息")

  subject1.RemoveObserver(observer1)
  subject1.Notify("再次发布消息")
}

/*
jarry@Mac go % go run reactive.go
Observer1 接到新消息: 发布消息
Observer2 接到新消息: 发布消息
Observer2 接到新消息: 再次发布消息
*/
