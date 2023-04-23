#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Shape shape;
typedef struct Circle circle;
typedef struct Rectangle rectangle;
typedef struct Square square;

// 定义了Shape作为基础接口，以便各形状有统一类型
typedef struct Shape
{
    char name[50];
    int width;
    int height;
    char color[50];
    char category[50];
    void (*draw)(struct Shape *shape);
    struct Shape *(*clone)(struct Shape *shape);
    char *(*to_string)(struct Shape *shape);
    void (*set_width)(struct Shape *shape, int width);
    int (*get_width)(struct Shape *shape);
    void (*set_height)(struct Shape *shape, int height);
    int (*get_height)(struct Shape *shape);
    void (*set_color)(struct Shape *shape, char *color);
    char *(*get_color)(struct Shape *shape);
    void (*set_category)(struct Shape *shape, char *category);
    char *(*get_category)(struct Shape *shape);
} Shape;
Shape *shape_constructor(char *name);

typedef struct Circle
{
    char name[50];
    int width;
    int height;
    char color[50];
    char category[50];
    void (*draw)(struct Circle *shape);
    struct Circle *(*clone)(struct Circle *shape);
    char *(*to_string)(struct Circle *shape);
    void (*set_width)(struct Circle *shape, int width);
    int (*get_width)(struct Circle *shape);
    void (*set_height)(struct Circle *shape, int height);
    int (*get_height)(struct Circle *shape);
    void (*set_color)(struct Circle *shape, char *color);
    char *(*get_color)(struct Circle *shape);
    void (*set_category)(struct Circle *shape, char *category);
    char *(*get_category)(struct Circle *shape);
} Circle;
Circle *circle_constructor(char *name);

typedef struct Square
{
    char name[50];
    int width;
    int height;
    char color[50];
    char category[50];
    void (*draw)(struct Square *shape);
    struct Square *(*clone)(struct Square *shape);
    char *(*to_string)(struct Square *shape);
    void (*set_width)(struct Square *shape, int width);
    int (*get_width)(struct Square *shape);
    void (*set_height)(struct Square *shape, int height);
    int (*get_height)(struct Square *shape);
    void (*set_color)(struct Square *shape, char *color);
    char *(*get_color)(struct Square *shape);
    void (*set_category)(struct Square *shape, char *category);
    char *(*get_category)(struct Square *shape);
} Square;
Square *square_constructor(char *name);

typedef struct Rectangle
{
    char name[50];
    int width;
    int height;
    char color[50];
    char category[50];
    void (*draw)(struct Rectangle *shape);
    struct Rectangle *(*clone)(struct Rectangle *shape);
    char *(*string)(struct Rectangle *shape);
    void (*set_width)(struct Rectangle *shape, int width);
    int *(*get_width)(struct Rectangle *shape);
    void (*set_height)(struct Rectangle *shape, int height);
    int *(*get_height)(struct Rectangle *shape);
    void (*set_color)(struct Rectangle *shape, char *color);
    char *(*get_color)(struct Rectangle *shape);
    void (*set_category)(struct Rectangle *shape, char *category);
    char *(*get_category)(struct Rectangle *shape);
} Rectangle;
Rectangle *rectangle_constructor(char *name);

// 调用客户端
typedef struct Application
{
    struct Shape **shapes;
    int shapes_length;
    void (*add_to_shapes)(struct Application *app);
    void (*add_shape)(struct Application *app, Shape *shape);
    Shape *(*get_shape)(struct Application *app, int index);
    Shape **(*get_shapes)(struct Application *app);
    Shape *(*get_shape_clone)(struct Application *app, int index);
    void (*print_shapes)(struct Application *app);
} Application;
Application *application_constructor();