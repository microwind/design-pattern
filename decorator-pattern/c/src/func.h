#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// 基础形状类，可定义公共方法
typedef struct Shape
{
    char name[50];
    void (*draw)(struct Shape *);
} Shape;

// 具体形状实现了基础形状接口
typedef struct Circle
{
    char name[50];
    void (*draw)(struct Circle *);
} Circle;
Circle *circle_constructor(char *name);

// 具体形状实现了基础形状接口
typedef struct Square
{
    char name[50];
    void (*draw)(struct Square *);
} Square;
Square *square_constructor(char *name);

// 抽象装饰器接口
typedef struct ShapeDecorator
{
    char name[50];
    void (*draw)(struct ShapeDecorator *);
    struct ShapeDecorator *decorated_shape;
    // void (*set_red_color)(struct ShapeDecorator *);
    // void (*set_shadow)(struct ShapeDecorator *);
} ShapeDecorator;

// 具体装饰器1，实现基础装饰器接口
typedef struct RedShapeDecorator
{
    char name[50];
    void (*draw)(struct RedShapeDecorator *);
    // 聚合具体形状对象
    struct ShapeDecorator *decorated_shape;
    void (*set_red_color)(struct RedShapeDecorator *);
} RedShapeDecorator;
RedShapeDecorator *red_shape_decorator_constructor(char *, ShapeDecorator *);

// 具体装饰器2，实现基础装饰器接口
typedef struct ShadowShapeDecorator
{
    char name[50];
    void (*draw)(struct ShadowShapeDecorator *);
    // 聚合具体形状对象
    struct ShapeDecorator *decorated_shape;
    void (*set_shadow)(struct ShadowShapeDecorator *);
} ShadowShapeDecorator;
ShadowShapeDecorator *shadow_shape_decorator_constructor(char *, ShapeDecorator *);