# 计算机专业课复习

## 1. 数据结构与算法

### 1.1 [Dijkstra最短路径算法](https://zhuanlan.zhihu.com/p/338414118)

1. 初始化一个visited数组代表是否访问，一个res数组代表从当前结点出发到其他结点的距离
2. 将第一个结点visited标记为1
3. 每次循环，选取visited为0（没有访问），且到当前结点路径最短的结点。对其他所有未访问的结点，更新res，`res[k] = min(res[k], res[minPos]+graph[minPos][k])`

[代码](./AcWing/Others/dijkstra.cpp)

## 2. 操作系统

## 3. 计算机网络

## 4. 计算机组成原理

## 5. C语言基础

### 5.1 [堆栈的区别]([堆和栈的理解和区别，C语言堆和栈完全攻略 (biancheng.net)](http://c.biancheng.net/c/stack/))

内存的分配方式，共有三种

1. 静态存储区域分配：编译的时候内存已经分配好，全局变量和static变量
2. 栈：函数内部的局部变量，运行效率高，分配内存容量有限，连续的内存区域
3. 堆：动态内存分配，需要程序员申请（`malloc`）和释放（`free`），否则导致内存泄漏。**运行效率低**

### 5.2 [指针和地址的区别]([(16条消息) 指针 & 地址的联系和区别_weixin_34015336的博客-CSDN博客](https://blog.csdn.net/weixin_34015336/article/details/88915625?utm_medium=distribute.pc_relevant.none-task-blog-2~default~BlogCommendFromMachineLearnPai2~default-3.control&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2~default~BlogCommendFromMachineLearnPai2~default-3.control))

地址是字节编号，是一串16进制的数组；指针是保存地址的变量。