  /* 2. MVC:前端MVC，与后端MVC并不太一样，View与Model是绑定的。在View中监测Model的行为通知来更新视图，Model更新则通过Controller注册转发 */
 !(function(win, doc) {
    class Observer {
      constructor() {
        this.observers = []
      }
      register(callback) {
        this.observers.push(callback)
      }
      notify(args) {
        for (let i = 0, l = this.observers.length; i < l; i++) {
          this.observers[i](args)
        }
      }
    }
    // View
    class View {
      constructor($el, model, tpl) {
        this.$el = $el
        this.model = model
        this.tpl = tpl
        this.onAdd = new Observer(this)
        this.onChange = new Observer(this)
        this.model.onUpdate.register(value => this.render())
        this.model.onChange.register(name => this.render())
        this.$el.addEventListener('click', evt => this.onAdd.notify(1))
        this.$el.addEventListener('mouseout', evt => this.onChange.notify('Click to add'))
      }
      render() {
        this.$el.innerHTML = this.compile(this.model.data)
      }
      compile(data) {
        return this.tpl || `<div><b>${data.name}</b>
         <em>${data.num}</em></div>`
      }
    }
    // Model
    class Model {
      constructor() {
        this.data = { name: 'MVC', num: 1 }
        this.onUpdate = new Observer(this)
        this.onChange = new Observer(this)
      }
      update(value) {
        const fn = (res) => {
          this.data.num += value
          this.onUpdate.notify(value)
        }
        fetch('./').then(fn).catch(fn)
      }
      change(name) {
        this.data.name = name
        this.onChange.notify(name)
      }
    }
    // Controller
    class Controller {
      constructor(view, model) {
        this.view = view
        this.model = model
      }
      init() {
        this.view.onAdd.register(value => {
          this.model.data.name = 'Click to add:Event dispatch.'
          this.model.update(value)
        })
        this.view.onChange.register(name => this.model.change(name))
        this.view.render()
      }
    }
    const model = new Model()
    const view = new View(doc.querySelector('#mvc-view'), model)
    const controller = new Controller(view, model)
    controller.init()
  })(window, document)