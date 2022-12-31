// 定义部件接口或抽象类，分支和叶子节点遵循该类约定
export class OrganizationComponent {
  constructor(name) {
    this.setName(name)
  }

  add(component) {
    this.children.push(component)
  }

  remove(component) {
    // 根据名称或删除成员
    for (let i = 0, l = this.children.length; i < l; i++) {
      if (this.children[i].getName() === component.getName()) {
        this.children.splice(i, 1)
        break
      }
    }
  }

  getChild(index) {
    return this.children[index]
  }

  operation() {
    console.log(this.constructor.name + '::operation() ' + this.name)
    for (const component of this.children) {
      component.operation()
    }
  }

  setName(name) {
    this.name = name
  }

  getName() {
    return this.name
  }
}
