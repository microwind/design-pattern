// 网络模块
export class NetworkModule {
  request() {
    console.log(this.constructor.name + '::request() 远程读取。')
  }
}
