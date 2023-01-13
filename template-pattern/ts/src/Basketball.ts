import { GameTemplate } from './GameTemplate.js'

// 定义子类覆写父类抽象方法
export class Basketball extends GameTemplate {
  override init() {
    console.log(
      'Basketball::init() [Basketball Game Initialized! Start playing.]'
    )
  }

  override start() {
    console.log(
      'Basketball::start() [Basketball Game Started. Enjoy the game!]'
    )
  }

  override end() {
    console.log('Basketball::end() [Basketball Game Finished!]')
  }
}
