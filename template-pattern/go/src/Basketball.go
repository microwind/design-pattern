package src

import "fmt"

// 定义子类覆写父类抽象方法
type Basketball struct {
  // 继承父模板的公共方法
  GameTemplate
}

func (b *Basketball) GetName() string {
  return "Basketball"
}

func (b *Basketball) Init() {
  fmt.Println("Basketball::Init() [Basketball Game Initialized! Start playing.]")
}

func (b *Basketball) Start() {
  fmt.Println("Basketball::Start() [Basketball Game Started. Enjoy the game!]")
}

func (b *Basketball) End() {
  fmt.Println("Basketball::End() [Basketball Game Finished!]")
}
