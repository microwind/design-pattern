import { AbstractUser } from './AbstractUser.js'

// 继承基础类的普通用户
export class CommonUser extends AbstractUser {
  constructor(name) {
    super(name)
  }
}
