"""
AOP（面向切面编程）是一种编程范式，通过分离横切关注点来提高模块性。
横切关注点是跨越应用程序多个部分的功能，比如日志记录、事务管理等。
Python可以通过装饰器实现AOP的动态代理。
"""

# 1. 定义业务类
class UserService:
    def add_user(self, username):
        print(f"添加用户: {username}")

    def delete_user(self, user_id):
        print(f"删除用户: {user_id}")

# 2. 定义切面类
class LoggingAspect:
    def before(self):
        print("前置通知: 准备执行操作")

    def after(self):
        print("后置通知: 操作执行完成")

# 3. 利用包装器创建动态代理
def create_proxy(target, aspect):
    """
    创建动态代理对象
    :param target: 目标对象（被代理的对象）
    :param aspect: 切面对象（包含横切逻辑）
    :return: 代理对象
    """
    class Proxy:
        def __init__(self, target, aspect):
            self.target = target
            self.aspect = aspect

        def __getattr__(self, name):
            """
            动态获取属性或方法
            :param name: 方法名
            :return: 包装后的方法
            """
            attr = getattr(self.target, name)
            if callable(attr):
                def wrapper(*args, **kwargs):
                    """
                    包装目标方法，插入切面逻辑
                    :param args: 方法参数
                    :param kwargs: 方法关键字参数
                    :return: 目标方法的执行结果
                    """
                    self.aspect.before() # 前置通知
                    result = attr(*args, **kwargs) # 调用目标方法
                    self.aspect.after() # 后置通知
                    return result
                return wrapper
            return attr
    return Proxy(target, aspect)


# 4. 测试AOP
user_service = UserService()
aspect = LoggingAspect()
user_proxy = create_proxy(user_service, aspect)

user_proxy.add_user("张三")
user_proxy.delete_user(101)

"""
jarry@Mac python % python aop.py 
前置通知: 准备执行操作
添加用户: 张三
后置通知: 操作执行完成
前置通知: 准备执行操作
删除用户: 101
后置通知: 操作执行完成
"""