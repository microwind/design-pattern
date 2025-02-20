/* 
组合是一个物体由不同部分组合而成，组合里的部分类一般不会单独运行。
本示例：
- 展示了Car类由Engine和Transmission组合而成。
- 组合关系：Car类包含了Engine和Transmission对象。这种"has-a"关系允许汽车使用这些组件，但它们也可以独立于汽车存在。
- 封装和抽象：汽车与引擎和变速箱之间的关系是通过组合实现的。通过封装，汽车不必了解引擎和变速箱的内部细节，只需通过公开的方法与它们交互。
- 灵活性：由于组合关系的松散耦合，您可以轻松地更改汽车的引擎和变速箱，而无需大幅度修改汽车类。这提供了组件化和模块化的好处。
*/

// 定义引擎类
class Engine {
  private type: string // 引擎类型，如汽油、柴油、混合动力等

  constructor(type: string) {
    this.type = type // 初始化引擎类型
  }

  start(): void {
    console.log(`Engine (${this.type}) is starting...`) // 启动引擎
  }

  stop(): void {
    console.log(`Engine (${this.type}) is stopping...`) // 停止引擎
  }
}

// 定义变速箱类
class Transmission {
  private gearType: string // 变速箱类型，如手动或自动

  constructor(gearType: string) {
    this.gearType = gearType // 初始化变速箱类型
  }

  changeGear(gear: number): void {
    console.log(`Transmission (${this.gearType}) is changing to gear ${gear}`) // 换挡
  }
}

// 定义汽车类，包含引擎和变速箱
class Car {
  private engine: Engine // 汽车的引擎
  private transmission: Transmission // 汽车的变速箱
  private make: string // 汽车的制造商
  private model: string // 汽车的型号

  constructor(
    make: string,
    model: string,
    engine: Engine,
    transmission: Transmission
  ) {
    this.make = make // 初始化汽车制造商
    this.model = model // 初始化汽车型号
    this.engine = engine // 组合：将引擎对象关联到汽车
    this.transmission = transmission // 组合：将变速箱对象关联到汽车
  }

  start(): void {
    console.log(`${this.make} ${this.model} is starting...`)
    this.engine.start() // 启动引擎
    this.transmission.changeGear(1) // 换到一挡
  }

  stop(): void {
    console.log(`${this.make} ${this.model} is stopping...`)
    this.engine.stop() // 停止引擎
  }
}

// 创建引擎和变速箱对象
const gasolineEngine: Engine = new Engine('Gasoline')
const manualTransmission: Transmission = new Transmission('Manual')

// 创建汽车对象，并将引擎和变速箱与之关联
const myCar: Car = new Car(
  'Toyota',
  'Corolla',
  gasolineEngine,
  manualTransmission
)

// 启动和停止汽车
myCar.start() // 输出：Toyota Corolla is starting... Engine (Gasoline) is starting...
// Transmission (Manual) is changing to gear 1
myCar.stop() // 输出：Toyota Corolla is stopping... Engine (Gasoline) is stopping...
