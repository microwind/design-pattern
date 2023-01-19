package src

type Manual struct {
  name    string
  screen  []int
  gpuType int
}

func (m *Manual) SetName(name string) {
  m.name = name
}

func (m *Manual) GetName() string {
  return m.name
}

func (m *Manual) SetScreen(screen []int) {
  m.screen = screen
}

func (m *Manual) GetScreen() []int {
  return m.screen
}

func (m *Manual) SetGpuType(gpuType int) {
  m.gpuType = gpuType
}

func (m *Manual) GetGpuType() int {
  return m.gpuType
}
