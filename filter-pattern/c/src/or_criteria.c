#include "func.h"

/* 定义Or过滤标准 */

// 先过滤条件1，再把结果按照条件2进行过滤
FilterPersons *or_criteria_filter(FilterPersons *filter, Criteria *criteria)
{
  FilterPersons *first_filter = criteria->first_criteria->filter(filter, criteria);
  FilterPersons *other_filter = criteria->other_criteria->filter(filter, criteria);
  int first_size = first_filter->length;
  int other_size = other_filter->length;

  int *other_index_list = (int *)malloc(other_size * sizeof(int));
  int count = 0;

  for (int i = 0; i < other_size; i++)
  {
    Person *person = other_filter->persons[i];
    // 如果other数组里有另外的项，则记录下坐标以添加到过滤结果中去
    if (!person->is_contained(person, first_filter))
    {
      other_index_list[count] = i;
      count += 1;
    }
  }

  // 初始化新数组，合并两个条件的结果，长度为第一个条件加上第二个条件不重合的项
  Person **result_persons = (Person **)calloc(first_size + count, sizeof(Person));
  // 复制第一个条件的结果
  for (int i = 0; i < first_size; i++)
  {
    result_persons[i] = first_filter->persons[i];
  }

  // 复制第二个条件的结果
  for (int i = 0; i < count; i++)
  {
    int result_idx = first_size + i;
    int other_idx = other_index_list[i];
    result_persons[result_idx] = other_filter->persons[other_idx];
  }

  // 返回新的查询结果
  FilterPersons *filter_persons = (FilterPersons *)calloc(1, sizeof(FilterPersons));
  filter_persons->length = first_size + count;
  filter_persons->persons = result_persons;

  free(first_filter);
  free(other_filter);
  free(other_index_list);

  return filter_persons;
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
