package src

// 建造者的基础接口
type Builder interface {
  Reset()
  SetName(name string) Builder
  SetScreen(size []int) Builder
  SetGPU(no int) Builder
}
