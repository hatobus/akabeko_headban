FRAME_LEN = 512

def bit_per_sample(format)
  # ここでは16bitか8bitしか対象にして居ないので三項演算子で表現
  format.bitPerSample == 16 ? 's*' : 'c*'
end

def get_wav_array(data_chunk, format)
  data_chunk.data.unpack(bit_per_sample(format))
end

f = open("./akabeko1.wav") # BPM120のメトロノーム音が入ったWAVファイル
data_chunk = WavFile::readDataChunk(f)
format = WavFile::readFormat(f)
f.close()

get_wav_array(data_chunk, format)
      .take(@wavs.size - @wavs.size % FRAME_LEN)
      .each_slice(FRAME_LEN).to_a
