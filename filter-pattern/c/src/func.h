#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

char *str_toupper(char str[]);
char *str_tolower(char str[]);

// 定义用于过滤的Person数组查询对象
// 因C语言无法定义动态数组，将数组长度存在此处
typedef struct FilterPersons
{
    int length;
    struct Person **persons;
} FilterPersons;

// 定义一个实体类，用来过滤的对象
typedef struct Person
{
    char name[50];
    char gender[20];
    char status[20];
    char *(*get_name)(struct Person *);
    char *(*to_string)(struct Person *);
    bool (*is_contained)(struct Person *, struct FilterPersons *);
} Person;
Person *person_constructor(char *name, char *gender, char *status);

// 定义抽象标准接口，聚合要过滤的对象集合
typedef struct Criteria
{
    struct Criteria *first_criteria;
    struct Criteria *other_criteria;
    FilterPersons *(*filter)(FilterPersons *, struct Criteria *);
} Criteria;

// 根据标准接口实现的过滤
typedef struct CriteriaFemale
{
    FilterPersons *(*filter)(FilterPersons *, struct Criteria *);
} CriteriaFemale;
CriteriaFemale *criteria_female_constructor();

// 根据标准接口实现的过滤
typedef struct CriteriaMale
{
    FilterPersons *(*filter)(FilterPersons *, struct Criteria *);
} CriteriaMale;
CriteriaMale *criteria_male_constructor();

// 根据标准接口实现的过滤
typedef struct CriteriaSingle
{
    FilterPersons *(*filter)(FilterPersons *, struct Criteria *);
} CriteriaSingle;
CriteriaSingle *criteria_single_constructor();

// 定义And过滤标准
typedef struct AndCriteria
{
    struct Criteria *first_criteria;
    struct Criteria *other_criteria;
    FilterPersons *(*filter)(FilterPersons *, struct Criteria *);
} AndCriteria;
AndCriteria *and_criteria_constructor(Criteria *, Criteria *);

// 定义Or过滤标准
typedef struct OrCriteria
{
    struct Criteria *first_criteria;
    struct Criteria *other_criteria;
    FilterPersons *(*filter)(FilterPersons *, struct Criteria *);
} OrCriteria;
OrCriteria *or_criteria_constructor(Criteria *, Criteria *);