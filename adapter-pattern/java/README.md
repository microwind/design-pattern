## 代码结构
```shell
- src
  - MediaPlayer.java # 媒体基础接口，供具体类实现
  - AudioPlayer.java # 具体实现类之一，负责Audio播放
  - HlsPlayer.java # 具体实现类之一，负责HLS播放
  - Mp4Player.java # 具体实现类之一，负责MP4播放
  - PlayerAdapter.java # 适配器类，对外提供接口，队内分发调用。可以实现或不实现基础接口
```

## 测试验证

```shell
$ cd ./adapter-pattern/java
$ javac test/Test.java
$ java test/Test
```
