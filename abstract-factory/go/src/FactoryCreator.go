package src

type FactoryCreator struct {
}

// 工厂生成器，返回同一业务不同种类的产品工厂
func (f *FactoryCreator) GetFactory(factoryType string) AbstractFactory {
  switch factoryType {
  case "vehicle":
    return &VehicleFactory{}
  case "shop":
    return &ShopFactory{}
  default:
    return nil
  }
}

// 工厂生成器，返回同一业务不同种类的产品工厂，go没有static，可以用一个全局函数
// func CreateFactory(name string) AbstractFactory {
//   switch name {
//   case "vehicle":
//     return new(VehicleFactory)
//   case "shop":
//     return new(ShopFactory)
//   default:
//     return nil
//   }
// }
