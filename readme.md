### 2019/05/23 500 ✔

### 2019/07/22 666 ✔

### 2020/05/29 update

去年拿了几枚银牌算是退役了，今天无聊学会了git统计代码行数，想起了这个爱恨交织的ACM，也可以说是梦开始的地方。当年大学搞ACM纯粹是因为高中没有打过竞赛，没有听过自主招生，我奇怪为什么要有自招和保送这种开挂的东西，为什么我没有这种机会，我想证明一下自己，证明我搞竞赛也不会输给别人。没想到一搞就是两年，走了很多弯路，发生了很多事情，明白了很多事情，成长了不少，虽然没有达到当初的梦想，也算是坚持了下来，成就一段难忘的经历。

```sh
$ git log --author=qq734628996 --format='%aN' | sort -u | while  read name; do echo -en "$name\t"; git log  --author="$name" --pretty=tformat: --numstat | grep  "\(.c\|.cpp\|.py\|.java\)$" | awk '{ add += $1; subs += $2; loc +=  $1 - $2 } END { printf "added lines: %s, removed lines:  %s, total lines: %s\n", add, subs, loc }' -; done
qq734628996     added lines: 98085, removed lines:  0, total lines: 98085
```

才不到10W行，我又想起大学C渣渣老师，从最高分专业转到最低分的计算机专业，帮学校拿到第一枚ACM金牌，进入总决赛，说的一句话：“10W行代码量，没人要你来我这。”。。。
