import { GameTemplate } from './GameTemplate.js'

// 定义子类覆写父类抽象方法
export class Football extends GameTemplate {
  init() {
    console.log('Football::init() [Football Game Initialized! Start playing.]')
  }

  start() {
    console.log('Football::start() [Football Game Started. Enjoy the game!]')
  }

  end() {
    console.log('Football::end() [Football Game Finished!]')
  }
}
