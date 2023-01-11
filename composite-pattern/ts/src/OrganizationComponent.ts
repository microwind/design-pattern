// 定义部件接口或抽象类，分支和叶子节点遵循该类约定
export abstract class OrganizationComponent {
  name: string
  children: OrganizationComponent[]
  constructor(name: string) {
    this.setName(name)
  }

  add(component: OrganizationComponent) {
    this.children.push(component)
  }

  remove(component: OrganizationComponent) {
    // 根据名称或删除成员
    for (let i = 0, l = this.children.length; i < l; i++) {
      if (this.children[i].getName() === component.getName()) {
        this.children.splice(i, 1)
        break
      }
    }
  }

  abstract getChild(index: number): OrganizationComponent | any

  abstract operation(): void

  setName(name: string) {
    this.name = name
  }

  getName() {
    return this.name
  }
}
