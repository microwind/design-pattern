package src;

import java.util.*;

// 根据标准接口实现的过滤
public class CriteriaFemale implements Criteria {

  @Override
  public List<Person> filter(List<Person> persons) {
    List<Person> femalePersons = new ArrayList<Person>();
    for (Person person : persons) {
      if (person.getGender().equalsIgnoreCase("FEMALE")) {
        femalePersons.add(person);
      }
    }
    return femalePersons;
  }
}