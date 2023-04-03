// 定义部件接口或抽象类，分支和叶子节点遵循该类约定
export class OrganizationComponent {
  constructor(name) {
    this.setName(name)
  }

  add(component) {
    this.children.push(component)
  }

  remove(component) {
    for (let i = 0, l = this.children.length; i < l; i++) {
      if (this.children[i] === component) {
      // 根据名称id或直接比较对象
      // if (this.children[i].getName() === component.getName()) {
        this.children.splice(i, 1)
        break
      }
    }
  }

  getChild(index) {
    return this.children[index]
  }

  // operation() {}

  setName(name) {
    this.name = name
  }

  getName() {
    return this.name
  }
}
