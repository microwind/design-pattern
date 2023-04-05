#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "func.h"

/* 定义Or过滤标准 */

// 先过滤条件1，再把结果按照条件2进行过滤
Person **or_criteria_filter(Person **persons, Criteria *criteria)
{
  Person **first_criteria_persons = criteria->first_criteria->filter(persons, criteria);
  Person **other_criteria_persons = criteria->other_criteria->filter(persons, criteria);

  int first_size = 0;
  for (int i = 0; i < PERSON_DATA_SIZE; i++)
  {
    if (first_criteria_persons[i] == NULL)
    {
      break;
    }
    first_size++;
  }

  int other_size = 0;
  for (int i = 0; i < PERSON_DATA_SIZE; i++)
  {
    if (other_criteria_persons[i] == NULL)
    {
      break;
    }
    other_size++;
  }

  for (int i = 0; i < other_size; i++)
  {
    Person *person = other_criteria_persons[i];
    // 条件2里的符合项如果不存在条件1里，则追加到条件1里去
    if (!person->is_contained(person, first_criteria_persons))
    {
      first_criteria_persons[first_size++] = person;
    }
  }

  return first_criteria_persons;
}

OrCriteria *or_criteria_constructor(Criteria *first_criteria, Criteria *other_criteria)
{
  Criteria *criteria = (Criteria *)malloc(sizeof(Criteria));
  criteria->filter = &or_criteria_filter;
  OrCriteria *or_criteria = (OrCriteria *)criteria;
  or_criteria->first_criteria = first_criteria;
  or_criteria->other_criteria = other_criteria;
  or_criteria->filter = &or_criteria_filter;
  return or_criteria;
}
