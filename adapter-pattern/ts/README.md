## 代码结构
```shell
- src
  - MediaPlayer.ts # 媒体基础接口，供具体类继承
  - AudioPlayer.ts # 具体实现类之一，负责Audio播放
  - HlsPlayer.ts # 具体实现类之一，负责HLS播放
  - Mp4Player.ts # 具体实现类之一，负责MP4播放
  - PlayerAdapter.ts # 适配器类，对外提供接口，队内分发调用。可以实现或不实现基础接口
```

## 测试验证

```shell
$ cd ./adapter-pattern/ts
$ tsc
$ node test/test.js
```
