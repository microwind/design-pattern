package src

import (
  "fmt"
  "strconv"
)

// 权限检查类
type AuthHandler struct {
  Name            string
  next            Handler
  abstractHandler *AbstractHandler
}

func (a *AuthHandler) SetNext(handler Handler) {
  a.next = handler
}

func (a *AuthHandler) GetNext() Handler {
  return a.next
}

// 如果检查不通过则返回失败，否则继续下一个检查
func (a *AuthHandler) Check(uid int) bool {
  fmt.Println("AuthHandler::Check() [uid = " + strconv.Itoa(uid) + "]")
  if uid%2 == 0 {
    return false
  }
  // 通过聚合类来调用下一步检查
  return a.abstractHandler.CheckNext(a, uid)
}
