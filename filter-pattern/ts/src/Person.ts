// 定义一个实体类，用来过滤的对象
export class Person {
  name: string
  gender: string
  status: string
  constructor(name: string, gender: string, status: string) {
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
}
