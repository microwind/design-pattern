package src

import "fmt"

// 文件模块
type FileModule struct {
}

func (f *FileModule) ReadFile() {
  fmt.Println("FileModule::ReadFile() 读取文件。")
}

func (f *FileModule) SaveFile() {
  fmt.Println("FileModule::SaveFile() 保存文件。")
}
