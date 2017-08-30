import numpy as np
import scipy.io.wavfile as scw
import matplotlib.pyplot as plt
import sys

# 信号とbpmのマッチ度を計算
def calc_match_bpm(data,bpm):
    N       = len(data)
    f_bpm   = bpm / 60
    f_frame = 44100 / 512

    phase_array = np.arange(N) * 2 * np.pi * f_bpm / f_frame
    sin_match   = (1/N) * sum( data * np.sin(phase_array))
    cos_match   = (1/N) * sum( data * np.cos(phase_array))
    return np.sqrt(sin_match ** 2 + cos_match ** 2)

# 各bpmでのマッチ度リストを返す
def calc_all_match(data):
    match_list = []
    bpm_iter   = range(60,300)

    # 各bpmにおいてmatch度を計算する
    for bpm in bpm_iter:
        match = calc_match_bpm(data,bpm)    
        match_list.append(match)

    return match_list

if __name__ == '__main__':

    # データの読み込み 
    if len(sys.argv) > 1:
        src_name = sys.argv[1]
    else:
        src_name = "./akabeko1.wav" 

    rate, dt = scw.read(src_name)
    dt       = dt / (2 ** 15) #normalize
    sample_total = dt.size
    ts       = 1 / rate # サンプリング周期[t]

    # フレームごとの音量データ作成
    # フレームサイズ分，振幅二乗和を計算，
    frame_size = 512
    sample_max = sample_total - (sample_total % frame_size) #余りフレームは切り捨てる
    frame_max  = sample_max / frame_size
    frame_list = np.hsplit(dt[:sample_max],frame_max)
    amp_list   = np.array([np.sqrt(sum(x ** 2)) for x in frame_list])

    # 音量の増加量を取得.
    # 負値はゼロにする.
    amp_diff_list = amp_list[1:] - amp_list[:-1]
    amp_diff_list = np.vectorize(max)(amp_diff_list,0) # np.vectorizeは関数をndarrayの各要素に適用可能にする

    # bpm推定
    match_list = calc_all_match(amp_diff_list)      # 各bpmのマッチ度を計算
    most_match = match_list.index(max(match_list))  # マッチ度最大のindexを取得
    print(most_match+60)                            # bpmに変換

    # plot
    plt.plot(np.arange(60,60+len(match_list)),match_list)
    plt.show()