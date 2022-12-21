package src

// 定义策略执行对象context
type Context struct {
	strategy Strategy
}

// 设置不同strategy，方法名首字母大写
func (c *Context) SetStrategy(s Strategy) {
	c.strategy = s
}

// 执行策略接口里面的方法
func (c *Context) Run() {
	c.strategy.Run()
}
