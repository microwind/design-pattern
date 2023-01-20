package src

import (
  "fmt"
)

type HlsPlayer struct {
  FileType string
  FilePath string
}

func (h *HlsPlayer) SetFileType(fileType string) {
  h.FileType = fileType
}

func (h *HlsPlayer) SetFilePath(filePath string) {
  h.FilePath = filePath
}

func (h *HlsPlayer) Play() {
  fmt.Println("HlsPlayer FileType:" + h.FileType + " | FilePath:" + h.FilePath)
  fmt.Println("HlsPlayer::Play()")
}
