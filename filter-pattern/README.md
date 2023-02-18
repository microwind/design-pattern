# 【过滤器设计模式详解】Java/JS/Go/Python/TS不同语言实现

# 简介
过滤器模式（Filter Pattern）或标准模式（Criteria Pattern），是一种结构型模式。这种模式允许使用不同的标准条件来过滤一组对象，并通过逻辑运算的方式把各条件连接起来，它结合多个标准来获得单一标准。

例子将创建一个 Person 对象、Criteria 接口和实现了该接口的实体类，来过滤 Person 对象的列表。Test 类使用 Criteria 对象，基于各种标准和它们的结合来过滤 Person 对象的列表。

# 作用
1. 可以通过层层筛选，过滤出自己想要的结果。
2. 面向接口编程，将对象过滤，接口不依赖对象；对象无入侵，每次只需要增加规则就行了，不用修改过滤对象类。

# 实现步骤
1. 创建Criteria基础接口，定义过滤方法。
2. 创建多个条件类，实现过滤逻辑。
3. 客户端调用时，通条件类过滤数据。

# UML
<img src="../docs/uml/filter-pattern.png">

# 代码

## 标准接口类
```java
// Criteria.java 定义抽象标准接口，聚合实体对象
public interface Criteria {
   public List<Person> filter(List<Person> persons);
}
```

## 具体标准实现类

```java
// AndCriteria.java 定义And过滤标准
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
```

```java
// OrCriteria.java 定义Or过滤标准
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
```

```java
// CriteriaFemale.java 根据标准接口实现的过滤
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
```

```java
// CriteriaMale.java 根据标准接口实现的过滤
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
```

```java
// CriteriaSingle.java 根据标准接口实现按属性的过滤
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
```

## 业务实体类
```java
// Person.java 定义一个实体类，用来过滤的对象
public class Person {

   private String name;
   private String gender;
   private String status;

   public Person(String name, String gender, String status) {
      this.name = name;
      this.gender = gender;
      this.status = status;
   }

   public String getName() {
      return name;
   }

   public String getGender() {
      return gender;
   }

   public String getStatus() {
      return status;
   }

   public String toString() {
      return "Person : [ Name : " + getName() + ", Gender : "
            + getGender() + ", Marital Status : " + getStatus() + " ]";
   }
}
```

## 测试调用
```java
    /**
     * 过滤器模式就是不断组合过滤条件，然后层层过滤的模式
     * 这里是简单演示，用List筛选来模拟过滤，实际例子有各种数据结构
     */
    List<Person> persons = new ArrayList<Person>();

    persons.add(new Person("王男单", "Male", "Single"));
    persons.add(new Person("李男婚", "Male", "Married"));
    persons.add(new Person("张女婚", "Female", "Married"));
    persons.add(new Person("赵女单", "Female", "Single"));
    persons.add(new Person("刘男单", "Male", "Single"));
    persons.add(new Person("杨男单", "Male", "Single"));

    Criteria male = new CriteriaMale();
    Criteria female = new CriteriaFemale();
    Criteria single = new CriteriaSingle();
    Criteria singleMale = new AndCriteria(single, male);
    Criteria singleOrFemale = new OrCriteria(single, female);

    // 查询男性
    System.out.println("Males: ");
    printPersons(male.filter(persons));

    // 查询女性
    System.out.println("\nFemales: ");
    printPersons(female.filter(persons));

    // 嵌套查询女性且单身
    System.out.println("\nFemales and Single: ");
    printPersons(single.filter(female.filter(persons)));

    // 查询男性男性单身
    System.out.println("\nSingle Males: ");
    printPersons(singleMale.filter(persons));

    // 查询女性或单身
    System.out.println("\nSingle Or Females: ");
    printPersons(singleOrFemale.filter(persons));
```
## 更多语言版本
不同语言实现设计模式：[https://github.com/microwind/design-pattern](https://github.com/microwind/design-pattern)