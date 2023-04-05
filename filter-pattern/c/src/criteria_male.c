#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "func.h"

// 根据是否男性进行过滤
Person **criteria_male_filter(Person **persons, Criteria *criteria)
{
  int person_size = PERSON_DATA_SIZE;
  int *male_index_list = (int *)malloc(person_size * sizeof(int));
  int count = 0;
  char *gender;
  for (int i = 0; i < person_size; i++)
  {
    if (persons[i] == NULL)
    {
      break;
    }
    gender = str_tolower(persons[i]->gender);
    if (strcmp(gender, "male") == 0)
    {
      // 记录下所有符合条件的person下标
      male_index_list[count] = i;
      count += 1;
    }
  }
  free(gender);
  free(male_index_list);

  // 将符合条件的person追加到新数组
  Person **male_persons = (Person **)calloc(count, sizeof(Person));
  for (int i = 0; i < count; i++)
  {
    male_persons[i] = persons[male_index_list[i]];
  }
  return male_persons;
}

CriteriaMale *criteria_male_constructor()
{
  Criteria *criteria = (Criteria *)malloc(sizeof(Criteria));
  criteria->filter = &criteria_male_filter;
  CriteriaMale *criteria_male = (CriteriaMale *)criteria;
  criteria_male->filter = &criteria_male_filter;
  return criteria_male;
}