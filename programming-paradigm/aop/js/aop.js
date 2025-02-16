/* 
AOP（面向切面编程）是一种编程范式，通过分离横切关注点来提高模块性。
横切关注点是跨越应用程序多个部分的功能，比如日志记录、事务管理等。
JavaScript语言非常灵活，可以通过高阶函数和Proxy轻易地实现AOP。
*/

// 1. 定义业务类
class UserService {
  addUser(username) {
    console.log(`添加用户: ${username}`);
  }

  deleteUser(userId) {
    console.log(`删除用户: ${userId}`);
  }
}

// 2. 定义切面类
class LoggingAspect {
  before() {
    console.log("前置通知: 准备执行操作");
  }

  after() {
    console.log("后置通知: 操作执行完成");
  }
}

// 3. 创建Proxy动态代理
function createProxy(target, aspect) {
  return new Proxy(target, {
    get(target, propKey, receiver) {
      const originalMethod = target[propKey];
      if (typeof originalMethod === 'function') {
        return function (...args) {
          aspect.before();
          const result = originalMethod.apply(target, args);
          aspect.after();
          return result;
        };
      }
      return originalMethod;
    }
  });
}

// 4. 测试AOP
const userService = new UserService();
const aspect = new LoggingAspect();
const userProxy = createProxy(userService, aspect);

userProxy.addUser("张三");
userProxy.deleteUser(101);

/*
jarry@Mac js % node aop.js 
前置通知: 准备执行操作
添加用户: 张三
后置通知: 操作执行完成
前置通知: 准备执行操作
删除用户: 101
后置通知: 操作执行完成
*/