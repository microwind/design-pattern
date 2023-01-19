package src

type PhoneBuilder struct {
  phone *Phone
}

func (p *PhoneBuilder) Reset() {
  p.phone = new(Phone)
}

func (p *PhoneBuilder) SetName(name string) {
  p.phone.SetName(name)
}

func (p *PhoneBuilder) SetScreen(screen []int) {
  p.phone.SetScreen(screen)
}

func (p *PhoneBuilder) SetGPU(no int) {
  p.phone.SetGpuType(no)
}

func (p *PhoneBuilder) GetProduct() *Phone {
  return p.phone
}
