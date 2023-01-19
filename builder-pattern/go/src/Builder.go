package src

// 建造者的基础接口
type Builder interface {
  Reset()
  SetName(name string)
  SetScreen(size []int)
  SetGPU(no int)
}
