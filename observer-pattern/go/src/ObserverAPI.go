package src

// 观察者抽象父类，定义一些公共方法
type ObserverAPI interface {
  SetSubject(subject Subject)
  GetName() string
  SetName(name string)
  Update(content string)
}