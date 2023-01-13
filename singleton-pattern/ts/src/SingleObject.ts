export const SingleObject = (function () {
  let instance: any = undefined

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
