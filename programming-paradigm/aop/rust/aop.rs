// 引入标准库的 Arc 类型，用于多线程环境下安全共享数据
use std::sync::Arc;

/*
AOP（面向切面编程）是一种编程范式，通过分离横切关注点来提高模块性。
横切关注点是跨越应用程序多个部分的功能，比如日志记录、事务管理等。
Rust中可通过Arc和动态分发实现AOP。
*/

// 定义切面接口，包含前置和后置通知方法
trait Aspect {
    fn before(&self);
    fn after(&self);
}

// 日志切面实现，是 Aspect 接口的一个具体实例
// 该切面的作用是在目标方法执行前后打印日志信息
struct LoggingAspect;
impl Aspect for LoggingAspect {
    fn before(&self) {
        println!("前置通知: 准备执行操作");
    }
    fn after(&self) {
        println!("后置通知: 操作执行完成");
    }
}

// 通用动态代理结构体，包装目标对象和切面对象
struct DynamicProxy<T>
where
    T: ?Sized,
{
    target: Arc<T>,
    // 切面对象，使用 Arc<dyn Aspect> 存储任意实现 Aspect 的类型
    aspect: Arc<dyn Aspect>,
}

impl<T> DynamicProxy<T>
where
    T: ?Sized,
{
    // 构造方法，创建代理实例
    pub fn new(target: Arc<T>, aspect: Arc<dyn Aspect>) -> Self {
        DynamicProxy { target, aspect }
    }

    // 通用代理调用方法，接收一个闭包作为目标方法调用
    // 闭包接受目标对象的引用并返回结果
    // 在闭包执行前后分别触发切面的前置和后置通知
    pub fn call<F, R>(&self, func: F) -> R
    where
        F: FnOnce(&T) -> R,
    {
        self.aspect.before();
        // 调用闭包，执行目标方法
        let result = func(&self.target);
        self.aspect.after();
        result
    }
}

// 业务接口：用户服务
trait UserService {
    fn add_user(&self, username: &str);
    fn delete_user(&self, user_id: i32);
}

// 业务接口实现
struct UserServiceImpl;
impl UserService for UserServiceImpl {
    fn add_user(&self, username: &str) {
        println!("添加用户: {}", username);
    }
    fn delete_user(&self, user_id: i32) {
        println!("删除用户: {}", user_id);
    }
}

// 测试动态代理
fn main() {
    // 创建用户服务实例，并使用 Arc 包装
    let user_service = Arc::new(UserServiceImpl);
    // 创建日志切面对象，并使用 Arc 包装
    let aspect = Arc::new(LoggingAspect);
    // 创建用户服务的代理对象
    let user_proxy = DynamicProxy::new(user_service.clone(), aspect);

    user_proxy.call(|service| service.add_user("张三"));
    user_proxy.call(|service| service.delete_user(101));
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
