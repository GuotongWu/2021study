```shell
git init

git help

git status

git add <filename>
git add -p <filename> #选择性add

git commit -m "xxx"
```

```shell
git log
git log --all --graph --decorate
git log --all --graph --decorate --online
```

```shell
git diff <filename>
git diff <branch1> <branch2> <fiename>
git diff --cache
```

```shell
git checkout <branchname> #更新HEAD
git checkout -b <name>
```

```shell
git branch #显示分支
git branch -vv #显示详细信息
git branch <name>

git merge <revision>
```

```shell
git remote add <name> <url>
# git remote add origin ../remote

git push <name> <local branch>:<remote branch>
# git push origin master:master

git branch --set-upstream-to=origin/master
git push

git fetch <remote>
git merge
# 等价于git pull
```

```sh
git clone <url> <fodername>
git clone --shallow
```

```shell
git config
```

```shell
git stash #返回到最近一次版本
git stash --pop #撤销上述动作
```

