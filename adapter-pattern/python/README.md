## 代码结构
```shell
- src
  - MediaPlayer.py # 媒体基础类，供具体类继承
  - AudioPlayer.py # 具体实现类之一，负责Audio播放
  - HlsPlayer.py # 具体实现类之一，负责HLS播放
  - Mp4Player.py # 具体实现类之一，负责MP4播放
  - PlayerAdapter.py # 适配器类，对外提供接口，队内分发调用。可以实现或不实现基础接口
```

## 测试验证

```shell
$ cd ./adapter-pattern/python
$ python test/test.py 
```
