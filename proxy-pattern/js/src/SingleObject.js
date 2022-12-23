export const SingleObject = (function () {
  let instance

  function createInstance(alias) {
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
    getInstance: function (alias) {
      if (!instance) {
        instance = createInstance(alias)
      }
      return instance
    },
  }
})()
