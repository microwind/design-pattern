// 通用视频播放
export interface MediaPlayer {
  play(): void

  setFileType(fileType: string): void

  setFilePath(filePath: string): void
}
