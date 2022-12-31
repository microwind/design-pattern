import { OrganizationComponent } from './OrganizationComponent.js'

// 实现部件的树枝构件2
export class DepartmentComposite extends OrganizationComponent {
  constructor(name) {
    super(name)
    this.children = []
  }
}
