class Observer:
    def update(self, message):
        pass

class MyObserver(Observer):
    def __init__(self, name):
        self.name = name

    def update(self, message):
        print(f"{self.name} 接到新消息: {message}")

class Subject:
    def __init__(self, name):
        self.name = name
        self.observers = []

    def add_observer(self, observer):
        self.observers.append(observer)

    def remove_observer(self, observer):
        self.observers.remove(observer)

    def notify(self, message):
        for observer in self.observers:
            observer.update(message)

if __name__ == "__main__":
    subject1 = Subject("Subject1")
    observer1 = MyObserver("Observer1")
    observer2 = MyObserver("Observer2")

    subject1.add_observer(observer1)
    subject1.add_observer(observer2)

    subject1.notify("发布消息")

    subject1.remove_observer(observer1)
    subject1.notify("再次发布消息")

"""
jarry@Mac python % python reactive.py
Observer1 接到新消息: 发布消息
Observer2 接到新消息: 发布消息
Observer2 接到新消息: 再次发布消息
"""