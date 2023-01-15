package src

// 定义抽象模板接口，包括各种动作，供子类去实现
type TemplateInterface interface {
  GetName() string
  Init()
  Start()
  End()
}
