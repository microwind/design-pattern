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

  // 在调用父类play之前，如果要执行自己的行为，也可以覆盖父类方法
  // 先执行自己的，再调用父类的方法
  play() {
    console.log(this.constructor.name + '::play() [Tennis Game play!]')
    super.play()
  }
}
