#include <stdio.h>
#include <string.h>

/*
MVP 模式
- Model：负责业务逻辑和数据处理，直接与数据库或数据源交互。
- View：负责渲染用户界面，显示数据给用户。View 不直接绑定 Model，而通过 Presenter 获取数据。
- Presenter：作为中介者，接收用户输入并更新 Model 或 View，处理业务逻辑。
*/

// Model (数据模型)
typedef struct {
    char name[50];
    int num;
} Model;

void Model_init(Model *model) {
    strcpy(model->name, "MVP Basic");
    model->num = 1;
}

const char *Model_getName(Model *model) {
    return model->name;
}

void Model_setNum(Model *model, int num) {
    model->num = num;
}

int Model_getNum(Model *model) {
    return model->num;
}

void Model_incrementNum(Model *model, int value) {
    model->num += value;
}

void Model_setName(Model *model, const char *name) {
    strcpy(model->name, name);
}

// View (视图层)
typedef struct {
    // View 只负责显示数据，并提供更新界面的接口
    void (*updateView)(const char *name, int num);
} View;

void View_updateView(const char *name, int num) {
    printf("<div><b>%s</b><em>%d</em></div>\n", name, num);
}

// Presenter (中介者)
typedef struct {
    Model *model;
    View *view;
} Presenter;

void Presenter_init(Presenter *presenter, Model *model, View *view) {
    presenter->model = model;
    presenter->view = view;
}

// 按钮点击时通过 Presenter 更新 Model 数据并刷新视图
void Presenter_onButtonClick(Presenter *presenter) {
    Model_setName(presenter->model, "onButtonClick");
    Model_incrementNum(presenter->model, 1);
    presenter->view->updateView(Model_getName(presenter->model), Model_getNum(presenter->model));
}

// 鼠标移出时通过 Presenter 更新 Model 数据并刷新视图
void Presenter_onMouseOut(Presenter *presenter) {
    Model_setName(presenter->model, "onMouseOut");
    Model_setNum(presenter->model, 0);
    presenter->view->updateView(Model_getName(presenter->model), Model_getNum(presenter->model));
}

// Test
int main() {
    Model model;
    Model_init(&model);

    View view;
    view.updateView = View_updateView;

    Presenter presenter;
    Presenter_init(&presenter, &model, &view);

    printf("Test 1: Button Click\n");
    Presenter_onButtonClick(&presenter);

    printf("Test 2: Mouse Out\n");
    Presenter_onMouseOut(&presenter);

    return 0;
}

/*
jarry@MacBook-Pro mvp % gcc mvp.c
jarry@MacBook-Pro mvp % ./a.out 
Test 1: Button Click
<div><b>onButtonClick</b><em>2</em></div>
Test 2: Mouse Out
<div><b>onMouseOut</b><em>0</em></div>
*/