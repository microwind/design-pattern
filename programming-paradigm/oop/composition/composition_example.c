/*
组合是一个物体由不同部分组合而成，组合里的部分类一般不会单独运行。
本示例：
- 展示了Car类由Engine和Transmission组合而成。
- 组合关系：Car类包含了Engine和Transmission对象。这种"has-a"关系允许汽车使用这些组件，但它们也可以独立于汽车存在。
- 封装和抽象：汽车与引擎和变速箱之间的关系是通过组合实现的。通过封装，汽车不必了解引擎和变速箱的内部细节，只需通过公开的方法与它们交互。
- 灵活性：由于组合关系的松散耦合，您可以轻松地更改汽车的引擎和变速箱，而无需大幅度修改汽车类。这提供了组件化和模块化的好处。
*/

#include <stdio.h>
#include <stdlib.h>

// 定义引擎结构体
struct Engine
{
    char *type; // 引擎类型，如汽油、柴油、混合动力等
};

// 创建引擎对象的函数
struct Engine *create_engine(char *type)
{
    struct Engine *engine = (struct Engine *)malloc(sizeof(struct Engine));
    engine->type = type;
    return engine;
}

// 启动引擎的函数
void start_engine(struct Engine *engine)
{
    printf("Engine (%s) is starting...\n", engine->type);
}

// 停止引擎的函数
void stop_engine(struct Engine *engine)
{
    printf("Engine (%s) is stopping...\n", engine->type);
}

// 定义变速箱结构体
struct Transmission
{
    char *gearType; // 变速箱类型，如手动或自动
};

// 创建变速箱对象的函数
struct Transmission *create_transmission(char *gearType)
{
    struct Transmission *transmission = (struct Transmission *)malloc(sizeof(struct Transmission));
    transmission->gearType = gearType;
    return transmission;
}

// 换挡的函数
void change_gear(struct Transmission *transmission, int gear)
{
    printf("Transmission (%s) is changing to gear %d\n", transmission->gearType, gear);
}

// 定义汽车结构体
struct Car
{
    struct Engine *engine;             // 汽车的引擎
    struct Transmission *transmission; // 汽车的变速箱
    char *make;                        // 汽车的制造商
    char *model;                       // 汽车的型号
};

// 创建汽车对象的函数
struct Car *create_car(char *make, char *model, struct Engine *engine, struct Transmission *transmission)
{
    struct Car *car = (struct Car *)malloc(sizeof(struct Car));
    car->make = make;
    car->model = model;
    car->engine = engine;
    car->transmission = transmission;
    return car;
}

// 启动汽车的函数
void start_car(struct Car *car)
{
    printf("%s %s is starting...\n", car->make, car->model);
    start_engine(car->engine);         // 启动引擎
    change_gear(car->transmission, 1); // 换到一挡
}

// 停止汽车的函数
void stop_car(struct Car *car)
{
    printf("%s %s is stopping...\n", car->make, car->model);
    stop_engine(car->engine); // 停止引擎
}

// 主函数
int main()
{
    // 创建引擎和变速箱对象
    struct Engine *gasolineEngine = create_engine("Gasoline");
    struct Transmission *manualTransmission = create_transmission("Manual");

    // 创建汽车对象，并将引擎和变速箱与之关联
    struct Car *myCar = create_car("Toyota", "Corolla", gasolineEngine, manualTransmission);

    // 启动和停止汽车
    start_car(myCar); // 输出：Toyota Corolla is starting... Engine (Gasoline) is starting...
                      // Transmission (Manual) is changing to gear 1
    stop_car(myCar);  // 输出：Toyota Corolla is stopping... Engine (Gasoline) is stopping...

    // 释放内存
    free(gasolineEngine);
    free(manualTransmission);
    free(myCar);

    return 0;
}

/*
jarry@jarrys-MacBook-Pro composition % gcc composition_example.c 
jarry@jarrys-MacBook-Pro composition % ./a.out 
Toyota Corolla is starting...
Engine (Gasoline) is starting...
Transmission (Manual) is changing to gear 1
Toyota Corolla is stopping...
Engine (Gasoline) is stopping...
*/