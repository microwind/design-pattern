# -*- coding: utf-8 -*-
"""
@author: jarry
"""

import sys
import os

os_path = os.getcwd()
sys.path.append(os_path)

from src.Person import Person
from src.CriteriaMale import CriteriaMale
from src.CriteriaFemale import CriteriaFemale
from src.CriteriaSingle import CriteriaSingle
from src.AndCriteria import AndCriteria
from src.OrCriteria import OrCriteria


def test():

    def printPersons(persons):
        for person in persons:
            print(person.to_string())

    '''
    * 过滤器模式就是不断组合过滤条件，然后层层过滤的模式
    * 这里是简单演示，其实就是list做条件筛选。
    '''
    persons = []

    persons.append(Person('王男单', 'Male', 'Single'))
    persons.append(Person('李男婚', 'Male', 'Married'))
    persons.append(Person('张女婚', 'Female', 'Married'))
    persons.append(Person('赵女单', 'Female', 'Single'))
    persons.append(Person('刘男单', 'Male', 'Single'))
    persons.append(Person('杨男单', 'Male', 'Single'))

    male = CriteriaMale()
    female = CriteriaFemale()
    single = CriteriaSingle()
    singleMale = AndCriteria(single, male)
    singleOrFemale = OrCriteria(single, female)

    # 查询男性
    print('Males: ')
    printPersons(male.filter(persons))

    # 查询女性
    print('\nFemales: ')
    printPersons(female.filter(persons))

    # 嵌套查询女性且单身
    print('\nFemales and Single: ')
    printPersons(single.filter(female.filter(persons)))

    # 查询男性男性单身
    print('\nSingle Males: ')
    printPersons(singleMale.filter(persons))

    # 查询女性或单身
    print('\nSingle Or Females: ')
    printPersons(singleOrFemale.filter(persons))


if __name__ == '__main__':
    print(__file__)
    print("test start:")
    test()
'''
jarry@jarrys-MacBook-Pro python % python3 test/test.py
test/test.py
test start:
Males: 
Person : [ Name : 王男单, Gender : Male, Marital Status : Single ]
Person : [ Name : 李男婚, Gender : Male, Marital Status : Married ]
Person : [ Name : 刘男单, Gender : Male, Marital Status : Single ]
Person : [ Name : 杨男单, Gender : Male, Marital Status : Single ]

Females: 
Person : [ Name : 张女婚, Gender : Female, Marital Status : Married ]
Person : [ Name : 赵女单, Gender : Female, Marital Status : Single ]

Females and Single: 
Person : [ Name : 赵女单, Gender : Female, Marital Status : Single ]

Single Males: 
Person : [ Name : 王男单, Gender : Male, Marital Status : Single ]
Person : [ Name : 刘男单, Gender : Male, Marital Status : Single ]
Person : [ Name : 杨男单, Gender : Male, Marital Status : Single ]

Single Or Females: 
Person : [ Name : 王男单, Gender : Male, Marital Status : Single ]
Person : [ Name : 赵女单, Gender : Female, Marital Status : Single ]
Person : [ Name : 刘男单, Gender : Male, Marital Status : Single ]
Person : [ Name : 杨男单, Gender : Male, Marital Status : Single ]
Person : [ Name : 张女婚, Gender : Female, Marital Status : Married ]
'''