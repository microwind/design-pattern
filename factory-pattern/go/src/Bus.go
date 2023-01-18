package src

import "fmt"

type Bus struct {
}

func (b *Bus) Run() {
  fmt.Println("Bus::Run().")
}
