import pygame.mixer as pgm,time

pgm.init()
pgm.music.load('./music/akabeko1.mp3')
pgm.music.play(1)

for i in range(10):
    print(i)
    time.sleep(1)

print("loop end")
time.sleep(5)
print("end")
