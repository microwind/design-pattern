# -*- coding: utf-8 -*-
"""
@author: jarry
"""

import sys
import os

os_path = os.getcwd()
sys.path.append(os_path)

from src.MemberUser import MemberUser
from src.CommonUser import CommonUser
from src.GeneralRoom import GeneralRoom

def test():
    '''
    * 中介者模式用一个中介对象来封装一系列动作，让对象之间利用中介者来交流。
    * 这里聊天室就是一个中介者，用户和用户之间的消息传递，全部依靠聊天室来完成。
    * 先给聊天室注册用户，也给用户绑定上中介者，双方彼此持有关系。
    * 中介者的成员之间的消息传递通过中介者来代理传达。
    '''

    # 声明一个聊天室
    general_room = GeneralRoom()
    # 给聊天室添加点不同的人
    user1 = CommonUser('user1')
    general_room.register(user1)
    user2 = CommonUser('user2')
    general_room.register(user2)
    user3 = MemberUser('user3')
    general_room.register(user3)

    # user1 发送给全体
    user1.send("hi, I'm " + user1.get_name() + '.')
    # user2 发送给 user3
    user2.send_to(user3, 'haha.')


if __name__ == '__main__':
    print(__file__)
    print("test start:")
    test()
'''
jarry@jarrys-MacBook-Pro python % python -V
Python 2.7.16

jarry@jarrys-MacBook-Pro python % python test/test.py
test start:
CommonUser:send() [user: user1 message: hi, I'm user1.]
GeneralRoom:send() [from: user1 message: hi, I'm user1.]
CommonUser:recieve() [user: user1 message: hi, I'm user1. from: user1]
CommonUser:recieve() [user: user2 message: hi, I'm user1. from: user1]
MemberUser:recieve() [user: user3 message: hi, I'm user1. from: user1]
CommonUser:send_to() [user: user2 message: haha. to: user3]
GeneralRoom:send_to() [from: user2 message: haha. to: user3]
MemberUser:recieve() [user: user3 message: haha. from: user2]
'''
