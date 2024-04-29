## 代码结构
```shell
- src
  - func.c # 头文件，定义接口与类型
  - media_player.c # 媒体基础接口，供具体类实现
  - audio_player.c # 具体实现类之一，负责Audio播放
  - hls_player.c # 具体实现类之一，负责HLS播放
  - mp4_player.c # 具体实现类之一，负责MP4播放
  - player_adapter.c # 适配器类，对外提供接口，队内分发调用。可以实现或不实现基础接口
```

## 测试验证

```shell
$ cd ./adapter-pattern/c
$ gcc src/*.c test/test.c
$ ./a.out
```
