!(function(win, doc) {
  // View
  class View {
    constructor($el, tpl) {
      this.$el = $el;
      this.tpl = tpl;
    }

    // 渲染数据
    render(data) {
      this.$el.innerHTML = this.compile(data);
    }

    // 编译模板
    compile(data) {
      return this.tpl || `<div><b>${data.name}</b><em>${data.num}</em></div>`;
    }

    // 设置按钮点击事件监听
    setClickListener(callback) {
      this.$el.addEventListener('click', callback);
    }

    // 设置鼠标移出事件监听
    setMouseOutListener(callback) {
      this.$el.addEventListener('mouseout', callback);
    }
  }

  // Model
  class Model {
    constructor() {
      this.data = { name: 'MVP', num: 1 };
    }

    // 更新数据
    update(value) {
      return new Promise((resolve, reject) => {
        this.data.num += value;
        resolve(this.data);
      });
    }

    // 修改名称
    change(name) {
      this.data.name = name;
    }

    // 获取当前数据
    getData() {
      return this.data;
    }
  }

  // Presenter
  class Presenter {
    constructor(view, model) {
      this.view = view;
      this.model = model;
    }

    // 初始化，绑定事件并渲染初始数据
    init() {
      this.view.setClickListener(() => this.add(1)); // 绑定点击事件
      this.view.setMouseOutListener(() => this.change('Click to add')); // 绑定鼠标移出事件
      this.render();
    }

    // 渲染视图
    render() {
      const data = this.model.getData();
      this.view.render(data);
    }

    // 增加数据
    add(value) {
      this.model.update(value).then(() => {
        this.render(); // 更新视图
      });
    }

    // 修改名称
    change(name) {
      this.model.change(name);
      this.render(); // 更新视图
    }
  }

  // 初始化
  const view = new View(doc.querySelector('#mvp-view'));
  const model = new Model();
  const presenter = new Presenter(view, model);
  presenter.init();
})(window || this, document);
