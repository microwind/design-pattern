use std::sync::Arc;

/* 
AOP（面向切面编程）是一种编程范式，通过分离横切关注点来提高模块性。
横切关注点是跨越应用程序多个部分的功能，比如日志记录、事务管理等。
Rust中可通过trait和动态分发实现AOP。
*/

// 1. 定义业务接口
trait UserService {
    fn add_user(&self, username: &str);
    fn delete_user(&self, user_id: i32);
}

// 2. 实现业务接口
struct UserServiceImpl;

impl UserService for UserServiceImpl {
    fn add_user(&self, username: &str) {
        println!("添加用户: {}", username);
    }

    fn delete_user(&self, user_id: i32) {
        println!("删除用户: {}", user_id);
    }
}

// 3. 定义切面类
struct LoggingAspect;

impl LoggingAspect {
    fn before(&self) {
        println!("前置通知: 准备执行操作");
    }

    fn after(&self) {
        println!("后置通知: 操作执行完成");
    }
}

// 4. 创建动态代理
struct UserServiceProxy {
    target: Arc<dyn UserService>, // 目标对象（被代理的对象）
    aspect: LoggingAspect, // 切面对象（包含横切逻辑）
}

impl UserService for UserServiceProxy {
    fn add_user(&self, username: &str) {
        self.aspect.before(); // 前置通知
        self.target.add_user(username); // 调用目标方法
        self.aspect.after(); // 后置通知
    }

    fn delete_user(&self, user_id: i32) {
        self.aspect.before(); // 前置通知
        self.target.delete_user(user_id); // 调用目标方法
        self.aspect.after(); // 后置通知
    }
}

// 5. 测试AOP
fn main() {
    let user_service = Arc::new(UserServiceImpl);
    let aspect = LoggingAspect;
    let user_proxy = UserServiceProxy {
        target: user_service.clone(),
        aspect,
    };

    user_proxy.add_user("张三");
    user_proxy.delete_user(101);
}

/*
jarry@Mac rust % rustc aop.rs 
jarry@Mac rs % ./aop 
前置通知: 准备执行操作
添加用户: 张三
后置通知: 操作执行完成
前置通知: 准备执行操作
删除用户: 101
后置通知: 操作执行完成
*/