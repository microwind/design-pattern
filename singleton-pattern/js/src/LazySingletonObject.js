export const LazySingletonObject = (function () {
  let instance
  // 创建对象，不是class，无需实例化，直接返回对象
  function createInstance(alias) {
    if (instance) {
      return instance
    }
    instance = Object.create(null)
    instance.alias = alias
    instance.run = function () {
      console.log('LazySingletonObject::run()', instance.alias)
    }
    return instance
  }

  return {
    // 通过函数来获得实例，延迟初始化
    // 也可以直接执行函数，则立即初始化
    getInstance: function (alias) {
      if (!instance) {
        instance = createInstance(alias)
      }
      return instance
    }
  }
})()
