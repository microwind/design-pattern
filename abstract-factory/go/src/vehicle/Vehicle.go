package vehicle

// 具体产品接口类，规范某类产品的行为
type Vehicle interface {
	GetName() string
	Run()
}
