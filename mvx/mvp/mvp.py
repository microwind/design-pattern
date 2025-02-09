# View: 负责显示数据并触发事件
class View:
    def __init__(self, presenter):
        self.presenter = presenter

    def render(self, name, num):
        print(f"<b>{name}</b><em>{num}</em>")

    def set_click_listener(self):
        # 模拟点击事件
        self.presenter.add(1)

    def set_mouse_out_listener(self):
        # 模拟鼠标移出事件
        self.presenter.change("Click to add")

# Model: 负责数据处理
class Model:
    def __init__(self):
        self.name = "MVP"
        self.num = 1

    def get_name(self):
        return self.name

    def get_num(self):
        return self.num

    def update(self, value):
        self.num += value

    def change(self, name):
        self.name = name

# Presenter: 负责协调 View 和 Model
class Presenter:
    def __init__(self, view, model):
        self.view = view
        self.model = model

    def init(self):
        self.view.set_click_listener()
        self.view.set_mouse_out_listener()
        self.render()

    def render(self):
        self.view.render(self.model.get_name(), self.model.get_num())

    def add(self, value):
        self.model.update(value)
        self.render()

    def change(self, name):
        self.model.change(name)
        self.render()

# 主程序
if __name__ == '__main__':
    model = Model()
    view = View(Presenter(view=None, model=model))
    presenter = Presenter(view=view, model=model)
    presenter.init()
