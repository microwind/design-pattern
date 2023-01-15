package src

import "fmt"

// 定义子类覆写父类抽象方法
type Tennis struct {
  // 继承父模板的公共方法
  gameTemplate GameTemplate
}

func (b *Tennis) GetName() string {
  return "Tennis"
}

func (b *Tennis) Init() {
  fmt.Println("Tennis::Init() [Tennis Game Initialized! Start playing.]")
}

func (b *Tennis) Start() {
  fmt.Println("Tennis::Start() [Tennis Game Started. Enjoy the game!]")
}

func (b *Tennis) End() {
  fmt.Println("Tennis::End() [Tennis Game Finished!]")
}

// 在调用父类play之前，如果要执行自己的行为，也可以覆盖父类方法
// 先执行自己的，再调用父类的方法
func (b *Tennis) Play(t TemplateInterface) {
  fmt.Println("Tennis::Play() [Tennis Game Play!]")
  b.gameTemplate.Play(t)
}
