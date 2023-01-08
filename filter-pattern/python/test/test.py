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
            print('Person : [ Name : ' + person.getName() + ', Gender : ' +
                  person.getGender() + ', Marital Status : ' +
                  person.getStatus() + ' ]')

    '''
    * 过滤器模式就是不断组合过滤条件，然后层层过滤的模式
    * 这里是简单演示，其实就是List筛选。JS 数组有filter本身非常方便
    '''
    persons = []

    persons.append(Person('Robert', 'Male', 'Single'))
    persons.append(Person('John', 'Male', 'Married'))
    persons.append(Person('Laura', 'Female', 'Married'))
    persons.append(Person('Diana', 'Female', 'Single'))
    persons.append(Person('Mike', 'Male', 'Single'))
    persons.append(Person('Bobby', 'Male', 'Single'))

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
Person : [ Name : Robert, Gender : Male, Marital Status : Single ]
Person : [ Name : John, Gender : Male, Marital Status : Married ]
Person : [ Name : Mike, Gender : Male, Marital Status : Single ]
Person : [ Name : Bobby, Gender : Male, Marital Status : Single ]

Females: 
Person : [ Name : Laura, Gender : Female, Marital Status : Married ]
Person : [ Name : Diana, Gender : Female, Marital Status : Single ]

Females and Single: 
Person : [ Name : Diana, Gender : Female, Marital Status : Single ]

Single Males: 
Person : [ Name : Robert, Gender : Male, Marital Status : Single ]
Person : [ Name : Mike, Gender : Male, Marital Status : Single ]
Person : [ Name : Bobby, Gender : Male, Marital Status : Single ]

Single Or Females: 
Person : [ Name : Robert, Gender : Male, Marital Status : Single ]
Person : [ Name : Diana, Gender : Female, Marital Status : Single ]
Person : [ Name : Mike, Gender : Male, Marital Status : Single ]
Person : [ Name : Bobby, Gender : Male, Marital Status : Single ]
Person : [ Name : Laura, Gender : Female, Marital Status : Married ]
'''