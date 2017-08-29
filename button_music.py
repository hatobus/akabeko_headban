# coding:utf-8
import pygame.mixer as game,time,RPi.GPIO as GPIO

GPIO.setmode(GPIO.BCM)

GPIO.setup(2,GPIO.IN)

game.init()
game.music.load('akabeko1.mp3')

try:
	while True:
		print GPIO.input(2)
		if GPIO.input(2) == GPIO.HIGH:
			game.music.play(1)
			print "音量:%s" % game.music.get_volume() #ボリュームの取得
			print "再生時間:%s[ms]"% game.music.get_busy() # 再生時間の取得[ms]

			time.sleep(30)
			game.music.stop() # 再生の終了
			print "終了"

		time.sleep(0.1)

except KeyboardInterrupt:
	print "end"
	GPIO.cleanup()
