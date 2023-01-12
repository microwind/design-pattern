// 外观模式的接口或抽象类，可选
export interface AbstractFacade {
  encoding(id: number): void

  encrypt(id: number): void
}
