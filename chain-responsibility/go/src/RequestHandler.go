package src

import (
  "fmt"
  "strconv"
)

// 请求是否安全合法检查
type RequestHandler struct {
  Name            string
  next            Handler
  abstractHandler *AbstractHandler
}

func (r *RequestHandler) SetNext(handler Handler) {
  r.next = handler
}

func (r *RequestHandler) GetNext() Handler {
  return r.next
}

// 如果检查不通过则返回失败，否则继续下一个检查
func (r *RequestHandler) Check(uid int) bool {
  fmt.Println("RequestHandler::Check() [uid = " + strconv.Itoa(uid) + "]")
  if uid%1 != 0 {
    return false
  }
  // 通过聚合类来调用下一步检查
  return r.abstractHandler.CheckNext(r, uid)
}
