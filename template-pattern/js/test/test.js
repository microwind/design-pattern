import { Football } from '../src/Football.js'
import { Tennis } from '../src/Tennis.js'
import { Basketball } from '../src/Basketball.js'

export function test() {
  /**
   * 模板方法模式就是当子类具备类似行为的时候，让子类共用一套流程
   * 创建一个公共模板，确定公用流程和操作动作，子类覆盖具体的动作
   */
  const football = new Football()
  football.play()

  console.log('===')
  const basketball = new Basketball()
  basketball.play()

  console.log('===')
  const tennis = new Tennis()
  tennis.play()
}

// 执行测试
;(function () {
  console.log('test start:')
  test()
})()
/**
// npm run
jarry@jarrys-MacBook-Pro js % npm run test
// or node execution
jarry@jarrys-MacBook-Pro js % node test/test.js
test start:
Football::play()
Football::init() [Football Game Initialized! Start playing.]
Football::start() [Football Game Started. Enjoy the game!]
Football::end() [Football Game Finished!]
===
Basketball::play()
Basketball::init() [Basketball Game Initialized! Start playing.]
Basketball::start() [Basketball Game Started. Enjoy the game!]
Basketball::end() [Basketball Game Finished!]
===
Tennis::play() [Tennis Game play!]
Tennis::play()
Tennis::init() [Tennis Game Initialized! Start playing.]
Tennis::start() [Tennis Game Started. Enjoy the game!]
Tennis::end() [Tennis Game Finished!]
*/
