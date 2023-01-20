package src

import (
  "fmt"
)

// 音频播放器
type AudioPlayer struct {
  FileType string
  FilePath string
}

func (a *AudioPlayer) SetFileType(fileType string) {
  a.FileType = fileType
}

func (a *AudioPlayer) SetFilePath(filePath string) {
  a.FilePath = filePath
}

func (a *AudioPlayer) Play() {
  fmt.Println("AudioPlayer FileType:" + a.FileType + " | FilePath:" + a.FilePath)
  fmt.Println("AudioPlayer::Play()")
  if a.FileType == "mp3" {
    fmt.Println("AudioPlayer::Play() mp3")
  } else if a.FileType == "mp4" {
    fmt.Println("AudioPlayer::Play() mp4")
  }
}
