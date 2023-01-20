import { MediaPlayer } from './MediaPlayer.js'
import { HlsPlayer } from './HlsPlayer.js'
import { Mp4Player } from './Mp4Player.js'
import { AudioPlayer } from './AudioPlayer.js'

// 适配器类，可以播放各种音频和视频，外部调用方式一样。
// 适配器是否实现基础接口可选。
export class PlayerAdapter implements MediaPlayer {
  // export class PlayerAdapter {
  mediaType: string
  filePath: string = ''
  fileType: string
  mp4Player: Mp4Player | any
  hlsPlayer: HlsPlayer | any
  audioPlayer: AudioPlayer | any
  constructor(mediaType: string, fileType: string, filePath: string) {
    this.mediaType = mediaType
    this.fileType = fileType
    if (mediaType === 'video') {
      if (fileType === 'mp4') {
        this.setMp4Player(fileType, filePath)
      } else if (fileType === 'hls') {
        this.setHlsPlayer(fileType, filePath)
      }
    } else if (mediaType === 'audio') {
      this.setAudioPlayer(fileType, filePath)
    }
  }

  setMp4Player(fileType: string, filePath: string) {
    if (!this.mp4Player) {
      this.mp4Player = new Mp4Player(fileType, filePath)
    } else {
      this.mp4Player.setFileType(fileType)
      this.mp4Player.setFilePath(filePath)
    }
  }

  setHlsPlayer(fileType: string, filePath: string) {
    if (!this.hlsPlayer) {
      this.hlsPlayer = new HlsPlayer(fileType, filePath)
    } else {
      this.hlsPlayer.setFileType(fileType)
      this.hlsPlayer.setFilePath(filePath)
    }
  }

  setAudioPlayer(fileType: string, filePath: string) {
    if (!this.audioPlayer) {
      this.audioPlayer = new AudioPlayer(fileType, filePath)
    } else {
      this.audioPlayer.setFileType(fileType)
      this.audioPlayer.setFilePath(filePath)
    }
  }

  // 通用的适配接口
  play() {
    if (this.mediaType === 'audio') {
      this.audioPlayer.play()
    } else if (this.mediaType === 'video') {
      if (this.fileType === 'mp4') {
        this.mp4Player.play()
      } else if (this.fileType === 'hls') {
        this.hlsPlayer.play()
      }
    }
  }

  // 根据路径播放，可根据需要复用实例
  playBy(mediaType: string, fileType: string, filePath: string) {
    if (mediaType === 'audio') {
      this.setAudioPlayer(fileType, filePath)
      this.audioPlayer.play()
    } else if (mediaType === 'video') {
      if (fileType === 'mp4') {
        this.setMp4Player(fileType, filePath)
        this.mp4Player.play()
      } else if (fileType === 'hls') {
        this.setHlsPlayer(fileType, filePath)
        this.hlsPlayer.play()
      }
    }
  }

  setFileType(fileType: string) {
    this.fileType = fileType
  }

  setFilePath(filePath: string) {
    this.filePath = filePath
  }
}
