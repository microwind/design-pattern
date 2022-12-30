# -*- coding: utf-8 -*-
"""
@author: jarry
"""


from src.AbstractUser import AbstractUser
# 继承基础类的会员用户


class MemberUser(AbstractUser):
    def __init__(self, name):
        AbstractUser.__init__(self, name)

    # 这里覆盖了父类
    def send(self, message):
        print('MemberUser call:send() [user: {1} message: {2}]'.format(type(
            self).name, self.get_name(), message))
       # 通过中介者来中转消息
        self.room_mediator.send(this.get_name(), message)
