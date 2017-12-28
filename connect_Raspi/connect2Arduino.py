import RPi.GPIO as GPIO,time

GPIO.setmode(GPIO.BCM)

GPIO.setup(23,GPIO,IN)
GPIO.setup(24,GPIO.OUT)

try:
    while True:

        if GPIO.input(23) == True:
            GPIO.output(24,True)
            time.sleep(0.1)
            
        else:
            GPIO.output(24,False)
            time.sleep(0.1)

except KeyboardInterrupt:
    GPIO.cleanup()
