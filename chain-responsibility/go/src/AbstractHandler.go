package src

// 事件基础类，聚合所有公共方法，所有处理变成链式，可以互动干涉，动态组合
// go中没有抽象类，因此将统一类型抽取为interface，公共方法单独放在一个类或用独立函数替代
type AbstractHandler struct {
}

// 创建调用链，传入多个handler，按顺序形成链，返回第一个handler
func (a *AbstractHandler) Link(first Handler, chain ...Handler) Handler {
  var head = first
  for _, handler := range chain {
    head.SetNext(handler)
    head = handler
  }

  return first
}

// 继续下一个检查
func (a *AbstractHandler) CheckNext(hander Handler, uid int) bool {
  // 如果没有next了表示链条检查完毕，返回true
  if hander.GetNext() == nil {
    return true
  }
  return hander.GetNext().Check(uid)
}
