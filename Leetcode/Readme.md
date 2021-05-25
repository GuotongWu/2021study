# 1. 数组

## 1.1 unordered_map

```C++
#include<unordered_map>
using namespace std;

unordered_map<string, string> ump;
```

**模板方法：**

```C++
at(key) // 返回容器中存储的键 key 对应的值，如果 key 不存在，则会抛出 out_of_range 异常。
find(key) // 查找以 key 为键的键值对，如果找到，则返回一个指向该键值对的正向迭代器；反之，则返回一个指向容器中最后一个键值对之后位置的迭代器
count(key)
insert() emplace()
erase(key)
operator[] // 如果没有则加入键，有的话则返回值
```

## 1.2 双指针

题目：26， 27

## 1.3 vector

```C++
v.insert(v.begin()+i, number); // 第一个参数必须是迭代器
```

# 2. 链表

# 3. 位运算：

1. 求n的第k位数字: `n >> k & 1`
2. 返回n的最后一位1：`lowbit(n) = n & -n`

# 4. 离散化

```cpp

vector<int> alls; // 存储所有待离散化的值
sort(alls.begin(), alls.end()); // 将所有值排序
alls.erase(unique(alls.begin(), alls.end()), alls.end());   // 去掉重复元素

// 二分求出x对应的离散化的值
int find(int x) // 找到第一个大于等于x的位置
{
    int l = 0, r = alls.size() - 1;
    while (l < r)
    {
        int mid = l + r >> 1;
        if (alls[mid] >= x) r = mid;
        else l = mid + 1;
    }
    return r + 1; // 映射到1, 2, ...n
}
```


111
