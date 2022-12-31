import { OrganizationComponent } from './OrganizationComponent.js'

// 实现部件的叶子节点，叶子节点不能再含有子节点
export class EmployeeLeaf extends OrganizationComponent {
  constructor(name) {
    super(name)
  }

  // 叶子节点不能再增加内容
  add() {
    console.log("Leaf can't add.")
  }

  // 叶子节点没有移除内容
  remove() {
    console.log("Leaf can't remove.")
  }

  // 叶子节点无获取子节点
  getChild() {
    console.log("Leaf can't getChild.")
    return null
  }

  operation() {
    console.log(
      this.constructor.name + ' EmployeeLeaf::operation() ' + this.name
    )
  }
}
