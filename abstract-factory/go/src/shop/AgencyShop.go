package shop

import (
  "fmt"
)

type AgencyShop struct {
  Name string
}

func (a *AgencyShop) GetName() string {
  return a.Name
}

func (a *AgencyShop) Greetings() {
  fmt.Println("AgencyShop::Greetings [Name=" + a.GetName() + "]")
}
