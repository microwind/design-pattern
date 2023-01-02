# -*- coding: utf-8 -*-
"""
@author: jarry
"""

from src.AbstractHandler import AbstractHandler

# 用户基本信息检查类
class UserHandler(AbstractHandler):
    # 如果检查不通过则返回失败，否则继续下一个检查
    def check(self, uid):
        print(self.__class__.__name__ + '::check() [uid = ' + str(uid) + ']')
        if (uid % 3 == 0):
            return False

        return self.checkNext(uid)
