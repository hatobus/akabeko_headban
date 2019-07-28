#! /usr/bin/python3
import RPi.GPIO as GPIO
import time
import pygame.mixer as game
import os

GPIO.setmode(GPIO.BCM)

GPIO.setup(12, GPIO.OUT)
GPIO.setup(17, GPIO.OUT)
GPIO.setup(18, GPIO.OUT)
GPIO.setup(20, GPIO.IN, pull_up_down=GPIO.PUD_DOWN)
GPIO.setup(21, GPIO.IN, pull_up_down=GPIO.PUD_DOWN)
GPIO.setup(23, GPIO.OUT)
GPIO.setup(24, GPIO.IN, pull_up_down=GPIO.PUD_DOWN)
GPIO.setup(27, GPIO.OUT)

tmptime = 30.0

MUSICDIR = "/home/pi/akabeko_headban/music"

try:
    while True:
        if GPIO.input(20) == True:
            game.init()
            game.music.load(os.path.join(MUSICDIR, 'akabeko1.mp3'))
            game.music.play(1)
            GPIO.output(23, True)
            intime = time.time()
            nowtime = intime

            while nowtime - intime < tmptime:
                GPIO.output(12, True)
                time.sleep(60.0 / 160000 * 2)
                GPIO.output(12, False)
                time.sleep(60.0 / 160000 * 2)
                nowtime = time.time()

            game.music.stop()

        if GPIO.input(21) == True:
            game.init()
            game.music.load(os.path.join(MUSICDIR, 'akabeko2.mp3'))
            game.music.play(1)
            GPIO.output(18, True)
            intime = time.time()
            nowtime = intime

            while nowtime - intime < tmptime:
                GPIO.output(12, True)
                time.sleep(116.0 / 160000 * 2)
                GPIO.output(12, False)
                time.sleep(116.0 / 160000 * 2)
                nowtime = time.time()

            game.music.stop()

        if GPIO.input(24) == True:
            game.init()
            game.music.load(os.path.join(MUSICDIR, 'akabeko3145.mp3'))
            game.music.play(1)
            GPIO.output(17, True)
            intime = time.time()
            nowtime = intime

            while nowtime - intime < tmptime:
                GPIO.output(12, True)
                time.sleep(145.0 / 160000)
                GPIO.output(12, False)
                time.sleep(145.0 / 160000)
                nowtime = time.time()

            game.music.stop()

        else:
            GPIO.output(23, False)
            GPIO.output(17, False)
            GPIO.output(18, False)
            time.sleep(0.1)

except KeyboardInterrupt:
    GPIO.cleanup()

