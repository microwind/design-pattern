import { GameTemplate } from './GameTemplate.js'

// 定义子类覆写父类抽象方法
export class Tennis extends GameTemplate {
  init() {
    console.log('Tennis::init() [Tennis Game Initialized! Start playing.]')
  }

  start() {
    console.log('Tennis::start() [Tennis Game Started. Enjoy the game!]')
  }

  end() {
    console.log('Tennis::end() [Tennis Game Finished!]')
  }
}
