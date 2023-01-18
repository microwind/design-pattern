package src

// 定义部件接口或抽象类，分支和叶子节点遵循该类约定
type OrganizationComponent interface {
  Add(component OrganizationComponent)

  Remove(component OrganizationComponent)

  GetChild(index int) OrganizationComponent

  Operation()

  GetName() string
}
