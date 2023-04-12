package src

// 构建可执行环境上下文
type Context struct {
  Map map[string]int
}

func (c *Context) Init(key string, value int) {
  c.Map = make(map[string]int)
  c.Add(key, value)
}

func (c *Context) Add(key string, value int) {
  if c.Map == nil {
    c.Map = make(map[string]int)
  }
  c.Map[key] = value
}

func (c *Context) Get(key string) int {
  return c.Map[key]
}
