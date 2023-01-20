package src

import (
  "fmt"
)

type Mp4Player struct {
  FileType string
  FilePath string
}

func (m *Mp4Player) SetFileType(fileType string) {
  m.FileType = fileType
}

func (m *Mp4Player) SetFilePath(filePath string) {
  m.FilePath = filePath
}

func (m *Mp4Player) Play() {
  fmt.Println("Mp4Player FileType:" + m.FileType + " | FilePath:" + m.FilePath)
  fmt.Println("Mp4Player::Play()")
}
