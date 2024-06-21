# -*- coding: utf-8 -*-
'''
# Python实现多态例子
'''

# 定义一个通用Animal类  

class Animal:  
    def make_sound(self):  
        print("Animal makes a sound")  
  
# 定义Dog类，继承Animal
class Dog(Animal):  
    name = "Dog"
    def make_sound(self):  
        print("Dog barks")  
  
# 定义Cat类，继承Animal
class Cat(Animal):  
    name = "Cat"
    def make_sound(self):  
        print("Cat meows")  
  
    # Cat自有方法  
    def meow(self):  
        print(self.name + " is meowing...")  
  
# 定义Bird类，它是动物的子类  
class Bird(Animal):  
    def make_sound(self):  
        print("Bird chirps")  

# 定义管理类
class Zoo:  
    # python与js一样为动态语言，使用duck typing，不需要显式声明接口
    def let_animal_make_sound(self, animal):  
        animal.make_sound()  
  
# 测试代码
if __name__ == "__main__":
    zoo = Zoo()

    # 直接创建实例，Python中不需要向上转型
    my_dog = Dog()
    my_cat = Cat()
    my_bird = Bird()

    # 直接调用自有方法
    my_cat.meow()

    # Python中可直接给对象设置方法，self不会改变
    my_dog.meow = my_cat.meow
    my_dog.meow()

    # 动物园可以使用相同的方法处理不同种类的动物
    zoo.let_animal_make_sound(my_dog)  # 输出 "Dog barks"
    zoo.let_animal_make_sound(my_cat)  # 输出 "Cat meows"
    zoo.let_animal_make_sound(my_bird)  # 输出 "Bird chirps"

"""
jarry@jarrys-MacBook-Pro polymorphism % python AnimalExample.py
Cat is meowing...
Cat is meowing...
Dog barks
Cat meows
Bird chirps
"""