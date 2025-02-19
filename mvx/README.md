# MVX 分层架构设计概述

MVX 是一类用于软件架构设计的模式，包括 MVC（Model-View-Controller）、MVP（Model-View-Presenter）、MVVM（Model-View-ViewModel）等。这些模式主要用于分离关注点，使代码更易维护和扩展。

## 不同 MVX 的结构图形示例

### MVC（Model-View-Controller）
```
                   User Input  
                       |  
                       v
+---------+       +-----------+      +-----------+
|  View   |  <--- | Controller| ---> |   Model   |
+---------+       +-----------+      +-----------+
    ^                                      v
    |            Model数据映射到View         |
    ****--------------------------------****

1. 如果是前端MVC，则由View的事件触发。
https://developer.mozilla.org/en-US/docs/Glossary/MVC

2. 如果是后端MVC，则由Controller作为入口。
https://spring.io/blog/2011/01/04/green-beans-getting-started-with-spring-mvc

```
**特点**：
- Model 负责数据处理和业务逻辑。一般还有层Service，Model负责数据建模，Service则负责处理业务流程。
- View 负责 UI 展示，但不会直接与 Model 交互，仅针对 Model 进行渲染。
- Controller 负责接收用户输入，更新 Model，并通知 View 渲染。
- View 关联到某个 Model，可以直接绑定 Model 或 通过 Controller 来进行绑定。

### MVP（Model-View-Presenter）
```
User Input  
    | 
    v        由主持人代理View和Model交互
+---------+      +-----------+       +-----------+
|  View   | <--> | Presenter | <---> |   Model   |
+---------+      +-----------+       +-----------+

1. MVP 主要用于前端开发，尤其是界面渲染，当一个界面需要针对多个视图数据进行渲染时，采用MVP比MVC更合适。
2. MVP 下 View 与 Model 隔离，View 中没有对应 Model 概念，数据由 Presenter 代为传递。
```
**特点**：
- View 只负责 UI 显示，不包含业务逻辑。
- Presenter 充当中间层，处理业务逻辑，并与 View 交互。
- Model 负责数据建模与核心逻辑处理。
- View 和 Model 不能直接通信，所有交互都必须经过 Presenter。

### MVVM（Model-View-ViewModel）
```
User Input  
    |
    v         将View与Model双向数据绑定
+---------+      +-----------+      +-----------+
|  View   | ---> | ViewModel | <--> |   Model    |
+---------+      +-----------+      +-----------+
                   ^        |
                   |        v
          Data Binding(由Agent监听数据变化)

1. MVVM 从 View 触发，监听事件执行数据更新。
2. 通过代理监听数据变化，自动更新视图。
```
**特点**：
- ViewModel 作为 View 和 Model 的桥梁，封装 UI 处理逻辑。
- View 通过数据绑定与 ViewModel 建立联系，而不是直接在 View 中访问 Model。
- Model 的数据变化会自动更新 View，View 变化也能同步到 Model。

## 各种 MVX 分层架构

| 架构 | 主要作用 | 适用场景 |
|------|---------|---------|
| MVC  | 经典架构模式，适用于各种系统开发 | 适用于前后端分离、Web 开发 |
| MVP  | 适用于解耦 UI 与逻辑的项目 | 适用于桌面应用、前端开发、Android 开发 |
| MVVM | 适用于数据驱动 UI，提升响应性 | 适用于前端框架，如 Vue、React |

## 各种 MVX 的应用场景
- **MVC**：常用于 Web 开发，如 Java Spring MVC、Django、ASP.NET MVC。
- **MVP**：常用于 Android 应用，如使用 Activity 作为 View，Presenter 处理业务逻辑。
- **MVVM**：常用于前端框架，如 Vue.js 和 React（利用 Hooks + 状态管理）。

## MVX 的简单例子（C、Java、JavaScript）

### C 语言实现 MVC
```c
#include <stdio.h>

// Model
typedef struct {
    int data;
} Model;

void updateModel(Model* model, int newData) {
    model->data = newData;
}

// View
void displayData(int data) {
    printf("Data: %d\n", data);
}

// Controller
void handleUserInput(Model* model, int input) {
    updateModel(model, input);
    displayData(model->data);
}

int main() {
    Model model = {0};
    handleUserInput(&model, 10);
    return 0;
}
```

### Java 语言实现 MVP
```java
// Model
class Model {
    private String data;

    public void setData(String data) {
        this.data = data;
    }

    public String getData() {
        return data;
    }
}

// View Interface
interface View {
    void showData(String data);
}

// Presenter
class Presenter {
    private Model model;
    private View view;

    public Presenter(Model model, View view) {
        this.model = model;
        this.view = view;
    }

    public void updateData(String newData) {
        model.setData(newData);
        view.showData(model.getData());
    }
}

// Main
public class Main {
    public static void main(String[] args) {
        Model model = new Model();
        View view = data -> System.out.println("Data: " + data);
        Presenter presenter = new Presenter(model, view);
        presenter.updateData("Hello, MVP!");
    }
}
```

### JavaScript 语言实现 MVVM
```javascript
// Model
class Model {
    constructor() {
        this._data = "";
    }

    set data(newData) {
        this._data = newData;
    }

    get data() {
        return this._data;
    }
}

// ViewModel
class ViewModel {
    constructor(model) {
        this.model = model;
        this.listeners = []; // 用于存储监听器
        this.defineReactive(); // 定义响应式数据
    }

    // 定义响应式数据
    defineReactive() {
        const self = this;
        Object.defineProperty(this.model, "data", {
            get() {
                return self.model._data;
            },
            set(newData) {
                self.model._data = newData;
                self.notifyListeners(); // 通知监听器
            },
        });
    }

    // 添加监听器
    addListener(listener) {
        this.listeners.push(listener);
    }

    // 通知监听器
    notifyListeners() {
        this.listeners.forEach((listener) => listener());
    }

    // 更新数据
    updateData(newData) {
        this.model.data = newData; // 更新数据
    }

    get data() {
        return this.model.data;
    }
}

// View
class View {
    constructor(viewModel, elementId) {
        this.viewModel = viewModel;
        this.element = document.getElementById(elementId); // 绑定 DOM 元素
        this.viewModel.addListener(() => this.render()); // 监听数据变化
        this.render(); // 初始化渲染
    }

    // 渲染函数
    render() {
        console.log('render:', this.viewModel.data)
        if (this.element) {
            this.element.innerHTML = `Data: ${this.viewModel.data}`; // 更新 DOM
        }
    }

    // 处理用户输入
    onUserInput(newData) {
        this.viewModel.updateData(newData); // 更新 ViewModel
    }
}

// Main
const model = new Model();
const viewModel = new ViewModel(model);

// 假设 HTML 中有一个 id 为 "app" 的元素
const view = new View(viewModel, "app");

// 模拟用户输入
view.onUserInput("Hello, MVVM!");
// 模拟数据变更
viewModel.model.data = 'new Data.';
```

## 总结
- **MVC 适用于前后端分离的 Web 应用。**
- **MVP 适用于 UI 逻辑与数据分离的桌面或 Android 应用。**
- **MVVM 适用于数据驱动的现代前端开发。**

## 更多例子与源码
- [https://github.com/microwind/design-patterns/tree/main/mvx](https://github.com/microwind/design-patterns/tree/main/mvx)
- [https://microwind.github.io/design-patterns/](https://microwind.github.io/design-patterns/)
- [mvc_mvp_mvvm例子详解](https://microwind.github.io/design-patterns/mvc_mvp_mvvm.html)
