package src

type Phone struct {
  name    string
  screen  []int
  gpuType int
}

func (p *Phone) SetName(name string) {
  p.name = name
}

func (p *Phone) GetName() string {
  return p.name
}

func (p *Phone) SetScreen(screen []int) {
  p.screen = screen
}

func (p *Phone) GetScreen() []int {
  return p.screen
}

func (p *Phone) SetGpuType(gpuType int) {
  p.gpuType = gpuType
}

func (p *Phone) GetGpuType() int {
  return p.gpuType
}
