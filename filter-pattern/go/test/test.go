package main

import (
  "fmt"

  "../src"
)

func printPersons(persons []*src.Person) {
  for _, person := range persons {
    fmt.Println(person.ToString())
  }
}

// main包下的main入口方法
func main() {
  fmt.Println("test start:")

  /**
   * 过滤器模式就是不断组合过滤条件，然后层层过滤的模式
   * 这里是简单演示，用List筛选来模拟过滤，实际例子有各种数据结构。
   * JS 数组虽然有filter本身非常方便，但这种层层组合过滤的模式还是有意义的。
   */

  // 定义Person数组切片
  var persons []*src.Person
  // 填充一些数据
  persons = append(persons, src.CreatePerson("王男单", "Male", "Single"))
  persons = append(persons, src.CreatePerson("李男婚", "Male", "Married"))
  persons = append(persons, src.CreatePerson("张女婚", "Female", "Married"))
  persons = append(persons, src.CreatePerson("赵女单", "Female", "Single"))
  persons = append(persons, src.CreatePerson("刘男单", "Male", "Single"))
  persons = append(persons, src.CreatePerson("杨男单", "Male", "Single"))

  // 声明属性过滤条件
  var male = new(src.CriteriaMale)
  var female = new(src.CriteriaFemale)
  var single = new(src.CriteriaSingle)

  // 声明逻辑条件，传入属性过滤条件
  var singleMale = &src.AndCriteria{
    FirstCriteria: single,
    OtherCriteria: male,
  }
  var singleOrFemale = &src.OrCriteria{
    FirstCriteria: single,
    OtherCriteria: female,
  }

  // 查询男性
  fmt.Println("Males: ")
  printPersons(male.Filter(persons))

  // 查询女性
  fmt.Println("\nFemales: ")
  printPersons(female.Filter(persons))

  // 嵌套查询女性且单身
  fmt.Println("\nFemales and Single: ")
  printPersons(single.Filter(female.Filter(persons)))

  // 查询男性男性单身
  fmt.Println("\nSingle Males: ")
  printPersons(singleMale.Filter(persons))

  // 查询女性或单身
  fmt.Println("\nSingle Or Females: ")
  printPersons(singleOrFemale.Filter(persons))
}

/**
// npm run
jarry@jarrys-MacBook-Pro js % npm run test
// or node execution
jarry@jarrys-MacBook-Pro js % node test/test.js
test start:
Males:
Males:
Person : [ Name : 王男单, Gender : Male, Marital Status : Single ]
Person : [ Name : 李男婚, Gender : Male, Marital Status : Married ]
Person : [ Name : 刘男单, Gender : Male, Marital Status : Single ]
Person : [ Name : 杨男单, Gender : Male, Marital Status : Single ]

Females:
Person : [ Name : 张女婚, Gender : Female, Marital Status : Married ]
Person : [ Name : 赵女单, Gender : Female, Marital Status : Single ]

Females and Single:
Person : [ Name : 赵女单, Gender : Female, Marital Status : Single ]

Single Males:
Person : [ Name : 王男单, Gender : Male, Marital Status : Single ]
Person : [ Name : 刘男单, Gender : Male, Marital Status : Single ]
Person : [ Name : 杨男单, Gender : Male, Marital Status : Single ]

Single Or Females:
Person : [ Name : 王男单, Gender : Male, Marital Status : Single ]
Person : [ Name : 赵女单, Gender : Female, Marital Status : Single ]
Person : [ Name : 刘男单, Gender : Male, Marital Status : Single ]
Person : [ Name : 杨男单, Gender : Male, Marital Status : Single ]
Person : [ Name : 张女婚, Gender : Female, Marital Status : Married ]
*/
