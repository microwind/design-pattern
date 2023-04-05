#include "func.h"

// 根据是否女性进行过滤
FilterPersons *criteria_female_filter(FilterPersons *filter, Criteria *criteria)
{
  int person_size = filter->length;
  int *female_index_list = (int *)malloc(person_size * sizeof(int));
  int count = 0;
  char *gender;
  for (int i = 0; i < person_size; i++)
  {
    if (filter->persons[i] == NULL)
    {
      break;
    }
    gender = str_toupper(filter->persons[i]->gender);
    if (strcmp(gender, "FEMALE") == 0)
    {
      // 记录下所有符合条件的person下标
      female_index_list[count] = i;
      count += 1;
    }
  }
  free(gender);
  free(female_index_list);

  // 将符合条件的person追加到新数组
  Person **female_persons = (Person **)calloc(count, sizeof(Person));
  for (int i = 0; i < count; i++)
  {
    female_persons[i] = filter->persons[female_index_list[i]];
  }
  FilterPersons *female_filter = (FilterPersons *)calloc(1, sizeof(FilterPersons));
  female_filter->length = count;
  female_filter->persons = female_persons;
  return female_filter;
}

CriteriaFemale *criteria_female_constructor()
{
  Criteria *criteria = (Criteria *)malloc(sizeof(Criteria));
  criteria->filter = &criteria_female_filter;
  CriteriaFemale *criteria_female = (CriteriaFemale *)criteria;
  criteria_female->filter = &criteria_female_filter;
  return criteria_female;
}
