package src

// 观察者抽象父类，定义一些公共方法
type ObserverAPI interface {
  SetSubject(subject Subject)
  GetName() string
  SetName(name string)
  Update(content string)
}

// constructor(name) {
//   this.name = name || this.constructor.name
// }

//   // 观察者发出更新通知，观察者自行监听
//   update(content) {
//     fmt.Println(`${this.constructor.name}::update() [content = ${content}]`)
//   }

//   setName(name) {
//     this.name = name
//   }
// }
