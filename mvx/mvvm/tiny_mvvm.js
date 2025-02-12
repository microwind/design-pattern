(function (win, doc) {
  /** 观察者类（订阅-发布模式） */
  class Observer {
    constructor() {
      this.observers = [] // 订阅者列表
    }
    /** 注册订阅者 */
    register(callback) {
      this.observers.push(callback)
    }
    /** 通知所有订阅者 */
    notify(...args) {
      this.observers.forEach(callback => callback(...args))
    }
  }

  /** 观察数据变动的 Watcher */
  class Watcher {
    constructor(vm, cb) {
      this.vm = vm
      this.cb = cb
      return this.run.bind(this)
    }
    run(obj, prop, value) {
      console.log('watch:', obj, prop, value)
      if (this.vm.watch[prop]) {
        this.vm.watch[prop].call(this.vm.data, value, this.vm)
      }
      this.cb.call(this.vm, obj, prop, value, this)
    }
  }

  /** 数据代理（使用 Proxy 监听变化） */
  class Agent {
    constructor(target, observer, vm) {
      const proxyCache = new WeakMap()
      const handle = {
        set(obj, prop, value) {
          if (obj[prop] !== value && obj.hasOwnProperty(prop)) {
            obj[prop] = value
            observer.notify(obj, prop, value)

            // 计算属性自动更新
            Object.keys(vm.computed).forEach(attr => {
              obj[attr] = vm.computed[attr].call(obj, vm)
            })
          }
          return Reflect.set(obj, prop, value)
        },
        get(obj, prop) {
          if (typeof obj[prop] === 'object' && obj[prop] !== null) {
            if (!proxyCache.has(obj[prop])) {
              proxyCache.set(obj[prop], new Proxy(obj[prop], handle))
            }
            return proxyCache.get(obj[prop])
          }
          return Reflect.get(obj, prop)
        }
      }
      return new Proxy(target, handle)
    }
  }

  /** 模板解析 */
  function template(strings, ...keys) {
    return function (...values) {
      const dict = values[values.length - 1] || {}
      return strings.reduce((result, str, i) => result + (dict[keys[i - 1]] || '') + str)
    }
  }

  /** 视图层处理 */
  class View {
    constructor($el, tpl) {
      this.$el = $el
      this.tpl = tpl
      this.events = []
    }
    compile(data) {
      const content = this.tpl(data)
      const reg = /e-([a-z]+)="([a-zA-Z0-9_]+)"/igm
      const matches = [...content.matchAll(reg)]
      this.events = matches.map(match => [match[1], match[2]])
      return content
    }
    render(data) {
      if (this.$el.innerHTML) {
        this.$el.innerHTML = this.compile(data)
      } else {
        console.error('render failed:', this.$el, data)
      }
    }
  }

  /** MVVM 入口类 */
  class TinyMVVM {
    constructor({
      $el,
      tpl,
      data,
      methods = {},
      watch = {},
      computed = {}
    }) {
      this.view = new View($el, tpl)
      this.observer = new Observer()
      this.watcher = new Watcher(this, () => this.render())
      this.observer.register(this.watcher)
      this.data = new Agent(data(), this.observer, this)
      this.methods = methods
      this.watch = watch
      this.computed = computed
      this.render()
      this.mount()
    }
    render() {
      const data = {
        ...this.data
      }
      Object.keys(this.computed).forEach(attr => {
        data[attr] = this.computed[attr].call(this.data, this)
      })
      this.view.render(data)
    }
    mount() {
      this.view.$el.addEventListener('click', evt => {
        let target = evt.target
        while (target && target !== this.view.$el) {
          const methodName = target.getAttribute('e-click')
          if (methodName && this.methods[methodName]) {
            this.methods[methodName].call(this, evt)
            break
          }
          target = target.parentNode
        }
      })
    }
  }

  win.onload = () => {
    /** 初始化 MVVM 实例 */
    new TinyMVVM({
      $el: doc.querySelector('#mvvm-watch-view'),
      tpl: template `<div e-click="add"><b>${'name'}</b> <em style="color:red">${'num'}</em> | ${'computedProp'}</div>`,
      data() {
        return {
          name: 'Tiny MVVM, click me',
          num: 1
        }
      },
      methods: {
        async fetch(value) {
          try {
            // await fetch('./')
            this.data.num += value
          } catch (error) {
            console.error('Fetch error:', error)
          }
        },
        add() {
          this.data.name = 'Updated Name'
          this.methods.fetch.call(this, 1)
        }
      },
      computed: {
        computedProp() {
          return this.name + ' computed.'
        }
      },
      watch: {
        num(value) {
          this.name = 'Num changed!'
        }
      }
    })
  }
})(window, document)