#include <stdio.h>
#include <string.h>

// Model: 负责数据处理
typedef struct {
    char name[50];
    int num;
} Model;

void model_init(Model* model) {
    strcpy(model->name, "MVP");
    model->num = 1;
}

void model_update(Model* model, int value) {
    model->num += value;
}

void model_change(Model* model, const char* name) {
    strcpy(model->name, name);
}

// View: 负责显示数据并触发事件
typedef struct {
    void (*render)(char* name, int num);
} View;

void view_render(char* name, int num) {
    printf("<b>%s</b><em>%d</em>\n", name, num);
}

// Presenter: 负责协调 View 和 Model
typedef struct {
    View* view;
    Model* model;
} Presenter;

void presenter_init(Presenter* presenter) {
    presenter->view->render(presenter->model->name, presenter->model->num);
}

void presenter_add(Presenter* presenter, int value) {
    model_update(presenter->model, value);
    presenter->view->render(presenter->model->name, presenter->model->num);
}

void presenter_change(Presenter* presenter, const char* name) {
    model_change(presenter->model, name);
    presenter->view->render(presenter->model->name, presenter->model->num);
}

int main() {
    Model model;
    model_init(&model);

    View view = { view_render };

    Presenter presenter = { &view, &model };

    presenter_init(&presenter);
    presenter_add(&presenter, 1);
    presenter_change(&presenter, "Click to add");
    return 0;
}
