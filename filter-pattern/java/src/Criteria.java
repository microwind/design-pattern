package src;

import java.util.*;

// 定义抽象标准接口，聚合实体对象
public interface Criteria {
   public List<Person> filter(List<Person> persons);
}