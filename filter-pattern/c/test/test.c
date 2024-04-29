#include "../src/func.h"

void print_persons(FilterPersons *filter)
{
    for (int i = 0; i < filter->length; i++)
    {
        char *result = filter->persons[i]->to_string(filter->persons[i]);
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

    int data_size = 6;
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
    for (int i = 0; i < data_size; i++)
    {
        char *name = data[i][0];
        char *gender = data[i][1];
        char *status = data[i][2];
        Person *person = person_constructor(name, gender, status);
        persons[i] = person;
    }

    // 构建查询对象
    FilterPersons *filter_persons = (FilterPersons *)malloc(sizeof(FilterPersons *));
    filter_persons->length = data_size;
    filter_persons->persons = persons;

    // 声明属性过滤条件，可用Criteria或具体条件声明
    Criteria *criteria_male = (Criteria *)criteria_male_constructor();
    CriteriaFemale *criteria_female = criteria_female_constructor();
    Criteria *criteria_single = (Criteria *)criteria_single_constructor();

    // 声明逻辑条件，传入属性过滤条件
    Criteria *single_male = (Criteria *)and_criteria_constructor(criteria_single, criteria_male);
    OrCriteria *single_or_female = or_criteria_constructor(criteria_single, (Criteria *)criteria_female);

    // 查询男性
    printf("\n Males: ");
    print_persons(((CriteriaMale *)criteria_male)->filter(filter_persons, criteria_male));

    // 查询女性
    printf("\nFemales: ");
    print_persons(criteria_female->filter(filter_persons, (Criteria *)criteria_female));

    // 嵌套查询女性且单身
    printf("\nFemales and Single: ");
    FilterPersons *females = criteria_female->filter(filter_persons, (Criteria *)criteria_female);
    print_persons(((CriteriaSingle *)criteria_single)->filter(females, criteria_single));

    // 查询男性男性单身
    printf("\nSingle Males: ");
    // 逐个条件过滤，与下面AndCriteria效果相同
    FilterPersons *single_males = ((CriteriaMale *)criteria_male)->filter(filter_persons, criteria_male);
    print_persons(((CriteriaSingle *)criteria_single)->filter(single_males, criteria_single));
    printf("\nSingle Males: ");
    // 通过AndCriteria来过滤
    FilterPersons *single_males2 = ((AndCriteria *)single_male)->filter(filter_persons, single_male);
    print_persons(single_males2);

    // 查询女性或单身
    printf("\nSingle Or Females: ");
    print_persons(single_or_female->filter(filter_persons, (Criteria *)single_or_female));

    free(filter_persons);
    free(criteria_male);
    free(criteria_female);
    free(criteria_single);
    free(single_male);
    free(single_or_female);

    return 0;
}


// jarry@jarrys-MacBook-Pro c % gcc test/test.c src*.c
// jarry@jarrys-MacBook-Pro c % ./a.out
/**
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