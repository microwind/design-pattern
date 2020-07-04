 // 7. 前端MVVM最简版框架模式，增加事件标记提取绑定和Watch行为变化，通过观察者模式将数据与视图进行双向绑定，然后由数据驱动更改
  !(function(win, doc) {
    class Observer {
      constructor(vm) {
        this.vm = vm
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
    class Watcher {
      constructor(vm, cb) {
        this.vm = vm
        this.cb = cb
        return this.run.bind(this)
      }
      run(obj, prop, value) {
        console.log('watch:', arguments)
        if (this.vm.watch[prop]) {
          (this.vm.watch[prop]).call(this.vm.data, value, this.vm)
        }
        this.cb.call(this.vm, obj, prop, value, this)
      }
    }
    class Agent {
      constructor(target, observer) {
        const handle = {
          set(obj, prop, value) {
           if (obj[prop] !== value && obj.hasOwnProperty(prop)) {
             obj[prop] = value
             observer && observer.notify(obj, prop, value)
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
    function template(strings, ...keys) {
      return function(...values) {
        const dict = values[values.length - 1] || {}
        const result = [strings[0]]
        keys.forEach((key, i) => {
          let value = dict[key]
          result.push(value, strings[i + 1])
        })
        return result.join('')
      }
    }

    // View
    class View {
      constructor($el, tpl) {
        this.$el = $el
        this.tpl = tpl
        this.events = []
      }
      compile(data) {
        const content = this.tpl(data)
        let reg = new RegExp('e-([a-z]+)\=\"([a-z0-9]+)' + '\"', 'igm')
        const result = content.match(reg) || []
        result.forEach((item) => {
          const [evt, fn] = item.split('=')
          this.events.push([evt.substr(2), fn.substr(0, fn.length - 1).substr(1)])
        })
        return content
      }
      render(data) {
        this.$el.innerHTML = this.compile(data)
      }
    }
    const Model = { name: 'Tiny MVVM Framework', num: 1 }
    // ViewModel
    class TinyMVVM {
      constructor({ $el, tpl, data, methods = {}, watch = {}, computed = {} }) {
        this.view = new View($el, tpl)
        this.observer = new Observer(this)
        this.watcher = new Watcher(this, (obj, prop, value) => {
          this.render()
        })
        this.observer.register(this.watcher)
        this.data = new Agent(data(), this.observer)
        this.methods = methods
        this.watch = watch
        this.computed = computed
        this.init()
      }
      render() {
        const data = Object.assign({}, this.data)
        for (let attr in this.computed) {
          data[attr] = (this.computed[attr]).call(this.data, this)
        }
        this.view.render(data)
      }
      init() {
        this.render()
        this.mount()
      }
      mount() {
        this.view.events.forEach((item) => {
          this.view.$el.addEventListener(item[0], (evt) => (this.methods[item[1]].bind(this))(evt))
        })
      }
    }
    new TinyMVVM({
      $el: doc.querySelector('#mvvm-watch-view'),
      tpl: template`
         <div e-click="add" e-mouseout="change"><b>${'name'}</b>
         <em>${'num'}</em> | ${'computedProp'}</div>`,
      data() {
        return Model
      },
      methods: {
        fetch(value) {
          const fn = (res) => {
            this.data.num += value
            return this.data
          }
          return fetch('./').then(fn).catch(fn)
        },
        change(evt) {
          this.data.name = 'Click to add'
        },
        add(evt) {
          this.data.name = 'Click to add:Watch data.'
          this.methods.fetch.bind(this)(1)
        }
      },
      computed: {
        computedProp: function(vm) {
          return this.name + ' computed.'
        }
      },
      watch: {
        num(value, vm) {
          this.name = 'Click to add:Watch data.'
        }
      }
    })
  })(window, document)