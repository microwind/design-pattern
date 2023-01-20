package src

// 适配器类，可以播放各种音频和视频，外部调用方式一样。
type PlayerAdapter struct {
  MediaType string
  FileType  string

  mp4Player   MediaPlayer
  hlsPlayer   MediaPlayer
  audioPlayer MediaPlayer
}

// 模拟构造函数，初始化时声明具体播放器
func (p *PlayerAdapter) Init(mediaType string, fileType string, filePath string) {
  p.MediaType = mediaType
  p.FileType = fileType
  if mediaType == "video" {
    if fileType == "mp4" {
      p.SetMp4Player(fileType, filePath)
    } else if fileType == "hls" {
      p.SetHlsPlayer(fileType, filePath)
    }
  } else if mediaType == "audio" {
    p.SetAudioPlayer(fileType, filePath)
  }
}

func (p *PlayerAdapter) SetMp4Player(fileType string, filePath string) {
  if p.mp4Player == nil {
    p.mp4Player = &Mp4Player{
      FileType: fileType,
      FilePath: filePath,
    }
  } else {
    p.mp4Player.SetFileType(fileType)
    p.mp4Player.SetFilePath(filePath)
  }
}

func (p *PlayerAdapter) SetHlsPlayer(fileType string, filePath string) {
  if p.hlsPlayer == nil {
    p.hlsPlayer = &HlsPlayer{
      FileType: fileType,
      FilePath: filePath,
    }
  } else {
    p.hlsPlayer.SetFileType(fileType)
    p.hlsPlayer.SetFilePath(filePath)
  }
}

func (p *PlayerAdapter) SetAudioPlayer(fileType string, filePath string) {
  if p.audioPlayer == nil {
    p.audioPlayer = &AudioPlayer{
      FileType: fileType,
      FilePath: filePath,
    }
  } else {
    p.audioPlayer.SetFileType(fileType)
    p.audioPlayer.SetFilePath(filePath)
  }
}

// 通用的适配接口
func (p *PlayerAdapter) Play() {
  if p.MediaType == "audio" {
    p.audioPlayer.Play()
  } else if p.MediaType == "video" {
    if p.FileType == "mp4" {
      p.mp4Player.Play()
    } else if p.FileType == "hls" {
      p.hlsPlayer.Play()
    }
  }
}

// 根据路径播放，可根据需要复用实例
func (p *PlayerAdapter) PlayBy(mediaType string, fileType string, filePath string) {
  if mediaType == "audio" {
    p.SetAudioPlayer(fileType, filePath)
    p.audioPlayer.Play()
  } else if mediaType == "video" {
    if fileType == "mp4" {
      p.SetMp4Player(fileType, filePath)
      p.mp4Player.Play()
    } else if fileType == "hls" {
      p.SetHlsPlayer(fileType, filePath)
      p.hlsPlayer.Play()
    }
  }
}
