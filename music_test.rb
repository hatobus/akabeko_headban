require 'wav-file'

f = open("./akabeko1.wav")
format = WavFile::readFormat(f)
f.close

puts format
