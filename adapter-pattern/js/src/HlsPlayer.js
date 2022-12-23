import { VideoPlayer } from './VideoPlayer.js'
export class HlsPlayer extends VideoPlayer {
  // constructor(fileType, filePath) {
  //   super(fileType, filePath)
  // }

  play() {
    console.log(
      'HlsPlayer fileType:' + this.fileType + ' | filePath:' + this.filePath,
    )
    console.log('HlsPlayer::play()')
  }
}
