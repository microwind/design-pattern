# -*- coding: utf-8 -*-
"""
@author: jarry
"""

from src.VideoPlayer import VideoPlayer


class Mp4Player(VideoPlayer):

    def play(self, ):
        print(
            'Mp4Player file_type:' + self.file_type + ' | file_path:' +
            self.file_path, )
        print('Mp4Player::play()')