// 定义一个实体类，用来过滤的对象
export class Person {
  constructor(name, gender, status) {
    this.name = name
    this.gender = gender
    this.status = status
  }

  getName() {
    return this.name
  }

  getGender() {
    return this.gender
  }

  getStatus() {
    return this.status
  }

  toString() {
    return 'Person : [ Name : ' +
      this.getName() +
      ', Gender : ' +
      this.getGender() +
      ', Marital Status : ' +
      this.getStatus() +
      ' ]'
  }
}