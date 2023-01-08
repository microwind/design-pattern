package src;

import java.util.*;

// 定义And过滤标准
public class AndCriteria implements Criteria {

   private Criteria criteria;
   private Criteria otherCriteria;

   public AndCriteria(Criteria criteria, Criteria otherCriteria) {
      this.criteria = criteria;
      this.otherCriteria = otherCriteria;
   }

   @Override
   public List<Person> filter(List<Person> persons) {
      List<Person> firstCriteriaPersons = criteria.filter(persons);
      return otherCriteria.filter(firstCriteriaPersons);
   }
}