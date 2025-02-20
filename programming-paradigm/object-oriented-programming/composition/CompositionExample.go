/*
组合是一个物体由不同部分组合而成，组合里的部分类一般不会单独运行。
本示例：
- 展示了Car类由Engine和Transmission组合而成。
- 组合关系：Car类包含了Engine和Transmission对象。这种"has-a"关系允许汽车使用这些组件，但它们也可以独立于汽车存在。
- 封装和抽象：汽车与引擎和变速箱之间的关系是通过组合实现的。通过封装，汽车不必了解引擎和变速箱的内部细节，只需通过公开的方法与它们交互。
- 灵活性：由于组合关系的松散耦合，您可以轻松地更改汽车的引擎和变速箱，而无需大幅度修改汽车类。这提供了组件化和模块化的好处。
*/

package main

import "fmt"

// 定义引擎结构体
type Engine struct {
  Type string // 引擎类型，如汽油、柴油、混合动力等
}

// 启动引擎的方法
func (e *Engine) Start() {
  fmt.Printf("Engine (%s) is starting...\n", e.Type)
}

// 停止引擎的方法
func (e *Engine) Stop() {
  fmt.Printf("Engine (%s) is stopping...\n", e.Type)
}

// 定义变速箱结构体
type Transmission struct {
  GearType string // 变速箱类型，如手动或自动
}

// 换挡的方法
func (t *Transmission) ChangeGear(gear int) {
  fmt.Printf("Transmission (%s) is changing to gear %d\n", t.GearType, gear)
}

// 定义汽车结构体
type Car struct {
  Make         string        // 汽车的制造商
  Model        string        // 汽车的型号
  Engine       *Engine       // 汽车的引擎
  Transmission *Transmission // 汽车的变速箱
}

// 启动汽车的方法
func (c *Car) Start() {
  fmt.Printf("%s %s is starting...\n", c.Make, c.Model)
  c.Engine.Start()             // 启动引擎
  c.Transmission.ChangeGear(1) // 换到一挡
}

// 停止汽车的方法
func (c *Car) Stop() {
  fmt.Printf("%s %s is stopping...\n", c.Make, c.Model)
  c.Engine.Stop() // 停止引擎
}

func main() {
  // 创建引擎和变速箱对象
  gasolineEngine := &Engine{"Gasoline"}
  manualTransmission := &Transmission{"Manual"}

  // 创建汽车对象，并将引擎和变速箱与之关联
  myCar := &Car{"Toyota", "Corolla", gasolineEngine, manualTransmission}

  // 启动和停止汽车
  myCar.Start() // 输出：Toyota Corolla is starting... Engine (Gasoline) is starting...
  // Transmission (Manual) is changing to gear 1
  myCar.Stop() // 输出：Toyota Corolla is stopping... Engine (Gasoline) is stopping...
}
