package src

// 定义通用Handler接口，统一类型
type Handler interface {
	SetNext(handler Handler)
	GetNext() Handler
	Check(uid int) bool
}
