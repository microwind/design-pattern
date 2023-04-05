#include "func.h"

/* 定义And过滤标准 */

// 先过滤条件1，再把结果按照条件2进行过滤
FilterPersons *and_criteria_filter(FilterPersons *filter, Criteria *criteria)
{
  FilterPersons *first_filter = criteria->first_criteria->filter(filter, criteria);
  return criteria->other_criteria->filter(first_filter, criteria);
}

AndCriteria *and_criteria_constructor(Criteria *first_criteria, Criteria *other_criteria)
{
  Criteria *criteria = (Criteria *)malloc(sizeof(Criteria));
  criteria->filter = &and_criteria_filter;
  AndCriteria *and_criteria = (AndCriteria *)criteria;
  and_criteria->first_criteria = first_criteria;
  and_criteria->other_criteria = other_criteria;
  and_criteria->filter = &and_criteria_filter;
  return and_criteria;
}