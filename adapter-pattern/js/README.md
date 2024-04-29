## 代码结构
```shell
- src
  - MediaPlayer.js # 媒体基础类，供具体类继承
  - AudioPlayer.js # 具体实现类之一，负责Audio播放
  - HlsPlayer.js # 具体实现类之一，负责HLS播放
  - Mp4Player.js # 具体实现类之一，负责MP4播放
  - PlayerAdapter.js # 适配器类，对外提供接口，队内分发调用。可以实现或不实现基础接口
```

## 测试验证

```shell
$ cd ./adapter-pattern/js
$ node test/test.js
```
