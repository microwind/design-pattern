#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

char *str_toupper(char str[]);
char *str_tolower(char str[]);
// C语言无动态数组，提前指定数组大小
int PERSON_DATA_SIZE;
// 定义一个实体类，用来过滤的对象
typedef struct Person
{
    char name[50];
    char gender[20];
    char status[20];
    char *(*get_name)(struct Person *);
    char *(*to_string)(struct Person *);
    bool (*is_contained)(struct Person *, struct Person **);
} Person;
Person *person_constructor(char *name, char *gender, char *status);

// 定义抽象标准接口，聚合要过滤的对象集合
typedef struct Criteria
{
    struct Criteria *first_criteria;
    struct Criteria *other_criteria;
    Person **(*filter)(Person **persons, struct Criteria *criteria);
} Criteria;

// 根据标准接口实现的过滤
typedef struct CriteriaFemale
{
    Person **(*filter)(Person **persons, struct Criteria *criteria);
} CriteriaFemale;
CriteriaFemale *criteria_female_constructor();

// 根据标准接口实现的过滤
typedef struct CriteriaMale
{
    Person **(*filter)(Person **persons, struct Criteria *criteria);
} CriteriaMale;
CriteriaMale *criteria_male_constructor();

// 根据标准接口实现的过滤
typedef struct CriteriaSingle
{
    Person **(*filter)(Person **persons, struct Criteria *criteria);
} CriteriaSingle;
CriteriaSingle *criteria_single_constructor();

// 定义And过滤标准
typedef struct AndCriteria
{
    struct Criteria *first_criteria;
    struct Criteria *other_criteria;
    Person **(*filter)(Person **persons, struct Criteria *criteria);
} AndCriteria;
AndCriteria *and_criteria_constructor(Criteria *first_criteria, Criteria *other_criteria);

// 定义Or过滤标准
typedef struct OrCriteria
{
    struct Criteria *first_criteria;
    struct Criteria *other_criteria;
    Person **(*filter)(Person **persons, struct Criteria *criteria);
} OrCriteria;
OrCriteria *or_criteria_constructor(Criteria *first_criteria, Criteria *other_criteria);