package src

// 定义状态接口和状态方法，当前context只有一种状态
type State interface {
  GetName() string
  On(context *Context)
  Off(context *Context)
}
