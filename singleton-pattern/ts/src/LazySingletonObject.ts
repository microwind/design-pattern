export const LazySingletonObject = (function () {
  let instance: any = undefined

  // 创建对象，不是class，无需实例化，直接返回对象
  function createInstance(alias: string) {
    if (instance) {
      return instance
    }
    instance = Object.create(null)
    instance.alias = alias
    instance.run = function () {
      console.log('LazySingletonObject::()', instance.alias)
    }
    return instance
  }

  return {
    getInstance: function (alias: string) {
      if (!instance) {
        instance = createInstance(alias)
      }
      return instance
    }
  }
})()
