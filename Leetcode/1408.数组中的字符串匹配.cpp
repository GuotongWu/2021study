/*
 * @lc app=leetcode.cn id=1408 lang=cpp
 *
 * [1408] 数组中的字符串匹配
 */
#include<iostream>
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    bool isSubstr(string p, string s){
        int n = p.size(), m = s.size();
        vector<int> ne(n, -1);
        for(int i=1; i<n; ++i){
            int j = ne[i-1];
            while(j>0 && p[j+1]!=p[i])
                j = ne[j];
            if(p[j+1] == p[i])
                ne[i] = j + 1;
            else ne[i] = -1;
        }

        int i=0, j=0;
        while(i<m && j<n){
            if(s[i] == p[j]){
                ++i;
                ++j;
            }
            else if(j>0)
                j = ne[j-1] + 1;
            else
                ++i;
        }
        return j==n;
    }

    vector<string> stringMatching(vector<string>& words) {
        vector<string> res;
        for(int i=0; i<words.size(); ++i)
            for(int j=0; j<words.size(); ++j)
                if(i!=j && isSubstr(words[i], words[j])){
                    res.push_back(words[i]);
                    break;
                }
        return res;
    }
};
// @lc code=end

