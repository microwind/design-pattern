import { OrganizationComponent } from './OrganizationComponent.js'

// 实现部件的树枝构件1
export class CompanyComposite extends OrganizationComponent {
  constructor(name) {
    super(name)
    this.children = []
  }

  operation() {
    console.log(this.constructor.name + '::operation() ' + this.name)
    for (const component of this.children) {
      component.operation()
    }
  }

}
