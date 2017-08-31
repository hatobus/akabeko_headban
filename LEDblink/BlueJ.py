# coding: utf-8
import RPi.GPIO as GPIO
import time
GPIO.setmode(GPIO.BCM)
GPIO.setup(2,GPIO.IN)
GPIO.setup(3,GPIO.IN)
GPIO.setup(21,GPIO.OUT)
GPIO.setup(22,GPIO.OUT)
try:
    while True:
        if (GPIO.input(2) == 1):
            for i in range(6):
    	        GPIO.output(21,True)
    	        time.sleep(60.0/160)
    	        GPIO.output(21,False)
    	        time.sleep(60.0/160)
	        #continue
        if (GPIO.input(3) == 1):
            for i in range(6):
                GPIO.output(22,True)
                time.sleep(60.0/160)
                GPIO.output(22,False)
                time.sleep(60.0/160)
	        #continue
except KeyboardInterrupt:
    GPIO.cleanup()

