package src;

import java.util.*;

// 根据标准接口实现按属性的过滤
public class CriteriaSingle implements Criteria {

   @Override
   public List<Person> filter(List<Person> persons) {
      List<Person> singlePersons = new ArrayList<Person>();
      for (Person person : persons) {
         if (person.getStatus().equalsIgnoreCase("SINGLE")) {
            singlePersons.add(person);
         }
      }
      return singlePersons;
   }
}