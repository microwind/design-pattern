package src

import "fmt"

// 定义子类覆写父类抽象方法
type Football struct {
  // 继承父模板的公共方法
  GameTemplate
}

func (b *Football) GetName() string {
  return "Football"
}

func (b *Football) Init() {
  fmt.Println("Football::Init() [Football Game Initialized! Start playing.]")
}

func (b *Football) Start() {
  fmt.Println("Football::Start() [Football Game Started. Enjoy the game!]")
}

func (b *Football) End() {
  fmt.Println("Football::End() [Football Game Finished!]")
}
