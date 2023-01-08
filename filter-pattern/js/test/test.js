import { Person } from '../src/Person.js'
import { CriteriaMale } from '../src/CriteriaMale.js'
import { CriteriaFemale } from '../src/CriteriaFemale.js'
import { CriteriaSingle } from '../src/CriteriaSingle.js'
import { AndCriteria } from '../src/AndCriteria.js'
import { OrCriteria } from '../src/OrCriteria.js'

export function test() {
  function printPersons(persons) {
    for (const person of persons) {
      console.log(
        'Person : [ Name : ' +
          person.getName() +
          ', Gender : ' +
          person.getGender() +
          ', Marital Status : ' +
          person.getStatus() +
          ' ]'
      )
    }
  }

  /**
   * 过滤器模式就是不断组合过滤条件，然后层层过滤的模式
   * 这里是简单演示，其实就是List筛选。JS 数组有filter本身非常方便
   */
  const persons = []

  persons.push(new Person('Robert', 'Male', 'Single'))
  persons.push(new Person('John', 'Male', 'Married'))
  persons.push(new Person('Laura', 'Female', 'Married'))
  persons.push(new Person('Diana', 'Female', 'Single'))
  persons.push(new Person('Mike', 'Male', 'Single'))
  persons.push(new Person('Bobby', 'Male', 'Single'))

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
// npm run
jarry@jarrys-MacBook-Pro js % npm run test
// or node execution
jarry@jarrys-MacBook-Pro js % node test/test.js
test start:
Males: 
Person : [ Name : Robert, Gender : Male, Marital Status : Single ]
Person : [ Name : John, Gender : Male, Marital Status : Married ]
Person : [ Name : Mike, Gender : Male, Marital Status : Single ]
Person : [ Name : Bobby, Gender : Male, Marital Status : Single ]

Females: 
Person : [ Name : Laura, Gender : Female, Marital Status : Married ]
Person : [ Name : Diana, Gender : Female, Marital Status : Single ]

Females and Single: 
Person : [ Name : Diana, Gender : Female, Marital Status : Single ]

Single Males: 
Person : [ Name : Robert, Gender : Male, Marital Status : Single ]
Person : [ Name : Mike, Gender : Male, Marital Status : Single ]
Person : [ Name : Bobby, Gender : Male, Marital Status : Single ]

Single Or Females: 
Person : [ Name : Robert, Gender : Male, Marital Status : Single ]
Person : [ Name : Diana, Gender : Female, Marital Status : Single ]
Person : [ Name : Mike, Gender : Male, Marital Status : Single ]
Person : [ Name : Bobby, Gender : Male, Marital Status : Single ]
Person : [ Name : Laura, Gender : Female, Marital Status : Married ]
*/
