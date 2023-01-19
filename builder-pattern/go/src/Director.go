package src

// 指挥调度类，负责利用建造者建造产品，隔离需求
type Director struct {
}

// 建造phone1
func (c *Director) BuildIPhone(builder Builder) {
  builder.Reset()
  var screen = []int{120, 500}
  builder.SetName("iPhone")
  builder.SetScreen(screen)
  builder.SetGPU(100)
}

// 建造phone2
func (c *Director) BuildHuaweiPhone(builder Builder) {
  builder.Reset()
  var screen = []int{140, 600}
  builder.SetName("HuaweiPhone")
  builder.SetScreen(screen)
  builder.SetGPU(102)
}

// 建造phone3
func (c *Director) BuildMiPhone(builder Builder) {
  builder.Reset()
  var screen = []int{130, 550}
  builder.SetName("MiPhone")
  builder.SetScreen(screen)
  builder.SetGPU(103)
}
