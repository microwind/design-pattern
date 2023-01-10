export class CriteriaFemale {
    filter(persons) {
        const femalePersons = [];
        for (const person of persons) {
            if (person.getGender().toUpperCase() === 'FEMALE') {
                femalePersons.push(person);
            }
        }
        return femalePersons;
    }
}
