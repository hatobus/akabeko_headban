import RPi.GPIO as GPIO
import time
import pygame.mixer as game
import os

GPIO.setmode(GPIO.BCM)

# Input (Button 1)
GPIO.setup(20, GPIO.IN)

# Input (Button 2)
GPIO.setup(21, GPIO.IN)

# Input (Button 3)
GPIO.setup(24, GPIO.IN)

# Output (LED PIN)
GPIO.setup(12, GPIO.OUT)

# Using Motor shield
GPIO.setup(23, GPIO.OUT)
GPIO.setup(18, GPIO.OUT)
GPIO.setup(17, GPIO.OUT)

cycletime = 30.0
musicAbsPath = os.path.dirname("../music/")

try:
    while True:
        if GPIO.input(20) == True:
	    game.init()
	    game.music.load(os.path.join(musicAbsPath, "akabeko1.mp3"))
	    game.music.play(1)
	    GPIO.output(23, True)
	    intime = time.time()
	    nowtime = intime

	    while nowtime - intime < cycletime:
	        GPIO.output(12, True)
		time.sleep(60.0 / 160)
		GPIO.output(12, False)
		time.sleep(60.0 / 160)
		nowtime = time.time()
	    
	    game.music.stop()
        
	if GPIO.input(21) == True:
	    game.init()
	    game.music.load(os.path.join(musicAbsPath, 'akabeko2.mp3'))
	    game.music.play(1)
	    GPIO.output(18, True)
	    intime = time.time()
	    nowtime = intime

	    while nowtime - intime < cycletime:
	        GPIO.output(12, True)
		time.sleep(116.0 / 160)
		GPIO.output(12, False)
		time.sleep(116.0 / 160)
		nowtime = time.time()
	    
	    game.music.stop()
	
	if GPIO.input(24) == True:
	    game.init()
	    game.music.load(os.path.join(musicAbsPath, 'akabeko3145.mp3'))
	    game.music.play(1)
	    GPIO.output(17, True)
	    intime = time.time()
	    nowtime = intime

	    while nowtime - intime < cycletime:
                GPIO.output(12, True)
                time.sleep(145.0 / 160)
		GPIO.output(12, False)
		time.sleep(145.0 / 160)
		nowtime=time.time()
	    
	    game.music.stop()

	else:
	    GPIO.output(23, False)
	    GPIO.output(17, False)
	    GPIO.output(18, False)
	    time.sleep(0.1)

except KeyboardInterrupt:
    GPIO.cleanup()

