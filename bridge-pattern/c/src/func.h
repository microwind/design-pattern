#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// 定义图形对象基础类，聚合了图形操作接口
// 相当于桥接了具体形状对象与具体的操作工具
typedef struct AbstractShape
{
    char name[50];
    struct DrawTool *draw_tool;
    void (*set_draw_tool)(struct AbstractShape *, struct DrawTool *);
    struct DrawTool *(*get_draw_tool)(struct AbstractShape *);
    void (*draw)(struct AbstractShape *, int, int, int);
    void (*draw_done)(struct AbstractShape *);
} AbstractShape;
void set_draw_tool(AbstractShape *shape, struct DrawTool *draw_tool);
struct DrawTool *get_draw_tool(AbstractShape *shape);

// 重新定义了对象类来实现桥接器，聚合了具体的操作工具
// 可能存在多个具体对象类，这里用一个表示
typedef struct RefinedShape
{
    char name[50];
    struct DrawTool *draw_tool;
    void (*set_draw_tool)(struct AbstractShape *, struct DrawTool *);
    struct DrawTool *(*get_draw_tool)(struct AbstractShape *);
    void (*draw)(struct AbstractShape *, int, int, int);
    void (*draw_done)(struct RefinedShape *);
} RefinedShape;
RefinedShape *refined_shape_constructor(char *name);

// 图形操作基础接口，供具体工具来实现
typedef struct DrawTool
{
    char name[50];
    char *(*get_name)(struct DrawTool *);
    void (*draw_style)(AbstractShape *);
} DrawTool;
char *get_draw_tool_name(DrawTool *draw_tool);

// 画圆A，实现了图画基础API
typedef struct DrawStyleA
{
    char name[50];
    char *(*get_name)(struct DrawTool *);
    void (*draw_style)(AbstractShape *);
} DrawStyleA;
DrawStyleA *draw_style_a_constructor(char *name);

// 画圆B，实现了图画基础API
typedef struct DrawStyleB
{
    char name[50];
    char *(*get_name)(struct DrawTool *);
    void (*draw_style)(AbstractShape *);
} DrawStyleB;
DrawStyleB *draw_style_b_constructor(char *name);