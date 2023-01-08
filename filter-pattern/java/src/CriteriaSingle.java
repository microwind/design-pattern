package src;

import java.util.*;

// 定义子类覆写父类抽象方法
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