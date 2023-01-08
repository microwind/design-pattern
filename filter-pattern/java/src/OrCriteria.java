package src;

import java.util.*;

// 定义Or过滤标准
public class OrCriteria implements Criteria {

   private Criteria criteria;
   private Criteria otherCriteria;

   public OrCriteria(Criteria criteria, Criteria otherCriteria) {
      this.criteria = criteria;
      this.otherCriteria = otherCriteria;
   }

   @Override
   public List<Person> filter(List<Person> persons) {
      List<Person> firstCriteriaItems = criteria.filter(persons);
      List<Person> otherCriteriaItems = otherCriteria.filter(persons);

      for (Person person : otherCriteriaItems) {
         if (!firstCriteriaItems.contains(person)) {
            firstCriteriaItems.add(person);
         }
      }
      return firstCriteriaItems;
   }
}