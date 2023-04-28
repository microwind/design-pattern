# -*- coding: utf-8 -*-
"""
@author: jarry
"""


class Director():

    def __init__(self):
        pass

    # 建造phone1
    def buildIPhone(self, builder):
        builder.reset()
        screen = [120, 500]
        builder.setName('iPhone')
        builder.setScreen(screen)
        builder.setGPU(100)

    # 建造phone2
    def buildHuaweiPhone(self, builder):
        builder.reset()
        screen = [140, 600]
        builder.setName('HuaweiPhone')
        builder.setScreen(screen)
        builder.setGPU(102)

    # 建造phone3
    def buildMiPhone(self, builder):
        builder.reset()
        screen = [130, 550]
        # 链式调用
        builder.setName('MiPhone').setScreen(screen).setGPU(103)
