package src

import "fmt"

type Motorcycle struct {
}

func (m *Motorcycle) Run() {
  fmt.Println("Motorcycle::Run().")
}
