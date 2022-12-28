// 通用视频播放
export class MediaPlayer {
  constructor(fileType, filePath) {
    this.fileType = fileType
    this.filePath = filePath
  }

  play() {
    console.log('MediaPlayer fileType:' + this.fileType + ' | filePath:' + this.filePath)
    console.log('MediaPlayer::play()')
  }

  setFileType(fileType) {
    this.fileType = fileType
  }

  setFilePath(filePath) {
    this.filePath = filePath
  }
}
