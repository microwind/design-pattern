package src

type PhoneBuilder struct {
  phone *Phone
}

func (p *PhoneBuilder) Reset() {
  p.phone = new(Phone)
}

func (p *PhoneBuilder) SetName(name string) Builder {
  p.phone.SetName(name)
  return (Builder)(p)
}

func (p *PhoneBuilder) SetScreen(screen []int) Builder {
  p.phone.SetScreen(screen)
  return (Builder)(p)
}

func (p *PhoneBuilder) SetGPU(no int) Builder {
  p.phone.SetGpuType(no)
  return (Builder)(p)
}

func (p *PhoneBuilder) GetProduct() *Phone {
  return p.phone
}
