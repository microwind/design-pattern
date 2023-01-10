export class OrCriteria {
    constructor(criteria, otherCriteria) {
        this.criteria = criteria;
        this.otherCriteria = otherCriteria;
    }
    filter(persons) {
        const firstCriteriaItems = this.criteria.filter(persons);
        const otherCriteriaItems = this.otherCriteria.filter(persons);
        for (const person of otherCriteriaItems) {
            if (!firstCriteriaItems.includes(person)) {
                firstCriteriaItems.push(person);
            }
        }
        return firstCriteriaItems;
    }
}
