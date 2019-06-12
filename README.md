# akabeko_headban
# makers fair

## 作るもの
#### ヘドバン赤べこ
音楽に合わせてヘドバンする赤べこ．
何個かの音源をBPM解析して，モーターに伝えてヘドバンさせる．

### 必要とされる言語

 - BPM解析 ... Python (raspberry pi)
 - LEDとか色々 ... Arduino (simblee)
 - 音声を出す ... Python (raspberry pi)

### 必要とされる部品

 - キーボード，マウス ... Raspberry piを使うために必須
 - LED ... 赤べこを光らせたい...光らせたくない？
 - モーター ... 赤べこをヘドバンさせるには必須
 - ボックス ... Raspberry piを隠す，モーターをつけるなど色々必要
 - 熱意 ... これがないと始まらないよね
 - モータードライバ　... 持ってるからいいかな
 - 電池ボックス ...　モータを動かすのに必要
 - 電池 ... モータを動かすのに必要

 ### 実際使ったもの

 - モータードライバ (ステッピングモータ) ROB-12779
 - ステッピングモータ (UniP 5V)
 - DC 5V （そこらへんのジャンクショップで買って来た)

 ### 配線図
 ![Akabeko_comp.png](./img/Akabeko_comp.png)


## 作成中のメモ

## 音楽
全て [魔王魂](http://maoudamashii.jokersounds.com/) から引用.

### 1曲目
 - ネオロック83 (akabeko1.wav)
 - BPM == 80

### 2曲目
 - ネオロック57
 - BPM == 116

### 3曲目
 - ネオロック74 (akabeko3145.wav)
 - BPM == 145

## BPM解析
プロ (-> tspider0176 ) が作ったレポを使いました．
ありがとうございます．

[ここ](https://github.com/tspider0176/bpm-analyzer)です
