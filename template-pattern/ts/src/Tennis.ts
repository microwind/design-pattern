import { GameTemplate } from './GameTemplate.js'

// 定义子类覆写父类抽象方法
export class Tennis extends GameTemplate {
  override init() {
    console.log('Tennis::init() [Tennis Game Initialized! Start playing.]')
  }

  override start() {
    console.log('Tennis::start() [Tennis Game Started. Enjoy the game!]')
  }

  override end() {
    console.log('Tennis::end() [Tennis Game Finished!]')
  }
}
