package src

import (
  "fmt"
  "strconv"
)

// 用户基本信息检查类
type UserHandler struct {
  Name            string
  next            Handler
  abstractHandler *AbstractHandler
}

func (u *UserHandler) SetNext(handler Handler) {
  u.next = handler
}

func (u *UserHandler) GetNext() Handler {
  return u.next
}

// 如果检查不通过则返回失败，否则继续下一个检查
func (u *UserHandler) Check(uid int) bool {
  fmt.Println("UserHandler::Check() [uid = " + strconv.Itoa(uid) + "]")
  if uid%3 == 0 {
    return false
  }
  // 通过聚合类来调用下一步检查
  return u.abstractHandler.CheckNext(u, uid)
}
