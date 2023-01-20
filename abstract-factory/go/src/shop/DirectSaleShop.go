package shop

import (
  "fmt"
)

type DirectSaleShop struct {
  Name string
}

func (d *DirectSaleShop) GetName() string {
  return d.Name
}

func (d *DirectSaleShop) Greetings() {
  fmt.Println("DirectSaleShop::Greetings [Name=" + d.GetName() + "]")
}

func (d *DirectSaleShop) Welcome() {
  fmt.Println("DirectSaleShop::Welcome [Name=" + d.GetName() + "]")
}
