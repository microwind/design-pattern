export class CriteriaSingle {
    filter(persons) {
        const singlePersons = [];
        for (const person of persons) {
            if (person.getStatus().toUpperCase() === 'SINGLE') {
                singlePersons.push(person);
            }
        }
        return singlePersons;
    }
}
