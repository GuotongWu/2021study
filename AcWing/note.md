[TOC]

# 基础算法

## 1. 排序

![排序算法](..\source\排序算法.jpg)

## 2. 前缀和
```C++
// 前缀和
s[0] = 0;
for(int i=1; i<=n; ++i)
    s[i] = s[i-1] + a[i];
// 计算 [i,j]
res = s[j+1] - s[i];
```

# 数据结构

## 1. 堆

### 1.1 特点

1. 完全二叉树
2. 每一个结点都小于等于左右儿子，根节点是最小值（小根堆）
3. 存储方式：一维数组，x的左儿子是2x，x的右儿子是2x+1

### 1.2 基本操作

1. down: 往下调整
   1. 寻找左右儿子最小值，交换根节点和最小值
   2. 重复以上操作
2. up：往上调整
   1. 与以上相反

### 1.3 操作

1. 插入新数：`heap[++size] = x; up(size);`
2. 求当前最小值：`heap[1]`
3. 删除最小数：用最后一个覆盖第一个，删除最后一个点，然后down：`heap[1]=heap[size]; --size; down(1);`
4. 删除任何一个元素：`heap[k] = heap[size]; --size; down(k); up(k);`
5. 修改任何一个元素

## 2. 哈希表

### 2.1 存储结构

将一个值域较大，分布稀疏的空间映射到另一个空间

常用：`x = mod(x, 1e5);`

处理冲突的方式：

1. 开放寻址法
2. 链表法

# 搜索与图

## 1. 图

使用邻接表的方法存储图

```c++
int h[N], e[N], ne[N], idx;

void add(){int a, int b} // 添加从a指向b的边
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

// 初始化
idx = 0;
memset(h, -1, sizeof(h));
```

## 2. 拓扑排序

有向无环图：拓扑图

```c++
// 算法 BFS
选取所有入度为0的结点入队;
while(队列不空){
    node curr = q.top();
    for(){
        遍历curr所有指向的结点j;
        删除curr->j的入度
        if(j入度为0){
            加入队列
        }
    }
    头结点出队
}
```

## 3. 最小生成树

### 3.1 prim算法

```C++
// 算法
dist[i]全部初始化为正无穷;
for(){
    找到集合外距离最近的点t;
    使用t来更新其他点到集合的距离;
    把t加入到集合之中去;
}
```

### 3.2 Kruskal算法

```C++
// 算法
将所有边按权重从小到大排序;
for(){
	从小到大枚举每条边a、b;
    if(不在一个集合中){
        加入集合中
    }
}
```

## 4. 最短路径算法

### 4.1 [Dijkstra最短路径算法](https://zhuanlan.zhihu.com/p/338414118)

1. 初始化一个visited数组代表是否访问，一个res数组代表从当前结点出发到其他结点的距离
2. 将第一个结点visited标记为1
3. 每次循环，选取visited为0（没有访问），且到当前结点路径最短的结点。对其他所有未访问的结点，更新res，`res[k] = min(res[k], res[minPos]+graph[minPos][k])`

[代码](./AcWing/Others/dijkstra.cpp)

### 4.2 Floyd算法

```c++
// d[i][j]是i->j最短路径
for(int k=1; k<=n; ++k)
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=n; ++j)
            d[i][j] = min(d[i][j], d[i][k]+d[k][j])
```

# 动态规划

## 1. 背包问题

### 1.1 0-1背包问题

> 题目：n件物品，总体积m，**每件物品只能使用一次**，求价值最大

只考虑前`i`个物品， 总体积小于等于`j`
$$
f[i,j] = max(f[i-1,j], f[i-1][j-v_i]+w_i)
$$
一维优化

```C++
for(int i=1; i<=n; ++i)
    for(int j=m; j>=v[i]; --j) // 循环从大到小？？？
        f[j] = max(f[j], f[j-v[i]]+w[i]);
```

### 1.2 完全背包问题

> 题目：与上面的区别在于每件物品可以无限次使用

$$
f[i, j] = max(f[i-1][j-k\times v_i]+k\times w_i)
$$

优化后
$$
f[i,j] = max(f[i-1,j], f[i, j-v_i]+w_i)
$$

```c++
for(int i=1; i<=n; ++i)
    for(int j=v[i]; j<=m ; ++j) 
        f[j] = max(f[j], f[j-v[i]]+w[i]);
```

### 1.3 多重背包问题

> 题目：与上题的区别在于，每件物品的个数有限制 $ s_i$ 件

```c++
for(int i=1; i<=n; ++i)
    for(int j=0; j<=n; ++j)
        for(int k=0; k*v[i]<=j && k<=s[i]; ++k)
            f[i][j] = max(f[i][j], f[i-1][j-v[i]*k]+k*w[i])
```

