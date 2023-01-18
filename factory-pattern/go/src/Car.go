package src

import "fmt"

type Car struct {
}

func (c *Car) Run() {
	fmt.Println("Car::Run().")
}
