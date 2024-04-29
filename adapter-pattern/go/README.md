## 代码结构
```shell
- src
  - MediaPlayer.go # 媒体基础接口，供具体类实现
  - AudioPlayer.go # 具体实现类之一，负责Audio播放。
  - HlsPlayer.go # 具体实现类之一，负责HLS播放。
  - Mp4Player.go # 具体实现类之一，负责MP4播放。
  - PlayerAdapter.go # 适配器类，对外提供接口，队内分发调用。可以实现或不实现基础接口。
```

## 测试验证

```shell
$ cd ./adapter-pattern/go
$ go run test/test.go
```
