package main

import (
  "fmt"

  "microwind/src"
)

// main包下的main入口方法
func main() {
  fmt.Println("test start:")

  /**
   * 模板方法模式就是当子类具备类似行为的时候，让子类共用一套流程
   * 创建一个公共模板，确定公用流程和操作动作，子类覆盖具体的动作
   */
  football := &src.Football{}
  football.Play(football)

  fmt.Println("===")
  basketball := &src.Basketball{}
  basketball.Play(basketball)

  fmt.Println("===")
  tennis := &src.Tennis{}
  tennis.Play(tennis)
}

/**
jarry@jarrys-MacBook-Pro go % go build src/*.go
jarry@jarrys-MacBook-Pro go % go run test/test.go
test start:
GameTemplate::play() [Football]
Football::Init() [Football Game Initialized! Start playing.]
Football::Start() [Football Game Started. Enjoy the game!]
Football::End() [Football Game Finished!]
===
GameTemplate::play() [Basketball]
Basketball::Init() [Basketball Game Initialized! Start playing.]
GameTemplate::play() [GameTemplate Game Initialized! Start playing.]
Basketball::End() [Basketball Game Finished!]
===
Tennis::Play() [Tennis Game Play!]
GameTemplate::play() [Tennis]
Tennis::Init() [Tennis Game Initialized! Start playing.]
Tennis::Start() [Tennis Game Started. Enjoy the game!]
Tennis::End() [Tennis Game Finished!]
*/
