  // 6. 前端MVVM模式，通过观察者模式将数据与视图进行双向绑定，然后由数据驱动更改
  !(function(win, doc) {
    class Agent {
      constructor(target, watch) {
        const handle = {
          set(obj, prop, value) {
           if (obj[prop] !== value && obj.hasOwnProperty(prop)) {
             obj[prop] = value
             watch && watch(obj, prop, value)
           }
           return Reflect.set(obj, prop, value)
          },
          get(obj, prop) {
            if (typeof obj[prop] === 'object' && obj[prop] !== null) {
              return new Proxy(obj[prop], handle)
            } else {
              return Reflect.get(obj, prop)
            }
          }
        }
        return new Proxy(target, handle)
      }
    }
    // View
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
    }
    // Model
    class Model {
      constructor() {
        this.data = { name: 'MVVM', num: 1 }
      }
      update(data) {
        const fn = (res) => {
          data.num += 1
          return data
        }
        return fetch('./').then(fn).catch(fn)
      }
    }
    // Controller
    class ViewModel {
      constructor({ $el, view, model }) {
        this.view = view
        this.data = new Agent(model.data, (obj, prop, value) => {
          this.view.render(this.data)
        })
        this.model = model
        this.init()
      }
      init() {
        console.log('render:', this.data)
        this.view.$el.addEventListener('click', (evt) => this.add(evt))
        this.view.$el.addEventListener('mouseout', (evt) => this.change(evt))
        this.view.render(this.data)
      }
      change(evt) {
        this.data.name = 'Click to add'
      }
      add(evt) {
        this.data.name = 'Click to add:Watch data.'
        this.model.update(this.data)
      }
    }
    const viewModel = new ViewModel({
      view: new View(doc.querySelector('#mvvm-view')), 
      model: new Model()
    })
  })(window, document)