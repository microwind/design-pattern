package src

import "fmt"

type Van struct {
}

func (v *Van) Run() {
  fmt.Println("Van::Run().")
}
