#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// 基础Vehicle对象
typedef struct Vehicle
{
    char name[50];
    void (*run)(struct Vehicle *);
} Vehicle;

// Bus对象
typedef struct Bus
{
    char name[50];
    void (*run)(struct Vehicle *);
} Bus;

// Bus构造函数
Bus *bus_constructor(char *name);

// Car对象
typedef struct Car
{
    char name[50];
    void (*run)(Vehicle *);
} Car;

// Car构造函数
Car *car_constructor(char *name);

// Motorcycle对象
typedef struct Motorcycle
{
    char name[50];
    void (*run)(Vehicle *);
} Motorcycle;

// Motorcycle构造函数
Motorcycle *motorcycle_constructor(char *name);

// Van对象
typedef struct Van
{
    char name[50];
    void (*run)(Vehicle *);
} Van;

// Van构造函数
Van *van_constructor(char *name);

// shop类型
enum shop_types
{
    AGENCY_SHOP_TYPE = 1,  // 1 代理商
    DIRECT_SALE_SHOP_TYPE, // 2 直销
    SUPERMARKET_SHOP_TYPE  // 3 超市
};

// 基础Shop对象
typedef struct Shop
{
    char name[50];
    void (*greetings)(struct Shop *);
} Shop;

typedef struct AgencyShop
{
    char name[50];
    void (*greetings)(Shop *);
} AgencyShop;
AgencyShop *agency_shop_constructor(char *name);

typedef struct DirectSaleShop
{
    char name[50];
    void (*greetings)(Shop *);
    void (*welcome)();
} DirectSaleShop;
DirectSaleShop *direct_sale_shop_constructor(char *name);

typedef struct SupermarketShop
{
    char name[50];
    void (*greetings)(Shop *);
} SupermarketShop;
SupermarketShop *supermarket_shop_constructor(char *name);

// 抽象工厂，定义有哪些工厂
typedef struct AbstractFactory
{
    struct Vehicle *(*get_vehicle)(char *type, char *name);
    struct Shop *(*get_shop)(int type, char *name);
} AbstractFactory;

// Vehicle工厂，实现抽象工厂
typedef struct VehicleFactory
{
    struct Vehicle *(*get_vehicle)(char *type, char *name);
    struct Shop *(*get_shop)(int type, char *name);
} VehicleFactory;
VehicleFactory *create_vehicle_factory();

// Shop工厂，实现抽象工厂
typedef struct ShopFactory
{
    struct Vehicle *(*get_vehicle)(char *type, char *name);
    struct Shop *(*get_shop)(int type, char *name);
} ShopFactory;
ShopFactory *create_shop_factory();

// 工厂创建者，返回某类工厂建造者
typedef struct FactoryCreatory
{
    AbstractFactory *(*get_factory)(char *name);
} FactoryCreatory;

FactoryCreatory *factory_creatory_constructor();