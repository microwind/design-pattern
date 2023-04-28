package src

import "fmt"

// 定义抽象模板类的公共部分，这里用struct替代
type GameTemplate struct {
}

// 抽象方法待子类来实现
func (g *GameTemplate) Init() {}
func (g *GameTemplate) Start() {
  fmt.Println("GameTemplate::play() [GameTemplate Game Initialized! Start playing.]")
}
func (g *GameTemplate) End() {}

// 可复用的算法流程
func (g *GameTemplate) Play(t TemplateInterface) {
  fmt.Println("GameTemplate::play() [" + t.GetName() + "]")

  // 初始化游戏
  t.Init()

  // 开始游戏
  t.Start()

  // 结束游戏
  t.End()
}
