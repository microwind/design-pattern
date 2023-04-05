#include "func.h"

// 根据是否单身进行过滤
FilterPersons *criteria_single_filter(FilterPersons *filter, Criteria *criteria)
{
  int person_size = filter->length;
  int *single_index_list = (int *)malloc(person_size * sizeof(int));
  int count = 0;
  char *status;
  for (int i = 0; i < person_size; i++)
  {
    if (filter->persons[i] == NULL)
    {
      break;
    }
    status = str_tolower(filter->persons[i]->status);
    if (strcmp(status, "single") == 0)
    {
      // 记录下所有符合条件的person下标
      single_index_list[count] = i;
      count += 1;
    }
  }
  free(status);
  free(single_index_list);

  // 将符合条件的person追加到新数组
  Person **single_persons = (Person **)calloc(count, sizeof(Person));
  for (int i = 0; i < count; i++)
  {
    single_persons[i] = filter->persons[single_index_list[i]];
  }

  FilterPersons *single_filter = (FilterPersons *)calloc(1, sizeof(FilterPersons));
  single_filter->length = count;
  single_filter->persons = single_persons;
  return single_filter;
}

CriteriaSingle *criteria_single_constructor()
{
  Criteria *criteria = (Criteria *)malloc(sizeof(Criteria));
  criteria->filter = &criteria_single_filter;
  CriteriaSingle *criteria_single = (CriteriaSingle *)criteria;
  criteria_single->filter = &criteria_single_filter;
  return criteria_single;
}