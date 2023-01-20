# -*- coding: utf-8 -*-
"""
@author: jarry
"""

from src.MediaPlayer import MediaPlayer

class HlsPlayer(MediaPlayer):

    def __init__(self, file_type, file_path):
        MediaPlayer.__init__(self, file_type, file_path)

    def play(self, ):
        print('HlsPlayer file_type:' + self.file_type + ' | file_path:' +
              self.file_path)
        print('HlsPlayer::play()')
