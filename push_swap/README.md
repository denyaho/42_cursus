*This project has been created as part of the 42 curriculum by daogawa*

# Project Name
 Push_swap

## Description
Push_swapは、2つのスタック（Stack AとStack B）と限定された命令セットを使用して、Stack Aのデータを効率的にソートするアルゴリズムを構築するプロジェクトです。
本プロジェクトの目的は、手数の最小化を意識しながら、C言語で最適なソートアルゴリズムを実装することにあります。私は「Turk Algorithm」を採用し、500個の数値に対して平均[5000]手でのソートを実現しました。

## Instructions
 1. git cloneよりコードをクローンします。
 2. 「make」コマンドよりコードをコンパイルすると実行ファイル `push_swap` が生成されます。「make fclean」でオブジェクトファイルの削除、「make fclean」でオブジェクトファイルと実行ファイルが削除されます。「make re」をすると1からコンパイルが可能です。
 3. 実行したいときは「./push_swap 3 2 5 1 4」または「./push_swap "3 2 5 1 4"」と実行してください。
 実行結果は毎回の手順が記載されます。
 ```
 実行例:

 c1r2s3% ./push_swap 3 2 5 1 4
pb
pb
sb
ra
ra
pa
pa
rra
 ```

操作一覧
sa (swap a): スタックAの先頭にある2つの要素を入れ替える。要素が1つ以下の場合は何もしない。

sb (swap b): スタックBの先頭にある2つの要素を入れ替える。要素が1つ以下の場合は何もしない。

ss : sa と sb を同時に行う。

pa (push a): スタックBの先頭にある要素を取り出し、スタックAの先頭に置く。スタックBが空の場合は何もしない。

pb (push b): スタックAの先頭にある要素を取り出し、スタックBの先頭に置く。スタックAが空の場合は何もしない。

ra (rotate a): スタックAの全要素を1つ分上にずらす。先頭の要素は最後の要素になる。

rb (rotate b): スタックBの全要素を1つ分上にずらす。先頭の要素は最後の要素になる。

rr : ra と rb を同時に行う。

rra (reverse rotate a): スタックAの全要素を1つ分下にずらす。最後の要素は先頭の要素になる。

rrb (reverse rotate b): スタックBの全要素を1つ分下にずらす。最後の要素は先頭の要素になる。

rrr : rra と rrb を同時に行う。

4. 結果が正しいか確認したい場合は「checker」を用いてください。

```
実行例:
$>ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_OS $AR
OK
```
5. ランダムな100個や500個の数をソートしたい場合は以下テスターを用いてください。使い方は以下URLをご参照ください。

https://github.com/nafuka11/push_swap_tester

### Benchmark

プロジェクトの最大評価（100点）およびボーナスの権利を得るための条件:

    100個のランダムな数字を 700手未満 でソートすること。

    500個のランダムな数字を 5500手以内 でソートすること。

最低限の合格（最低点 80点）となる平均手数の目安: 以下のいずれかの基準を満たすことで合格（80点以上）となります。

    100個で1100手未満、かつ 500個で8500手未満

    100個で700手未満、かつ 500個で11500手未満

    100個で1300手未満、かつ 500個で5500手以内

### Resources

Turk アルゴリズムは以下資料をご参照ください。

https://pure-forest.medium.com/push-swap-turk-algorithm-explained-in-6-steps-4c6650a458c0

https://medium.com/@ayogun/push-swap-c1f5d2d41e97

Pushswapのテストは以下資料をご参照ください。

https://github.com/nafuka11/push_swap_tester


### AI use Description

このプロジェクトでは適切なソートアルゴリズムの選択と、エラー処理においてAIを使用しました。
エラー処理においては、エラー部分の可能性をAIで出力し、自分でアルゴリズムを確認しつつ訂正しました。
