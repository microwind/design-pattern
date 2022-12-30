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
            type(self).__name__, self.get_name(), message))
        # 通过中介者来中转消息
        self.room_mediator.send(self.get_name(), message)

    def send_to(self, to, message):
        print('{0}:send_to() [user: {1} message: {2} to: {3}]'.format(type(
            self).__name__, self.get_name(), message, to))
        # 通过中介者来中转消息
        self.room_mediator.send_to(self.get_name(), to, message)

    def recieve(self, sender, message):
        print('{0}:recieve() [user: {1} message: {2} from: {3}]'.format(type(
            self).__name__, self.get_name(), message, sender))

    def get_name(self):
        return self.name
