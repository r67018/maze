# これは何？
コンソールで動く迷路  
迷路を自動生成するアルゴリズムを試したかった  

![Animation](https://user-images.githubusercontent.com/66293670/127705440-94935d94-5bed-49de-a2e0-29949519e74f.gif)

# 実行方法
docker を使うとき
```
docker pull swk67018/maze
docker run --name maze -it swk67018/maze

コンテナ内で
./main
```

使わないとき
```
git clone https://github.com/swk67018/maze.git
cd maze
make CFLAGS="-DPRINT_CREATE_PROCESS"
build/main
```

# 実装
言語: C++  
アルゴリズム: 穴掘り法  
Makefile に初挑戦  

# 参考
[C言語で穴掘り法を使った自動迷路作成を実装してみた - Qiita](https://qiita.com/zurazurataicho/items/1435b7236b6b1ca34334)  
[自動生成迷路](http://www5d.biglobe.ne.jp/stssk/maze/make.html)  
[Makefileでワイルドカードを使う方法 - nao-bambooの日記](https://nao-bamboo.hatenablog.com/entry/2015/09/11/175832)  
