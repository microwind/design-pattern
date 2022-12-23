# -*- coding: utf-8 -*-
"""
@author: jarry
"""

from src.VideoPlayer import VideoPlayer

class HlsPlayer(VideoPlayer):

    def __init__(self, file_type, file_path):
        VideoPlayer.__init__(self, file_type, file_path)

    def play(self, ):
        print(
            'HlsPlayer file_type:' + self.file_type + ' | file_path:' +
            self.file_path, )
        print('HlsPlayer::play()')
