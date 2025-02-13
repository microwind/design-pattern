/*
MVP 模式
- Model：负责业务逻辑和数据处理，直接与数据库或数据源交互。
- View：负责渲染用户界面，显示数据给用户。View不直接绑定Model，而通过Presenter获取数据。
- Presenter：作为中介者，接收用户输入并更新 Model 或 View，处理业务逻辑。
*/

// Model (数据模型)
class Model {
  constructor() {
    this.name = "MVP Basic";
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
  // View 只负责显示数据，并提供更新界面的接口
  updateView(name, num) {
    console.log(`<div><b>${name}</b><em>${num}</em></div>`);
  }
}

// Presenter (中介者)
class Presenter {
  constructor(model, view) {
    this.model = model;
    this.view = view;
  }

  // 按钮点击时通过 Presenter 更新 Model 数据并刷新视图
  onButtonClick() {
    this.model.setName("onButtonClick");
    this.model.incrementNum(1);
    this.updateView();
  }

  // 鼠标移出时通过 Presenter 更新 Model 数据并刷新视图
  onMouseOut() {
    this.model.setName("onMouseOut");
    this.model.setNum(0);
    this.updateView();
  }

  // 由 Presenter 调用更新 View，传递数据，而不是Model
  updateView() {
    this.view.updateView(this.model.getName(), this.model.getNum());
  }
}

// Test
const model = new Model();
// View 不直接持有 Model，也不传递Model，view针对数据更新
const view = new View();
const presenter = new Presenter(model, view);

console.log("Test 1: Button Click");
presenter.onButtonClick();

console.log("Test 2: Mouse Out");
presenter.onMouseOut();

/*
jarry@MacBook-Pro mvp % node mvp.js 
Test 1: Button Click
<div><b>onButtonClick</b><em>2</em></div>
Test 2: Mouse Out
<div><b>onMouseOut</b><em>0</em></div>
*/