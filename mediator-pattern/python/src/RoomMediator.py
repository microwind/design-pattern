# -*- coding: utf-8 -*-
"""
@author: jarry
"""

# 定义中介者接口或抽象类


class RoomMediator:
    def __init__(self):
        pass
    users = []

    def register(self, user):
        # 用户注册登记，追加用户列表
        user.set_room_mediator(self)
        self.users.append(user)

    def send_to(self, sender, to, message):
        pass

    def send(self, sender, message):
        pass
