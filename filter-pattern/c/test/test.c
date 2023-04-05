#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../src/func.h"

void print_persons(Person *persons[], int size)
{
    if (persons == NULL)
        return;
    for (int i = 0; i < size; i++)
    {
        if (persons[i] == NULL)
        {
            break;
        }
        char *result = persons[i]->to_string(persons[i]);
        printf("\r\n %s", result);
        free(result);
    }
}

int main(void)
{
    printf("test start:\r\n");
    /**
     * 过滤器模式就是不断组合过滤条件，然后层层过滤的模式
     * 这里是简单演示，用List筛选来模拟过滤，实际例子有各种数据结构。
     */

    PERSON_DATA_SIZE = 6;
    int data_size = PERSON_DATA_SIZE;
    // 定义一些数据
    char data[6][3][100] = {
        {"王男单", "Male", "Single"},
        {"李男婚", "Male", "Married"},
        {"张女婚", "Female", "Married"},
        {"赵女单", "Female", "Single"},
        {"刘男单", "Male", "Single"},
        {"杨男单", "Male", "Single"}};

    // 定义persons数组
    Person *persons[data_size];
    // Person **persons = (Person **)calloc(data_size, sizeof(Person *));
    for (int i = 0; i < data_size; i++)
    {
        char *name = data[i][0];
        char *gender = data[i][1];
        char *status = data[i][2];
        Person *person = person_constructor(name, gender, status);
        persons[i] = person;
    }

    // 没法计算得到指针数组长度，定义全局数组长度
    // printf("size:%zd", sizeof(persons) / sizeof(persons[0]));
    // print_persons(persons, data_size);

    // 声明属性过滤条件，可用Criteria或具体条件声明
    Criteria *criteria_male = (Criteria *)criteria_male_constructor();
    CriteriaFemale *criteria_female = criteria_female_constructor();
    Criteria *criteria_single = (Criteria *)criteria_single_constructor();

    // 声明逻辑条件，传入属性过滤条件
    Criteria *single_male = (Criteria *)and_criteria_constructor(criteria_single, criteria_male);
    OrCriteria *single_or_female = or_criteria_constructor(criteria_single, (Criteria *)criteria_female);

    // 查询男性
    printf("\n Males: ");
    print_persons(((CriteriaMale *)criteria_male)->filter(persons, criteria_male), data_size);

    // 查询女性
    printf("\nFemales: ");
    print_persons(criteria_female->filter(persons, (Criteria *)criteria_female), data_size);

    // 嵌套查询女性且单身
    printf("\nFemales and Single: ");
    Person **females = criteria_female->filter(persons, (Criteria *)criteria_female);
    print_persons(((CriteriaSingle *)criteria_single)->filter(females, criteria_single), data_size);

    // 查询男性男性单身
    printf("\nSingle Males: ");
    // 逐个条件过滤
    // Person **single_males = ((CriteriaMale *)criteria_male)->filter(persons, criteria_male);
    // print_persons(((CriteriaSingle *)criteria_single)->filter(single_males, criteria_single), data_size);
    // 通过AndCriteria来过滤
    Person **single_males = ((AndCriteria *)single_male)->filter(persons, single_male);
    print_persons(single_males, data_size);

    // 查询女性或单身
    printf("\nSingle Or Females: ");
    print_persons(single_or_female->filter(persons, (Criteria *)single_or_female), data_size);

    return 0;
}

/**
jarry@jarrys-MacBook-Pro c % gcc test/test.c src*.c
jarry@jarrys-MacBook-Pro c % ./a.out
test start:

 Males: 
 Person :[ name :王男单, gender : Male, status : Single]
 Person :[ name :李男婚, gender : Male, status : Married]
 Person :[ name :刘男单, gender : Male, status : Single]
 Person :[ name :杨男单, gender : Male, status : Single]
Females: 
 Person :[ name :张女婚, gender : Female, status : Married]
 Person :[ name :赵女单, gender : Female, status : Single]
Females and Single: 
 Person :[ name :赵女单, gender : Female, status : Single]
Single Males: 
 Person :[ name :王男单, gender : Male, status : Single]
 Person :[ name :刘男单, gender : Male, status : Single]
 Person :[ name :杨男单, gender : Male, status : Single]
Single Or Females: 
 Person :[ name :王男单, gender : Male, status : Single]
 Person :[ name :赵女单, gender : Female, status : Single]
 Person :[ name :刘男单, gender : Male, status : Single]
 Person :[ name :杨男单, gender : Male, status : Single]
 Person :[ name :张女婚, gender : Female, status : Married]%  
 */