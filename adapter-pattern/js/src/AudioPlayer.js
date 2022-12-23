// 音频播放器
export class AudioPlayer {
  constructor(fileType, filePath) {
    this.fileType = fileType
    this.filePath = filePath
  }

  play() {
    console.log(
      'AudioPlayer fileType:' + this.fileType + ' | filePath:' + this.filePath,
    )
    console.log('AudioPlayer::play()')
    if (this.fileType === 'mp3') {
      console.log('AudioPlayer::play() mp3')
    } else if (this.fileType === 'mp4') {
      console.log('AudioPlayer::play() mp4')
    }
  }

  setFileType(fileType) {
    this.fileType = fileType
  }

  setFilePath(filePath) {
    this.filePath = filePath
  }
}
