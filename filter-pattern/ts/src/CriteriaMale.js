export class CriteriaMale {
    filter(persons) {
        const malePersons = new Array();
        for (const person of persons) {
            if (person.getGender().toUpperCase() === 'MALE') {
                malePersons.push(person);
            }
        }
        return malePersons;
    }
}
