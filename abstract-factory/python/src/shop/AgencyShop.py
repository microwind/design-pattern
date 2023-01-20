# -*- coding: utf-8 -*-
"""
@author: jarry
"""
from src.shop.Shop import Shop

# 具体产品类，继承该类产品父类
class AgencyShop(Shop):

    def greetings(self):
        print('AgencyShop::greetings')
