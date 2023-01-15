package src

import "fmt"

// 真实类实现基础接口
type RealImage struct {
  fileName string
}

// 在初始化时执行内部逻辑
func (r *RealImage) Init(fileName string) {
  r.fileName = fileName
  r.LoadFromDisk(fileName)
}

func (r *RealImage) Display() {
  fmt.Println("RealImage::Display() " + r.fileName)
}

// 这个方法只是内部使用
func (r *RealImage) LoadFromDisk(fileName string) {
  fmt.Println("RealImage::LoadFromDisk()  " + fileName)
}
