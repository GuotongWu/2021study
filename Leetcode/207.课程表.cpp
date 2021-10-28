/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表
 */
#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;
// @lc code=start
const int N = 100010;


class Solution {
public:
    int e[N], ne[N], h[N], d[N], idx;
    int v[N], cnt;
    queue<int> q;
    
    void add(int a, int b){
        e[idx] = b;
        ne[idx] = h[a];
        h[a] = idx++;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        memset(h, -1, sizeof(h));
        for(auto item: prerequisites){
            add(item[1], item[0]);
            ++d[item[0]];
        }
        for(int i=0; i<numCourses; ++i)
            if(!d[i])
                q.push(i);
        while(!q.empty()){
            int curr = q.front();
            v[cnt++] = curr;
            for(int i=h[curr]; i!=-1; i=ne[i]){
                if(--d[e[i]] == 0)
                    q.push(e[i]);
            }
            q.pop();
        }
        // cout<<cnt<<endl;
        // for(int i=0; i<cnt; ++i)
        //     cout<<v[i]<<" ";
        return cnt==numCourses;
    }
};
// @lc code=end

