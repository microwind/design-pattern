 /* 1. MVC Basic: 最基本版MVC，与后端MVC类似, M与C分离。事件绑定和数据更新均通过Controller来设置和转发。 */
  !(function(win, doc) {
    // View
    class View {
      constructor($el, tpl) {
        this.$el = $el
        this.tpl = tpl
      }
      render(data) {
        this.$el.innerHTML = this.compile(data)
      }
      compile(data) {
        return this.tpl || `<div><b>${data.name}</b>
         <em>${data.num}</em></div>`
      }
    }
    // Model
    class Model {
      constructor() {
        this.data = { name: 'MVC Basic', num: 1 }
      }
      update(value, cb) {
        const fn = (res) => {
          this.data.num += value
          cb(this.data)
        }
        fetch('./').then(fn).catch(fn)
      }
      change(name, cb) {
        this.data.name = name
        cb(this.data)
      }
    }
    // Controller
    class Controller {
      constructor(view, model) {
        this.view = view
        this.model = model
      }
      init() {
        this.view.$el.addEventListener('click', evt => {
          this.model.data.name = 'Click to add:Event dispatch.'
          this.model.update(1, data => this.view.render(data))
        })
        this.view.$el.addEventListener('mouseout', evt => {
          this.model.change('Click to add', data => this.view.render(data))
        })
        this.view.render(this.model.data)
      }
    }
    const model = new Model()
    const view = new View(doc.querySelector('#mvc-basic-view'))
    const controller = new Controller(view, model)
    controller.init()
  })(window, document)