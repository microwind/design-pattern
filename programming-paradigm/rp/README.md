# 响应式编程概述

响应式编程(Reactive Programming, RP)，是一种面向数据流和变化传播的编程范式，它强调通过异步和非阻塞的方式处理数据流。它使程序能够以声明性的方式描述动态行为和交互，并自动处理变化带来的复杂性。

## JS代码示例

```js
let data = 0

// 订阅函数
function subscribe(callback) {
  callback(data)
}

// 修改数据并通知订阅者
function updateData(newValue) {
  data = newValue

  // 触发响应函数，数据自动更新
  subscribe((value) => {
    value += 10
    console.log('Data updated:', value)
  })
}

// 进行初始订阅
subscribe((value) => {
  console.log('Initial data:', value)
})

// 模拟数据更新
updateData(10)
updateData(20)
```

## Java代码示例
```java

```