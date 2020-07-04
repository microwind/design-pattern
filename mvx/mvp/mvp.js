 /* 3. MVP:Contorller升级为Presenter，将View与Model分离。通过Presenter来绑定View事件和代理双方行为 */
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
        this.data = { name: 'MVP', num: 1 }
      }
      update(value) {
        const fn = (res) => {
          this.data.num += value
          return res
        }
        return fetch('./').then(fn).catch(fn)
      }
      change(name) {
        this.data.name = name
      }
    }
    // Presenter
    class Presenter {
      constructor(view, model) {
        this.view = view
        this.model = model
        view.$el.addEventListener('click', evt => this.add(1))
        view.$el.addEventListener('mouseout', evt => this.change('Click to add'))
      }
      init() {
        this.render(this.model.data)
      }
      render(data) {
        this.view.render(data)
      }
      add(value) {
        this.model.data.name = 'Click to add:Event proxy.'
        this.model.update(value).then(res => {
          this.render(this.model.data)
        })
      }
      change(name) {
        this.model.change(name)
        this.render(this.model.data)
      }
    }
    const view = new View(doc.querySelector('#mvp-view'))
    const presenter = new Presenter(view, new Model())
    presenter.init()
  })(window, document)