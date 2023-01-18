import { Person } from '../src/Person.js'
import { CriteriaMale } from '../src/CriteriaMale.js'
import { CriteriaFemale } from '../src/CriteriaFemale.js'
import { CriteriaSingle } from '../src/CriteriaSingle.js'
import { AndCriteria } from '../src/AndCriteria.js'
import { OrCriteria } from '../src/OrCriteria.js'

export function test() {
  function printPersons(persons: Person[]) {
    for (const person of persons) {
      console.log(person.toString())
    }
  }

  /**
   * 过滤器模式就是不断组合过滤条件，然后层层过滤的模式
   * TS数组虽然有filter本身非常方便，但这种层层组合过滤的模式还是有意义的。
   */
  const persons: Person[] = []

  persons.push(new Person('王男单', 'Male', 'Single'))
  persons.push(new Person('李男婚', 'Male', 'Married'))
  persons.push(new Person('张女婚', 'Female', 'Married'))
  persons.push(new Person('赵女单', 'Female', 'Single'))
  persons.push(new Person('刘男单', 'Male', 'Single'))
  persons.push(new Person('杨男单', 'Male', 'Single'))

  const male = new CriteriaMale()
  const female = new CriteriaFemale()
  const single = new CriteriaSingle()
  const singleMale = new AndCriteria(single, male)
  const singleOrFemale = new OrCriteria(single, female)

  // 查询男性
  console.log('Males: ')
  printPersons(male.filter(persons))

  // 查询女性
  console.log('\nFemales: ')
  printPersons(female.filter(persons))

  // 嵌套查询女性且单身
  console.log('\nFemales and Single: ')
  printPersons(single.filter(female.filter(persons)))

  // 查询男性男性单身
  console.log('\nSingle Males: ')
  printPersons(singleMale.filter(persons))

  // 查询女性或单身
  console.log('\nSingle Or Females: ')
  printPersons(singleOrFemale.filter(persons))
}

// 执行测试
;(function () {
  console.log('test start:')
  test()
})()
/**
jarry@jarrys-MacBook-Pro ts % tsc -v
Version 4.9.4
jarry@jarrys-MacBook-Pro ts % tsc
// % tsc test/test.ts --charset utf-8 --lib es6,dom,es2020 --target es2020 
// npm run
// jarry@jarrys-MacBook-Pro ts % npm run test
// or node execution
jarry@jarrys-MacBook-Pro ts % node test/test.js
test start:
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
