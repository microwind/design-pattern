import java.lang.reflect.InvocationHandler;
import java.lang.reflect.Method;
import java.lang.reflect.Proxy;

/*
AOP（面向切面编程）是一种编程范式，通过分离横切关注点来提高模块性。
横切关注点是跨越应用程序多个部分的功能，比如日志记录、事务管理等。
在 Java 中，主要是通过 Java 的反射机制和动态代理来实现 AOP 。
态代理允许在运行时创建一个实现了特定接口的代理对象，我们可以在代理对象的方法调用前后插入额外的逻辑，从而实现 AOP 的功能。
*/

// 1. 定义业务接口
interface UserService {
    void addUser(String username);

    void deleteUser(int userId);
}

// 2. 实现业务接口
class UserServiceImpl implements UserService {
    @Override
    public void addUser(String username) {
        System.out.println("添加用户: " + username);
    }

    @Override
    public void deleteUser(int userId) {
        System.out.println("删除用户: " + userId);
    }
}

// 3. 定义切面类
class LoggingAspect {
    public void before() {
        System.out.println("前置通知: 准备执行操作");
    }

    public void after() {
        System.out.println("后置通知: 操作执行完成");
    }
}

// 4. 创建动态代理类
class UserServiceProxy implements InvocationHandler {
    private Object target; // 目标对象（被代理的对象）
    private LoggingAspect aspect; // 切面对象（包含横切逻辑）

    // 构造函数，传入目标对象和切面对象
    public UserServiceProxy(Object target, LoggingAspect aspect) {
        this.target = target;
        this.aspect = aspect;
    }

    // 实现 InvocationHandler 接口的 invoke 方法
    @Override
    public Object invoke(Object proxy, Method method, Object[] args) throws Throwable {
        aspect.before(); // 前置通知：在目标方法执行前调用
        Object result = method.invoke(target, args); // 调用目标方法
        aspect.after(); // 后置通知：在目标方法执行后调用
        return result; // 返回目标方法的执行结果
    }
}

// 5. 测试AOP
public class AOP {
    public static void main(String[] args) {
        // 创建目标对象
        UserService userService = new UserServiceImpl();

        // 创建切面对象
        LoggingAspect aspect = new LoggingAspect();

        // 通过动态代理创建代理对象
        UserService proxy = (UserService) Proxy.newProxyInstance(
                userService.getClass().getClassLoader(), // 目标类的类加载器
                userService.getClass().getInterfaces(), // 目标类实现的接口
                new UserServiceProxy(userService, aspect) // InvocationHandler 实现类
        );

        // 通过代理对象调用 UserService 的方法
        // 调用 addUser 方法时，会先执行前置通知，再执行目标方法，最后执行后置通知
        proxy.addUser("张三");

        // 调用 deleteUser 方法时，同样会先执行前置通知，再执行目标方法，最后执行后置通知
        proxy.deleteUser(101);
    }
}

/*
 * jarry@Mac java % javac AOP.java
 * jarry@Mac java % java AOP
 * 前置通知: 准备执行操作
 * 添加用户: 张三
 * 后置通知: 操作执行完成
 * 前置通知: 准备执行操作
 * 删除用户: 101
 * 后置通知: 操作执行完成
 */