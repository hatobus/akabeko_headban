# coding:utf-8
import pygame.mixer as game
import time

game.init()
game.music.load('akabeko1.mp3')
game.music.play(1)

print "音量:%s" % game.music.get_volume() #ボリュームの取得
print "再生時間:%s[ms]"% game.music.get_busy() # 再生時間の取得[ms]

time.sleep(30)
game.music.stop() # 再生の終了
print "終了"
