import { MediaPlayer } from './MediaPlayer.js'
export class Mp4Player implements MediaPlayer {
  fileType: string;
  filePath: string;

  constructor(fileType: string, filePath: string) {
    this.fileType = fileType
    this.filePath = filePath
  }

  play() {
    console.log(
      'Mp4Player fileType:' + this.fileType + ' | filePath:' + this.filePath,
    )
    console.log('Mp4Player::play()')
  }
  setFileType(fileType: string) {
    this.fileType = fileType;
  }

  setFilePath(filePath: string) {
    this.filePath = filePath;
  }
}
