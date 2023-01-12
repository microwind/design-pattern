// 文件模块
export class FileModule {
  readFile() {
    console.log(this.constructor.name + '::readFile() 读取文件。')
  }

  saveFile() {
    console.log(this.constructor.name + '::saveFile() 保存文件。')
  }
}
