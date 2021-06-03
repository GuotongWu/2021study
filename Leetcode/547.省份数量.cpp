/*
 * @lc app=leetcode.cn id=547 lang=cpp
 *
 * [547] 省份数量
 */
#include<iostream>
#include<vector>
using namespace std;
// @lc code=start
class UnionFind {
public:
    vector<int> fa;
    int cnt;
    UnionFind(vector<vector<int>> isConnected){
        int n = isConnected.size();
        for(int i=0; i<n; ++i)
            fa.push_back(i);
        cnt = n;
    }
    int find(int x){
        if(fa[x] != x)
            return fa[x] = find(fa[x]);
        return fa[x];
    }
    void merge(int x, int y){
        int a = find(x);
        int b = find(y);
        if(a != b){
            fa[a] = b;
            --cnt;
        }
    }
    void getNum(vector<vector<int>> isConnected){
        int n = isConnected.size();
        for(int i=0; i<n; ++i)
            for(int j=0; j<n; ++j)
                if(isConnected[i][j])
                    merge(i,j);
    }
};
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        UnionFind u(isConnected);
        u.getNum(isConnected);
        return u.cnt;
    }
};
// @lc code=end

