# MVC 模式
# - Model：负责业务逻辑和数据处理，直接与数据库或数据源交互。
# - View：负责渲染用户界面，显示数据给用户。View可与Model绑定。
# - Controller：作为用户输入的中介，接收用户的输入并更新 Model 或 View。

# Model (数据模型)
class Model:
    def __init__(self):
        self.name = "MVC Basic"
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
    def __init__(self, model):
        self.model = model

    def update_view(self):
        print(
            f"<div><b>{self.model.get_name()}</b><em>{self.model.get_num()}</em></div>")


# Controller (控制器)
class Controller:
    def __init__(self, model, view):
        self.model = model
        self.view = view

    def on_button_click(self):
        self.model.set_name("onButtonClick")
        self.model.increment_num(1)
        self.update_view()

    def on_mouse_out(self):
        self.model.set_name("onMouseOut")
        self.model.set_num(0)
        self.update_view()

    def update_view(self):
        self.view.update_view()


# Test
if __name__ == "__main__":
    model = Model()
    # view绑定model或render时从model取数据
    view = View(model)
    controller = Controller(model, view)

    print("Test 1: Button Click")
    controller.on_button_click()

    print("Test 2: Mouse Out")
    controller.on_mouse_out()

"""
jarry@MacBook-Pro mvc % python mvc.py
Test 1: Button Click
<div><b>onButtonClick</b><em>2</em></div>
Test 2: Mouse Out
<div><b>onMouseOut</b><em>0</em></div>
"""