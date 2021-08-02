/*
维护一个字符串集合，支持两种操作：

I x 向集合中插入一个字符串 x；
Q x 询问一个字符串在集合中出现了多少次。
共有 N 个操作，输入的字符串总长度不超过 105，字符串仅包含小写英文字母。
*/

#include<iostream>
using namespace std;

const int N = 1e5+10;
int idx; // 每一个结点的编号
int son[N][26]; //第一维是结点编号，son存储下一个结点的编号（第一维的变量）
int cnt[N]; // 每个结点的字符数量

void insert(string s){
    int p = 0;
    for(int i=0; i<s.size(); ++i){
        int u = s[i] - 'a';
        if(!son[p][u])
            son[p][u] = ++idx;
        p = son[p][u];
    }
    ++cnt[p];
}

int query(string s){
    int p = 0;
    for(int i=0; i<s.size(); ++i){
        int u = s[i] - 'a';
        if(!son[p][u])
            return 0;
        p = son[p][u];
    }
    return cnt[p];
}