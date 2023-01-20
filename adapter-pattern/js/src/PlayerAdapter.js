import { MediaPlayer } from './MediaPlayer.js'
import { HlsPlayer } from './HlsPlayer.js'
import { Mp4Player } from './Mp4Player.js'
import { AudioPlayer } from './AudioPlayer.js'

// 适配器类，可以播放各种音频和视频，外部调用方式一样。适配器继承基类可选。
// export class PlayerAdapter extends MediaPlayer {
export class PlayerAdapter {
  constructor(mediaType, fileType, filePath) {
    // super(fileType, filePath)
    this.mediaType = mediaType
    this.fileType = fileType
    this.mp4Player = null
    this.hlsPlayer = null
    this.audioPlayer = null
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

  setMp4Player(fileType, filePath) {
    if (!this.mp4Player) {
      this.mp4Player = new Mp4Player(fileType, filePath)
    } else {
      this.mp4Player.setFileType(fileType)
      this.mp4Player.setFilePath(filePath)
    }
  }

  setHlsPlayer(fileType, filePath) {
    if (!this.hlsPlayer) {
      this.hlsPlayer = new HlsPlayer(fileType, filePath)
    } else {
      this.hlsPlayer.setFileType(fileType)
      this.hlsPlayer.setFilePath(filePath)
    }
  }

  setAudioPlayer(fileType, filePath) {
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
  playBy(mediaType, fileType, filePath) {
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
}
