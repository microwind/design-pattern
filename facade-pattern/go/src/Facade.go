package src

import (
  "fmt"
  "strconv"
)

// 外观模式实现类，是外部调用与内部子系统的衔接层
type Facade struct {
  fileModule    *FileModule
  networkModule *NetworkModule
  encodeModule  *EncodeModule
}

func (f *Facade) Encoding(id int) {
  fmt.Println("Facade::Encoding() [id=" + strconv.Itoa(id) + "]")
  f.networkModule.Request()
  f.fileModule.ReadFile()
  f.encodeModule.Encoding()
  f.fileModule.SaveFile()
}

func (f *Facade) Encrypt(id int) {
  fmt.Println("Facade::Encrypt() [id=" + strconv.Itoa(id) + "]")
  f.fileModule.ReadFile()
  f.encodeModule.Encoding()
}

func (f *Facade) GetFileModule() *FileModule {
  return f.fileModule
}

func (f *Facade) GetNetworkModule() *NetworkModule {
  return f.networkModule
}

func (f *Facade) GetEncodeModule() *EncodeModule {
  return f.encodeModule
}
