package shop

// 具体产品接口类，规范某类产品的行为
type Shop interface {
  GetName() string
  Greetings()
}
