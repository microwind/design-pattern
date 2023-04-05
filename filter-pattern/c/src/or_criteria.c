#include "func.h"

/* 定义Or过滤标准 */

// 先过滤条件1，再把结果按照条件2进行过滤
FilterPersons *or_criteria_filter(FilterPersons *filter, Criteria *criteria)
{
  FilterPersons *first_filter = criteria->first_criteria->filter(filter, criteria);
  FilterPersons *other_filter = criteria->other_criteria->filter(filter, criteria);

  int first_size = first_filter->length;
  int other_size = other_filter->length;

  for (int i = 0; i < other_size; i++)
  {
    Person *person = other_filter->persons[i];
    // 符合项如果不存在条件1里，则追加到条件1里去
    if (!person->is_contained(person, first_filter))
    {
      // 这里数组长度直接增加
      first_filter->persons[first_size++] = person;
    }
  }

  first_filter->length = first_size;

  return first_filter;
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
