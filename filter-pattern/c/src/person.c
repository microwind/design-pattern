#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "func.h"

/* Person实体对象，用来做过滤 */

// 是否被包含在对象数组中
bool person_is_contained(Person *person, Person **persons)
{
  int persons_size = PERSON_DATA_SIZE;
  for (int i = 0; i < persons_size; i++)
  {
    if (persons[i] == person)
    {
      return true;
    }
  }
  return false;
}

char *person_get_name(Person *person)
{
  return person->name;
}

// 返回字符串
char *person_to_string(Person *person)
{
  char *result = (char *)malloc(500 * sizeof(char));
  strcat(result, "Person :[ name :");
  strcat(result, person->name);
  strcat(result, ", gender : ");
  strcat(result, person->gender);
  strcat(result, ", status : ");
  strcat(result, person->status);
  strcat(result, "]");
  return result;
}

Person *person_constructor(char *name, char *gender, char *status)
{
  Person *person = (Person *)malloc(sizeof(Person));
  strncpy(person->name, name, 50);
  strncpy(person->gender, gender, 20);
  strncpy(person->status, status, 20);
  person->get_name = &person_get_name;
  person->to_string = &person_to_string;
  person->is_contained = &person_is_contained;
  return person;
}