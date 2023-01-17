package src

// 定义抽象主题类或者接口，供具体主题类继承
type Subject interface {
  Init(name string)
  GetName() string
  SetName(string)
  Register(observer ObserverAPI)
  Remove(observer ObserverAPI)
  GetObservers() map[string]ObserverAPI
  Notify(content string)
}
