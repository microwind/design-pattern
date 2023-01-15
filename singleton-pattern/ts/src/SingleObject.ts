export const SingleObject = (function () {
  let instance: any = undefined

  // 对象创建方式，如果已经实例化则直接返回对象，类似一个普通Object
  function createInstance(alias: string) {
    if (instance) {
      return instance
    }
    instance = Object.create(null)
    instance.alias = alias
    instance.run = function () {
      console.log('SingleObject::()', instance.alias)
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
