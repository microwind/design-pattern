 /* 4. MVP+Observer: 增加Observer，View与Model分离。事件由View绑定，Presenter增加对应函数，代理View与Model全部行为 */
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
        this.$el.addEventListener('click', evt => this.onAdd.notify(1) )
        this.$el.addEventListener('mouseout', evt => this.onChange.notify('Click to add'))
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
        this.data = { name: 'MVP+Observer', num: 1 }
        this.onUpdate = new Observer(this)
        this.onChange = new Observer(this)
      }
      update(value) {
        const fn = (res) => {
          this.data.num += value
          this.onUpdate.notify(value)
          return res
        }
        return fetch('./').then(fn).catch(fn)
      }
      change(name) {
        this.data.name = name
        this.onChange.notify(name)
      }
    }
    // Presenter
    class Presenter {
      constructor(view, model) {
        this.view = view
        this.model = model
        this.view.onAdd.register(value => this.add(value))
        this.view.onChange.register(name => this.change(name))
        this.model.onUpdate.register(res => this.render())
        this.model.onChange.register(res => this.render())
      }
      init() {
        this.render()
      }
      render() {
        this.view.render(this.model.data)
      }
      add(value) {
        this.model.data.name = 'Click to add:Event proxy.'
        this.model.update(value)
      }
      change(name) {
        this.model.change(name)
      }
    }
    const $el = doc.querySelector('#mvp-observer-view')
    const presenter = new Presenter(new View($el), new Model())
    presenter.init()
  })(window, document)