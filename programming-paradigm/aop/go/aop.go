package main

import (
  "fmt"
  "reflect"
)

/*
AOP（面向切面编程）是一种编程范式，通过分离横切关注点来提高模块性。
横切关注点是跨越应用程序多个部分的功能，比如日志记录、事务管理等。
Go语言没有直接的动态代理机制，但可以反射来达成动态代理。
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

// 通用代理函数
func createProxy(target interface{}, aspect *LoggingAspect, methodName string, args ...interface{}) {
  // 前置通知
  aspect.Before()

  // 获取目标对象的反射值
  targetValue := reflect.ValueOf(target)

  // 获取目标方法
  method := targetValue.MethodByName(methodName)

  if method.IsValid() {
    // 准备参数
    in := make([]reflect.Value, len(args))
    for i, arg := range args {
      in[i] = reflect.ValueOf(arg)
    }

    // 调用目标方法
    method.Call(in)
  }

  // 后置通知
  aspect.After()
}

// 4. 创建动态代理结构体
type DynamicServiceProxy struct {
  target interface{}
  aspect *LoggingAspect
}

// 代理结构体构造函数
func NewDynamicServiceProxy(target interface{}, aspect *LoggingAspect) *DynamicServiceProxy {
  return &DynamicServiceProxy{target: target, aspect: aspect}
}

// 通用方法调用代理
func (p *DynamicServiceProxy) Call(methodName string, args ...interface{}) {
  createProxy(p.target, p.aspect, methodName, args...)
}

func main() {
  // 创建目标对象
  userService := &UserServiceImpl{}

  // 创建切面对象
  aspect := &LoggingAspect{}

  // 创建代理对象
  proxyService := NewDynamicServiceProxy(userService, aspect)

  // 通过代理对象调用方法
  proxyService.Call("AddUser", "张三")
  proxyService.Call("DeleteUser", 101)
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
