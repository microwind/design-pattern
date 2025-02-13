#include <stdio.h>
#include <string.h>

/*
MVC 模式
- Model：负责业务逻辑和数据处理，直接与数据库或数据源交互。
- View：负责渲染用户界面，显示数据给用户。View可与Model绑定。
- Controller：作为用户输入的中介，接收用户的输入并更新 Model 或 View。
*/

// Model (数据模型)
typedef struct
{
    char name[20];
    int num;
} Model;

void init_model(Model *model)
{
    strcpy(model->name, "MVC Basic");
    model->num = 1;
}

const char *get_name(Model *model)
{
    return model->name;
}

void set_num(Model *model, int num)
{
    model->num = num;
}

int get_num(Model *model)
{
    return model->num;
}

void increment_num(Model *model, int value)
{
    model->num += value;
}

void set_name(Model *model, const char *name)
{
    strcpy(model->name, name);
}

// View (视图层)
typedef struct
{
    Model *model;
} View;

void init_view(View *view, Model *model)
{
    view->model = model;
}

void update_view(View *view)
{
    printf("<div><b>%s</b><em>%d</em></div>\n", get_name(view->model), get_num(view->model));
}

// Controller (控制器)
typedef struct
{
    Model *model;
    View *view;
} Controller;

void init_controller(Controller *controller, Model *model, View *view)
{
    controller->model = model;
    controller->view = view;
}

void on_button_click(Controller *controller)
{
    set_name(controller->model, "onButtonClick");
    increment_num(controller->model, 1);
    update_view(controller->view);
}

void on_mouse_out(Controller *controller)
{
    set_name(controller->model, "onMouseOut");
    set_num(controller->model, 0);
    update_view(controller->view);
}

// Test
int main()
{
    Model model;
    init_model(&model);

    View view;
    // view可以关联model
    init_view(&view, &model);

    Controller controller;
    init_controller(&controller, &model, &view);

    printf("Test 1: Button Click\n");
    on_button_click(&controller);

    printf("Test 2: Mouse Out\n");
    on_mouse_out(&controller);

    return 0;
}

/*
jarry@MacBook-Pro mvc % gcc mvc.c
jarry@MacBook-Pro mvc % ./a.out
Test 1: Button Click
<div><b>onButtonClick</b><em>2</em></div>
Test 2: Mouse Out
<div><b>onMouseOut</b><em>0</em></div>
*/