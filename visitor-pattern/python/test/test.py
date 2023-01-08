# -*- coding: utf-8 -*-
"""
@author: jarry
"""

import sys
import os

os_path = os.getcwd()
sys.path.append(os_path)

from src.ObjectStructure import ObjectStructure
from src.ConcreteVisitorA import ConcreteVisitorA
from src.ConcreteVisitorB import ConcreteVisitorB


def test():
    '''
    * 访问者模式是当客户需要访问具体各元素Element时，先建立一个访问者Visitor作为媒介
    * 客户基于对象结构ObjectStructure，调用accept访问，并传入访问者
    * 对象结构向其他元素对象负责分发Visitor，元素对象接受之后会将自己回传给访问者，访问者则可以访问元素
    '''
    structure = ObjectStructure()
    # 接受访问者A，把访问者传递给具体元素
    structure.accept(ConcreteVisitorA())

    print('====')
    # 接受访问者B，把访问者传递给具体元素
    structure.accept(ConcreteVisitorB())


if __name__ == '__main__':
    print(__file__)
    print("test start:")
    test()
'''
jarry@jarrys-MacBook-Pro python % python3 test/test.py 
test/test.py
test start:
ObjectStructure::accept() [visitor.class = ConcreteVisitorA visitor.name = Google Visitor]
ConcreteElementA::accept() [visitor.class = ConcreteVisitorA visitor.name = Google Visitor]
ConcreteVisitorA::visit() [Element.class = ConcreteElementA Element.name = Monitor Element]
ConcreteElementA::operate() [Monitor Element]
ConcreteElementB::accept() [visitor.class = ConcreteVisitorA visitor.name = Google Visitor]
ConcreteVisitorA::visit() [Element.class = ConcreteElementB Element.name = Keyboard Element]
ConcreteElementB::operate() [Keyboard Element]
====
ObjectStructure::accept() [visitor.class = ConcreteVisitorB visitor.name = Apple Visitor]
ConcreteElementA::accept() [visitor.class = ConcreteVisitorB visitor.name = Apple Visitor]
ConcreteVisitorB::visit() [Element.class = ConcreteElementA Element.name = Monitor Element]
ConcreteElementA::operate() [Monitor Element]
ConcreteElementB::accept() [visitor.class = ConcreteVisitorB visitor.name = Apple Visitor]
ConcreteVisitorB::visit() [Element.class = ConcreteElementB Element.name = Keyboard Element]
ConcreteElementB::operate() [Keyboard Element]
'''