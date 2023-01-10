import { Person } from './Person.js'

// 定义抽象标准接口，聚合实体对象
export interface Criteria {
  filter(persons: Person[]): Person[];
}
