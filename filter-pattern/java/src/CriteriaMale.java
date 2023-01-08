package src;

import java.util.*;

// 根据标准接口实现的过滤
public class CriteriaMale implements Criteria {

   @Override
   public List<Person> filter(List<Person> persons) {
      List<Person> malePersons = new ArrayList<Person>();
      for (Person person : persons) {
         if (person.getGender().equalsIgnoreCase("MALE")) {
            malePersons.add(person);
         }
      }
      return malePersons;
   }
}