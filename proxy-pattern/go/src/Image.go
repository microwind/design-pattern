package src

// 定义一个接口供代理和实际调用来使用
type Image interface {
  Init(fileName string)
  Display()
}
