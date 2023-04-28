package src

type ManualBuilder struct {
  manual *Manual
}

func (m *ManualBuilder) Reset() {
  m.manual = new(Manual)
}

func (m *ManualBuilder) SetName(name string) Builder {
  m.manual.SetName(name)
  return (Builder)(m)
}

func (m *ManualBuilder) SetScreen(screen []int) Builder {
  m.manual.SetScreen(screen)
  return (Builder)(m)
}

func (m *ManualBuilder) SetGPU(no int) Builder {
  m.manual.SetGpuType(no)
  return (Builder)(m)
}

func (m *ManualBuilder) GetProduct() *Manual {
  return m.manual
}
