# -*- coding: utf-8 -*-
"""
@author: jarry
"""

# 基础用户类，供具体继承


class AbstractUser:
    name = None
    room_mediator = []

    def __init__(self, name):
        self.name = name

    def set_room_mediator(self, room_mediator):
        self.room_mediator = room_mediator

    def send(self, message):
        print('{0}:send() [user: {1} message: {2}]'.format(
            self.__class__.__name__, self.get_name(), message))
        # 通过中介者来中转消息
        self.room_mediator.send(self, message)

    def send_to(self, to, message):
        print('{0}:send_to() [user: {1} message: {2} to: {3}]'.format(
            self.__class__.__name__, self.get_name(), message, to.get_name()))
        # 通过中介者来中转消息
        self.room_mediator.send_to(self, to, message)

    def recieve(self, sender, message):
        print('{0}:recieve() [user: {1} message: {2} from: {3}]'.format(
            self.__class__.__name__, self.get_name(), message, sender.get_name()))

    def get_name(self):
        return self.name
