import { MediaPlayer } from './MediaPlayer.js'
export class HlsPlayer implements MediaPlayer {
  fileType: string;
  filePath: string;

  constructor(fileType: string, filePath: string) {
    this.fileType = fileType
    this.filePath = filePath
  }
  play() {
    console.log(
      'HlsPlayer fileType:' + this.fileType + ' | filePath:' + this.filePath,
    )
    console.log('HlsPlayer::play()')
  }
  setFileType(fileType: string) {
    this.fileType = fileType;
  }

  setFilePath(filePath: string) {
    this.filePath = filePath;
  }
}
