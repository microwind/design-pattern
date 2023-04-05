#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "func.h"

// 根据是否女性进行过滤
Person **criteria_female_filter(Person **persons, Criteria *criteria)
{
  int person_size = PERSON_DATA_SIZE;
  int *female_index_list = (int *)malloc(person_size * sizeof(int));
  int count = 0;
  char *gender;
  for (int i = 0; i < person_size; i++)
  {
    if (persons[i] == NULL) {
      break;
    }
    gender = str_toupper(persons[i]->gender);
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
    female_persons[i] = persons[female_index_list[i]];
  }
  return female_persons;
}

CriteriaFemale *criteria_female_constructor()
{
  Criteria *criteria = (Criteria *)malloc(sizeof(Criteria));
  criteria->filter = &criteria_female_filter;
  CriteriaFemale *criteria_female = (CriteriaFemale *)criteria;
  criteria_female->filter = &criteria_female_filter;
  return criteria_female;
}
