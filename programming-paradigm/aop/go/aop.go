package main

import (
  "fmt"
)

/*
AOP（面向切面编程）是一种编程范式，通过分离横切关注点来提高模块性。
横切关注点是跨越应用程序多个部分的功能，比如日志记录、事务管理等。
Go语言没有直接的动态代理机制，但可以通过接口和函数包装实现AOP。
Go这种机构相比动态代理更加巧妙和高性能，但代码会比较啰嗦，每个类都要单独写
*/

// 1. 定义业务接口
type UserService interface {
  AddUser(username string)
  DeleteUser(userId int)
}

// 2. 实现业务接口
type UserServiceImpl struct{}

func (u *UserServiceImpl) AddUser(username string) {
  fmt.Printf("添加用户: %s\n", username)
}

func (u *UserServiceImpl) DeleteUser(userId int) {
  fmt.Printf("删除用户: %d\n", userId)
}

// 3. 定义切面类
type LoggingAspect struct{}

func (l *LoggingAspect) Before() {
  fmt.Println("前置通知: 准备执行操作")
}

func (l *LoggingAspect) After() {
  fmt.Println("后置通知: 操作执行完成")
}

// 4. 创建动态代理类
type UserServiceProxy struct {
  target UserService
  aspect *LoggingAspect
}

// 代理类构造函数，传入目标对象和切面对象
func NewUserServiceProxy(target UserService, aspect *LoggingAspect) UserService {
  return &UserServiceProxy{target: target, aspect: aspect}
}

// 每个函数都实现相一遍，增加前后调用
func (p *UserServiceProxy) AddUser(username string) {
  p.aspect.Before()
  p.target.AddUser(username)
  p.aspect.After()
}

// 每个函数都实现相一遍，增加前后调用
func (p *UserServiceProxy) DeleteUser(userId int) {
  p.aspect.Before()
  p.target.DeleteUser(userId)
  p.aspect.After()
}

// 5. 测试AOP
func main() {
  // 创建目标对象
  userService := &UserServiceImpl{}

  // 创建切面对象
  aspect := &LoggingAspect{}

  // 创建代理对象
  proxy := NewUserServiceProxy(userService, aspect)

  // 通过代理对象调用方法
  proxy.AddUser("张三")
  proxy.DeleteUser(101)
}

/*
jarry@Mac go % go run aop.go
前置通知: 准备执行操作
添加用户: 张三
后置通知: 操作执行完成
前置通知: 准备执行操作
删除用户: 101
后置通知: 操作执行完成
*/
