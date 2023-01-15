package src

import "fmt"

// 代理类也实现了基础接口
type ProxyImage struct {
  fileName string
  // 直接聚合真实类
  // realImage RealImage
  // 聚合接口
  realImage Image
}

// 设置文件名称
func (p *ProxyImage) SetFileName(fileName string) {
  p.fileName = fileName
}

func (p *ProxyImage) Display() {
  fmt.Println("ProxyImage::Display() " + p.fileName)
  if p.realImage == nil {
    p.realImage = &RealImage{}
    p.realImage.Init(p.fileName)
  }
  // 代理类调用真实类的方法
  p.realImage.Display()
}
