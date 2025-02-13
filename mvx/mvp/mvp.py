# MVP 模式
# - Model：负责业务逻辑和数据处理，直接与数据库或数据源交互。
# - View：负责渲染用户界面，显示数据给用户。View不直接绑定Model，而通过Presenter获取数据。
# - Presenter：作为中介者，接收用户输入并更新 Model 或 View，处理业务逻辑。

# Model (数据模型)
class Model:
    def __init__(self):
        self.name = "MVP Basic"
        self.num = 1

    def get_name(self):
        return self.name

    def set_num(self, num):
        self.num = num

    def get_num(self):
        return self.num

    def increment_num(self, value):
        self.num += value

    def set_name(self, name):
        self.name = name


# View (视图层)
class View:
    # View 只负责显示数据，并提供更新界面的接口
    def update_view(self, name, num):
        print(f"<div><b>{name}</b><em>{num}</em></div>")


# Presenter (中介者)
class Presenter:
    def __init__(self, model, view):
        self.model = model
        self.view = view

    # 按钮点击时通过 Presenter 更新 Model 数据并刷新视图
    def on_button_click(self):
        self.model.set_name("onButtonClick")
        self.model.increment_num(1)
        self.update_view()

    # 鼠标移出时通过 Presenter 更新 Model 数据并刷新视图
    def on_mouse_out(self):
        self.model.set_name("onMouseOut")
        self.model.set_num(0)
        self.update_view()

    # 由 Presenter 调用更新 View，传递数据，而不是Model
    def update_view(self):
        self.view.update_view(self.model.get_name(), self.model.get_num())


# Test
model = Model()
# view与model无关联
view = View()
presenter = Presenter(model, view)

print("Test 1: Button Click")
presenter.on_button_click()

print("Test 2: Mouse Out")
presenter.on_mouse_out()

"""
jarry@MacBook-Pro mvp % python mvp.py
Test 1: Button Click
<div><b>onButtonClick</b><em>2</em></div>
Test 2: Mouse Out
<div><b>onMouseOut</b><em>0</em></div>
"""
