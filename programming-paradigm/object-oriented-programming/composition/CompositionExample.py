'''
组合是一个物体由不同部分组合而成，组合里的部分类一般不会单独运行。
本示例：
- 展示了Car类由Engine和Transmission组合而成。
- 组合关系：Car类包含了Engine和Transmission对象。这种"has-a"关系允许汽车使用这些组件，但它们也可以独立于汽车存在。
- 封装和抽象：汽车与引擎和变速箱之间的关系是通过组合实现的。通过封装，汽车不必了解引擎和变速箱的内部细节，只需通过公开的方法与它们交互。
- 灵活性：由于组合关系的松散耦合，您可以轻松地更改汽车的引擎和变速箱，而无需大幅度修改汽车类。这提供了组件化和模块化的好处。
'''

# 定义引擎类
class Engine:
    def __init__(self, type):
        self.type = type  # 初始化引擎类型

    def start(self):
        print(f"Engine ({self.type}) is starting...")  # 启动引擎

    def stop(self):
        print(f"Engine ({self.type}) is stopping...")  # 停止引擎

# 定义变速箱类
class Transmission:
    def __init__(self, gear_type):
        self.gear_type = gear_type  # 初始化变速箱类型

    def change_gear(self, gear):
        print(f"Transmission ({self.gear_type}) is changing to gear {gear}")  # 换挡

# 定义汽车类，包含引擎和变速箱
class Car:
    def __init__(self, make, model, engine, transmission):
        self.make = make  # 初始化汽车制造商
        self.model = model  # 初始化汽车型号
        self.engine = engine  # 组合：将引擎对象关联到汽车
        self.transmission = transmission  # 组合：将变速箱对象关联到汽车

    def start(self):
        print(f"{self.make} {self.model} is starting...")
        self.engine.start()  # 启动引擎
        self.transmission.change_gear(1)  # 换到一挡

    def stop(self):
        print(f"{self.make} {self.model} is stopping...")
        self.engine.stop()  # 停止引擎

# 创建引擎和变速箱对象
gasoline_engine = Engine("Gasoline")
manual_transmission = Transmission("Manual")

# 创建汽车对象，并将引擎和变速箱与之关联
my_car = Car("Toyota", "Corolla", gasoline_engine, manual_transmission)

# 启动和停止汽车
my_car.start()  # 输出：Toyota Corolla is starting... Engine (Gasoline) is starting...
                # Transmission (Manual) is changing to gear 1
my_car.stop()   # 输出：Toyota Corolla is stopping... Engine (Gasoline) is stopping...
