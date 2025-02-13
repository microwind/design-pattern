/*
MVC 模式
- Model：负责业务逻辑和数据处理，直接与数据库或数据源交互。
- View：负责渲染用户界面，显示数据给用户。View可与Model绑定。
- Controller：作为用户输入的中介，接收用户的输入并更新 Model 或 View。
*/

// Model (数据模型)
class Model {
    constructor() {
        this.name = "MVC Basic";
        this.num = 1;
    }

    getName() {
        return this.name;
    }

    setNum(num) {
        this.num = num;
    }

    getNum() {
        return this.num;
    }

    incrementNum(value) {
        this.num += value;
    }

    setName(name) {
        this.name = name;
    }
}

// View (视图层)
class View {
    // 关联 Model
    constructor(model) {
        this.model = model;
    }

    // 更新视图显示，直接从 Model 获取数据
    updateView() {
        console.log(`<div><b>${this.model.getName()}</b><em>${this.model.getNum()}</em></div>`);
    }
}

// Controller (控制器)
class Controller {
    constructor(model, view) {
        this.model = model;
        this.view = view;
    }

    onButtonClick() {
        this.model.setName("onButtonClick");
        this.model.incrementNum(1);
        this.updateView();
    }

    onMouseOut() {
        this.model.setName("onMouseOut");
        this.model.setNum(0);
        this.updateView();
    }

    // 由 Controller 调用更新 View
    updateView() {
        this.view.updateView();
    }
}

// Test
const model = new Model();
// View 可以持有 Model，或在更新视图时传递Model
const view = new View(model);
const controller = new Controller(model, view);

console.log("Test 1: Button Click");
controller.onButtonClick();

console.log("Test 2: Mouse Out");
controller.onMouseOut();

/*
jarry@MacBook-Pro mvc % node mvc.js
Test 1: Button Click
<div><b>onButtonClick</b><em>2</em></div>
Test 2: Mouse Out
<div><b>onMouseOut</b><em>0</em></div>
*/