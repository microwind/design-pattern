package shop

import (
  "fmt"
)

type SupermarketShop struct {
  Name string
}

func (s *SupermarketShop) GetName() string {
  return s.Name
}

func (s *SupermarketShop) Greetings() {
  fmt.Println("SupermarketShop::Greetings [Name=" + s.GetName() + "]")
}
