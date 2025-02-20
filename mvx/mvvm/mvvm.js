/*
MVVM（Model-View-ViewModel）模式 是一种基于数据双向绑定的分层UI架构。

MVVM的三大组件
1. Model（模型）
  职责：Model 负责应用程序的核心数据和业务逻辑。
  作用：Model 定义了数据结构和业务规则，不关心 UI 层的变动。它只关心数据处理和状态管理。
2. View（视图）
  职责：View 是界面部分，负责展示用户信息并接收用户输入。
  作用：View 通过与 ViewModel 绑定来显示数据。它本身并不包含任何业务逻辑，只负责界面的渲染。它通过数据绑定将数据从 ViewModel 并更新到界面。
3. ViewModel（视图模型）
  职责：ViewModel 是 View 和 Model 之间的中介，负责将 Model 中的数据转换成适合 View 显示的格式。它包含了 View 的表现逻辑（即界面操作相关的逻辑），同时不包含任何关于如何渲染 UI 的代码。
  作用：ViewModel 通过数据绑定向 View 提供数据，并从 View 接收用户输入。它处理UI交互请求，并调用 Model 来获取或修改数据，再通知 View 更新视图。
*/

// 前端MVVM模式，通过观察者模式将数据与视图进行双向绑定，然后由数据驱动更改
!(function (global, doc) {
  // 代理类Agent，采用深度代理
  class Agent {
    constructor(target, watch) {
      const handle = {
        set(obj, prop, value) {
          if (obj[prop] !== value && obj.hasOwnProperty(prop)) {
            obj[prop] = value
            // 数据变化时触发回调
            watch && watch(obj, prop, value)
          }
          return Reflect.set(obj, prop, value)
        },
        get(obj, prop) {
          if (typeof obj[prop] === 'object' && obj[prop] !== null) {
            // 递归代理嵌套对象
            return new Proxy(obj[prop], handle)
          } else {
            return Reflect.get(obj, prop)
          }
        }
      }
      return new Proxy(target, handle)
    }
  }

  // View - 负责渲染页面
  class View {
    constructor($el, tpl) {
      this.$el = $el
    }
    compile(data) {
      return this.tpl || `
         <div><b>${data.name}</b>
         <em>${data.num}</em></div>`
    }
    render(data) {
      this.$el.innerHTML = this.compile(data)
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

  // Model - 负责数据和业务逻辑
  class Model {
    constructor() {
      this.data = {
        name: 'MVVM',
        num: 1
      }
    }

    // 更新数据，不关心视图层，由ViewModel自动监听
    update(data) {
      return new Promise((resolve) => {
        const name = data.name
        data.name = 'loading...'
        setTimeout(() => {
          data.num += 1 // 模拟数据更新
          data.name = name
          resolve(data)
        }, 100)
      })
    }
  }

  // ViewModel - 管理视图与数据绑定
  class ViewModel {
    constructor({
      view,
      model
    }) {
      this.view = view
      this.model = model

      // 使用代理监听数据变化，关联model与view
      this.data = new Agent(model.data, (obj, prop, value) => {
        // 数据变化时可以获得数据以及具体变化的属性和值
        this.view.render(this.data) // 数据变化时更新视图
      })
      // init可以放在构造器或外层
      this.init()
    }

    // 初始化事件监听
    init() {
      // this.view.$el.addEventListener('click', (evt) => this.onButtonClick(evt))
      // this.view.$el.addEventListener('mouseout', (evt) => this.onMouseOut(evt))
      // 给view设置事件回调
      this.view.setClickListener(this.onButtonClick.bind(this));
      this.view.setMouseOutListener(this.onMouseOut.bind(this));
      this.view.render(this.data)
    }

    // 点击事件处理
    onButtonClick(evt) {
      this.data.name = 'Click to add: Watch data.'
      this.model.update(this.data).then(() => {
        console.log('Data updated:', this.data)
      })
    }

    // 鼠标移出事件处理
    onMouseOut(evt) {
      this.data.name = 'Click to add'
    }
  }

  // 输出到全局
  global.$mvvm = {
    ViewModel: ViewModel,
    View: View,
    Model: Model
  }
  // 执行测试
  // global.onload = () => {
  //   const viewModel = new ViewModel({
  //     view: new View(doc.querySelector('#mvvm-view')),
  //     model: new Model()
  //   })
  // }
})(this || window, document)