package vehicle

import (
	"fmt"
)

// 具体产品实现类
type Car struct {
	Name string
}

func (c Car) GetName() string {
	return c.Name
}

func (c *Car) Run() {
	fmt.Println("Car::Run() [Name=" + c.Name + "]")
}
