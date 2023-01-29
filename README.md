# push_swap
## 概要
42Tokyoの課題の一つ。以下のゲームにおける準最適解の探索。</br>

## ゲーム詳細
### 構成
２本のスタックa, bで構成

### 初期状態
- スタックa : 正負いずれかの乱数値が重複なく無作為に任意個格納されている
- スタックb : 空

#### Example
```
a | 2 1 3 6 5 8
b |
```

### 終了状態
- スタックa : 数字が昇順に並んでいる
- スタックb : 空

#### Example
```
a | 1 2 3 5 6 8
b |
```

### 目標
なるべく少ない操作数で終了状態に遷移させる。

### 操作
スタックに対して以下の操作が許されている。
- **sa** : swap a - スタックaの先頭２要素をスワップ。
- **sb** : swap b - スタックbの先頭２要素をスワップ。
- **ss** : saとsbを同時に行う。
- **pa** : push a - bの先頭の要素を取り、aの先頭に置く。bが空なら何も行わない。
- **pb** : push b - aの先頭の要素を取り、bの先頭に置く。aが空なら何も行わない。
- **ra** : rotate a - スタックaの全要素を1つずつ右シフト。最後の要素は先頭へ。
- **rb** : rotate b - スタックbの全要素を1つずつ右シフト。最後の要素は先頭へ。
- **rr** : raとrbを同時に行う。
- **rra** : reverse rotate a - スタックaの全要素を1つずつ左シフト。最初の要素は末尾へ。
- **rrb** : reverse rotate b - スタックbの全要素を1つずつ左シフト。最初の要素は末尾へ。
- **rrr** : rraとrrbを同時に行う。

#### Example
```
Init
a | 2 1 3 6 5 8
b |

> sa:
a | 1 2 3 6 5 8
b |

> pb pb pb:
a | 6 5 8
b | 3 2 1

> ra rb:
a | 5 8 6
b | 2 1 3

> rra rrb:
a | 6 5 8
b | 3 2 1

> sa:
a | 5 6 8
b | 3 2 1

> pa pa pa:
a | 1 2 3 5 6 8
b |

命令数: 12
```

## 実行
### 環境の構築
```
$ git clone https://github.com/RIshimoto/push_swap
$ cd push_swap
$ virtualenv -p python3.7 .venv
$ source .venv/bin/activate
(.venv)$ pip install -r requirements.txt
(.venv)$ build
```

### 
```
(.venv)$ python srcipt/train.py
```

### 
```
(.venv)$ ./push_swap "2 1 3 6 5 8”
```

## デモ
https://user-images.githubusercontent.com/57135683/213191249-c802d00a-ec0b-4bd3-9fd0-e651bf031dd8.mp4

