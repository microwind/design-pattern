import java.lang.reflect.InvocationHandler;
import java.lang.reflect.Method;
import java.lang.reflect.Proxy;
import java.util.ArrayList;
import java.util.List;
/*
AOP（面向切面编程）是一种编程范式，通过分离横切关注点来提高模块性。
横切关注点是跨越应用程序多个部分的功能，比如日志记录、事务管理等。
在 Java 中，主要是通过 Java 的反射机制和动态代理来实现 AOP 。
态代理允许在运行时创建一个实现了特定接口的代理对象，我们可以在代理对象的方法调用前后插入额外的逻辑，从而实现 AOP 的功能。
*/

// 1. 定义通用的切面接口（可扩展）
interface Aspect {
    void before(Method method, Object[] args);

    void after(Method method, Object result);
}

// 2. 日志切面实现
class LoggingAspect implements Aspect {
    @Override
    public void before(Method method, Object[] args) {
        System.out.println("前置通知: 调用 " + method.getName() + "，参数: " + java.util.Arrays.toString(args));
    }

    @Override
    public void after(Method method, Object result) {
        System.out.println("后置通知: " + method.getName() + " 执行完成，返回值: " + result);
    }
}

// 3. 通用动态代理类
class DynamicProxy implements InvocationHandler {
    private final Object target; // 目标对象
    private final List<Aspect> aspects; // 切面列表

    public DynamicProxy(Object target, List<Aspect> aspects) {
        this.target = target;
        this.aspects = aspects;
    }

    @Override
    public Object invoke(Object proxy, Method method, Object[] args) throws Throwable {
        for (Aspect aspect : aspects) {
            aspect.before(method, args);
        }
        Object result = method.invoke(target, args); // 调用目标方法
        for (Aspect aspect : aspects) {
            aspect.after(method, result);
        }
        return result;
    }

    // 创建代理对象的通用方法
    @SuppressWarnings("unchecked")
    public static <T> T createProxy(T target, List<Aspect> aspects) {
        return (T) Proxy.newProxyInstance(
                target.getClass().getClassLoader(),
                target.getClass().getInterfaces(),
                new DynamicProxy(target, aspects));
    }
}

// 4. 业务接口
interface UserService {
    void addUser(String username);

    void deleteUser(int userId);
}

// 5. 业务实现类
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

// 6. 测试 AOP 代理
public class AOP {
    public static void main(String[] args) {
        // 创建目标对象
        UserService userService = new UserServiceImpl();

        // 创建切面列表
        List<Aspect> aspects = new ArrayList<>();
        aspects.add(new LoggingAspect()); // 可以添加多个切面

        // 通过动态代理创建 UserService 代理对象
        UserService proxy = DynamicProxy.createProxy(userService, aspects);

        // 调用代理方法，自动执行 AOP 逻辑
        proxy.addUser("张三");
        proxy.deleteUser(101);
    }
}
/*
jarry@MacBook-Pro java % java AOP.java
前置通知: 调用 addUser，参数: [张三]
添加用户: 张三
后置通知: addUser 执行完成，返回值: null
前置通知: 调用 deleteUser，参数: [101]
删除用户: 101
后置通知: deleteUser 执行完成，返回值: null
 */