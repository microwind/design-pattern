package src

type ManualBuilder struct {
  manual *Manual
}

func (m *ManualBuilder) Reset() {
  m.manual = new(Manual)
}

func (m *ManualBuilder) SetName(name string) {
  m.manual.SetName(name)
}

func (m *ManualBuilder) SetScreen(screen []int) {
  m.manual.SetScreen(screen)
}

func (m *ManualBuilder) SetGPU(no int) {
  m.manual.SetGpuType(no)
}

func (m *ManualBuilder) GetProduct() *Manual {
  return m.manual
}
