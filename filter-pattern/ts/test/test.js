import { Person } from '../src/Person.js';
import { CriteriaMale } from '../src/CriteriaMale.js';
import { CriteriaFemale } from '../src/CriteriaFemale.js';
import { CriteriaSingle } from '../src/CriteriaSingle.js';
import { AndCriteria } from '../src/AndCriteria.js';
import { OrCriteria } from '../src/OrCriteria.js';
export function test() {
    function printPersons(persons) {
        for (const person of persons) {
            console.log('Person : [ Name : ' +
                person.getName() +
                ', Gender : ' +
                person.getGender() +
                ', Marital Status : ' +
                person.getStatus() +
                ' ]');
        }
    }
    const persons = [];
    persons.push(new Person('Robert', 'Male', 'Single'));
    persons.push(new Person('John', 'Male', 'Married'));
    persons.push(new Person('Laura', 'Female', 'Married'));
    persons.push(new Person('Diana', 'Female', 'Single'));
    persons.push(new Person('Mike', 'Male', 'Single'));
    persons.push(new Person('Bobby', 'Male', 'Single'));
    const male = new CriteriaMale();
    const female = new CriteriaFemale();
    const single = new CriteriaSingle();
    const singleMale = new AndCriteria(single, male);
    const singleOrFemale = new OrCriteria(single, female);
    console.log('Males: ');
    printPersons(male.filter(persons));
    console.log('\nFemales: ');
    printPersons(female.filter(persons));
    console.log('\nFemales and Single: ');
    printPersons(single.filter(female.filter(persons)));
    console.log('\nSingle Males: ');
    printPersons(singleMale.filter(persons));
    console.log('\nSingle Or Females: ');
    printPersons(singleOrFemale.filter(persons));
}
;
(function () {
    console.log('test start:');
    test();
})();
