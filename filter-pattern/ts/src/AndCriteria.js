export class AndCriteria {
    constructor(criteria, otherCriteria) {
        this.criteria = criteria;
        this.otherCriteria = otherCriteria;
    }
    filter(persons) {
        const firstCriteriaPersons = this.criteria.filter(persons);
        return this.otherCriteria.filter(firstCriteriaPersons);
    }
}
