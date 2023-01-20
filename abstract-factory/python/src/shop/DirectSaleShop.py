# -*- coding: utf-8 -*-
"""
@author: jarry
"""
from src.shop.Shop import Shop


class DirectSaleShop(Shop):

    def greetings(self):
        print('DirectSaleShop::greetings')

    def welcome(self):
        print('DirectSaleShop::welcome')
