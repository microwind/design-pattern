import { MediaPlayer } from './MediaPlayer.js'
export class HlsPlayer extends MediaPlayer {
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
