# -*- coding: utf-8 -*-
"""
@author: jarry
"""

from src.RoomMediator import RoomMediator

# 中介者的具体实现类


class GeneralRoom(RoomMediator):
    def __init__(self):
        RoomMediator.__init__(self)

    # 作为中介者通知给某个用户
    def send_to(self, sender, to, message):
        print('{0}:send_to() [from: {1} message: {2} to: {3}]'.format(
            self.__class__.__name__, sender.get_name(), message, to.get_name()))
        # 定向发送
        to.recieve(sender, message)

    # 作为中介者通知给全体用户
    def send(self, sender, message):
        print('{0}:send() [from: {1} message: {2}]'.format(
            self.__class__.__name__, sender.get_name(), message))
        for user in self.users:
            user.recieve(sender, message)
