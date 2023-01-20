package src

// 通用视频播放接口
type MediaPlayer interface {
  Play()
  SetFileType(fileType string)
  SetFilePath(filePath string)
}
