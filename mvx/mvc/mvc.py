# Model: 负责数据管理
class Model:
    def __init__(self):
        self.name = "MVC Basic"
        self.num = 1

    def get_name(self):
        return self.name

    def get_num(self):
        return self.num

    def set_name(self, name):
        self.name = name

    def increment_num(self, value):
        self.num += value

# View: 负责显示数据
class View:
    def display(self, name, num):
        print(f"<div><b>{name}</b><em>{num}</em></div>")

# Controller: 负责处理用户输入和业务逻辑
class Controller:
    def __init__(self, model, view):
        self.model = model
        self.view = view

    def on_button_click(self):
        self.model.increment_num(1)
        self.view.display(self.model.get_name(), self.model.get_num())

    def on_mouse_out(self):
        self.model.set_name("Click to add")
        self.view.display(self.model.get_name(), self.model.get_num())

# Test
def test():
    model = Model()
    view = View()
    controller = Controller(model, view)

    print("Test 1: Button Click")
    controller.on_button_click()  # simulate button click

    print("Test 2: Mouse Out")
    controller.on_mouse_out()  # simulate mouse out

test()

"""
jarry@MacBook-Pro mvc % python mvc.py 
Test 1: Button Click
<div><b>MVC Basic</b><em>2</em></div>
Test 2: Mouse Out
<div><b>Click to add</b><em>2</em></div>
"""