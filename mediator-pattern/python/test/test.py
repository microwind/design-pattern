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
    user2.send_to(user3.get_name(), 'haha.')


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
>>GeneralRoom:send() [from: user1 message: hi, I'm user1.]
CommonUser:recieve() [user: user1 message: hi, I'm user1. from: user1]
CommonUser:recieve() [user: user2 message: hi, I'm user1. from: user1]
MemberUser:recieve() [user: user3 message: hi, I'm user1. from: user1]
CommonUser:send_to() [user: user2 message: haha. to: user3]
>>GeneralRoom:send_to() [from: user2 message: haha. to: user3]        
MemberUser:recieve() [user: user3 message: haha. from: user2]
'''
