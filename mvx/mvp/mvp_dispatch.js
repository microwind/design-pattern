  /* 5. MVP+Dispatch: 轻量级的MVP，与最基本MVC也类似，将View与Model分离，通过Presenter注册Model行为，但不增加代理函数，直接将View与Model绑定 */
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
      constructor($el, tpl) {
        this.$el = $el
        this.tpl = tpl
        this.onAdd = new Observer(this)
        this.onChange = new Observer(this)
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
        this.data = { name: 'MVP+Dispatch', num: 1 }
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
        this.view.$el.addEventListener('click', evt => this.view.onAdd.notify(1))
        this.view.$el.addEventListener('mouseout', evt => this.view.onChange.notify('Click to add'))
        this.view.onAdd.register(value => {
          this.model.data.name = 'Click to add:Event dispatch.'
          this.model.update(value)
        })
        this.view.onChange.register(name => this.model.change(name))
        this.model.onUpdate.register(value => this.view.render(this.model.data))
        this.model.onChange.register(name => this.view.render(this.model.data))
        this.view.render(this.model.data)
      }
    }
    const model = new Model()
    const view = new View(doc.querySelector('#mvp-dispatch-view'))
    const controller = new Controller(view, model)
    controller.init()
  })(window, document)