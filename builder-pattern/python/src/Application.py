# -*- coding: utf-8 -*-
"""
@author: jarry
"""

from src.Director import Director
from src.PhoneBuilder import PhoneBuilder
from src.ManualBuilder import ManualBuilder


class Application():

    def __init__(self):
        pass

    @staticmethod
    def makeIPhone():
        director = Director()
        # 创建手机
        phoneBuilder = PhoneBuilder()
        director.buildIPhone(phoneBuilder)
        iPhone = phoneBuilder.getProduct()
        print('iPhone:' + iPhone.getName() + ' | ', iPhone)

        # 创建手册
        manualBuilder = ManualBuilder()
        director.buildIPhone(manualBuilder)
        manual = manualBuilder.getProduct()
        print('manual:' + manual.getName() + ' | ', manual)

    @staticmethod
    def makeHuaweiPhone():
        director = Director()

        # 创建手机
        phoneBuilder = PhoneBuilder()
        director.buildHuaweiPhone(phoneBuilder)
        huaweiPhone = phoneBuilder.getProduct()
        print('huaweiPhone:' + huaweiPhone.getName() + ' | ', huaweiPhone)

        # 创建手册
        manualBuilder = ManualBuilder()
        director.buildHuaweiPhone(manualBuilder)
        manual = manualBuilder.getProduct()
        print('manual:' + manual.getName() + ' | ', manual)
