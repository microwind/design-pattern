# -*- coding: utf-8 -*-
"""
@author: jarry
"""

import sys
import os

os_path = os.getcwd()
sys.path.append(os_path)

from src.EmployeeLeaf import EmployeeLeaf
from src.DepartmentComposite import DepartmentComposite
from src.CompanyComposite import CompanyComposite

def test():
    # 通过组合模型组合了一个部件，分支和节点可以随意增删
    com = CompanyComposite('西天旅游有限公司')
    com1 = DepartmentComposite('总裁办')
    com2 = DepartmentComposite('行动队')
    com3 = DepartmentComposite('后勤组')
    leaf1 = EmployeeLeaf('唐三藏')
    leaf2 = EmployeeLeaf('孙悟空')
    leaf3 = EmployeeLeaf('猪悟能')
    leaf4 = EmployeeLeaf('沙悟净')

    com.add(com1)
    com.add(com2)
    com.add(com3)

    # leaf1属于com1
    com1.add(leaf1)
    # leaf2, leaf3属于com2
    com2.add(leaf2)
    com2.add(leaf3)

    # 添加再删除
    dept1 = DepartmentComposite('小分队')
    com2.add(dept1)
    tmp1 = EmployeeLeaf('临时工')
    dept1.add(tmp1)
    dept1.remove(tmp1)

    # leaf4属于com3
    com3.add(leaf4)

    # 执行全部节点动作
    com.operation()

    # 获取某个节点
    employee = com.get_child(1).get_child(0)
    print(employee.get_name())


if __name__ == '__main__':
    print(__file__)
    print("test start:")
    test()
'''
jarry@jarrys-MacBook-Pro python % python -V
Python 2.7.16

jarry@jarrys-MacBook-Pro python % python test/test.py
test start:
CompanyComposite::operation() prepare
CompanyComposite::operation() 西天旅游有限公司        
DepartmentComposite::operation() 总裁办
EmployeeLeaf EmployeeLeaf::operation() 唐三藏
DepartmentComposite::operation() 行动队
EmployeeLeaf EmployeeLeaf::operation() 孙悟空
EmployeeLeaf EmployeeLeaf::operation() 猪悟能
DepartmentComposite::operation() 小分队
DepartmentComposite::operation() 后勤组
EmployeeLeaf EmployeeLeaf::operation() 沙悟净
孙悟空
'''
