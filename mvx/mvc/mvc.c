#include <stdio.h>
#include <string.h>

// Model: 负责数据管理
typedef struct {
    char name[50];
    int num;
} Model;

void init_model(Model* model) {
    strcpy(model->name, "MVC Basic");
    model->num = 1;
}

void increment_num(Model* model, int value) {
    model->num += value;
}

void set_name(Model* model, const char* name) {
    strcpy(model->name, name);
}

// View: 负责显示数据
void display_view(const char* name, int num) {
    printf("<div><b>%s</b><em>%d</em></div>\n", name, num);
}

// Controller: 负责处理用户输入和业务逻辑
typedef struct {
    Model* model;
} Controller;

void init_controller(Controller* controller, Model* model) {
    controller->model = model;
}

void on_button_click(Controller* controller) {
    increment_num(controller->model, 1);
    display_view(controller->model->name, controller->model->num);
}

void on_mouse_out(Controller* controller) {
    set_name(controller->model, "Click to add");
    display_view(controller->model->name, controller->model->num);
}

// Test
int main() {
    Model model;
    init_model(&model);
    
    Controller controller;
    init_controller(&controller, &model);

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
<div><b>MVC Basic</b><em>2</em></div>
Test 2: Mouse Out
<div><b>Click to add</b><em>2</em></div>
*/