import { MediaPlayer } from './MediaPlayer.js'
export class Mp4Player extends MediaPlayer {
  // constructor(fileType, filePath) {
  //   super(fileType, filePath)
  // }

  play() {
    console.log(
      'Mp4Player fileType:' + this.fileType + ' | filePath:' + this.filePath,
    )
    console.log('Mp4Player::play()')
  }
}
