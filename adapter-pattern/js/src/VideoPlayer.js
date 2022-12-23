// 通用视频播放
export class VideoPlayer {
  constructor(fileType, filePath) {
    this.fileType = fileType
    this.filePath = filePath
  }

  play() {
    console.log('VideoPlayer fileType:' + this.fileType + ' | filePath:' + this.filePath)
    console.log('VideoPlayer::play()')
  }

  setFileType(fileType) {
    this.fileType = fileType
  }

  setFilePath(filePath) {
    this.filePath = filePath
  }
}
