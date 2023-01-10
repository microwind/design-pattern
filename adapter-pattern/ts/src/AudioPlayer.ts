import { MediaPlayer } from './MediaPlayer.js'

// 音频播放器
export class AudioPlayer implements MediaPlayer {
  fileType: string
  filePath: string

  constructor(fileType: string, filePath: string) {
    this.fileType = fileType
    this.filePath = filePath
  }

  play() {
    console.log(
      'AudioPlayer fileType:' + this.fileType + ' | filePath:' + this.filePath
    )
    console.log('AudioPlayer::play()')
    if (this.fileType === 'mp3') {
      console.log('AudioPlayer::play() mp3')
    } else if (this.fileType === 'mp4') {
      console.log('AudioPlayer::play() mp4')
    }
  }

  setFileType(fileType: string) {
    this.fileType = fileType
  }

  setFilePath(filePath: string) {
    this.filePath = filePath
  }
}
