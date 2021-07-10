/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */
#include<iostream>
#include<stack>
using namespace std;
// @lc code=start
class Solution {
public:
    bool equal(char c1, char c2){
        if(c1=='(' && c2==')')
            return true;
        if(c1=='{' && c2=='}')
            return true;
        if(c1=='[' && c2==']')
            return true;
        return false;
    }

    bool isValid(string s) {
        stack<char> st;
        for(auto ch: s){
            if(st.size() && equal(st.top(),ch))
                st.pop();
            else
                st.push(ch);
        }
        return st.size()==0;
    }
};
// @lc code=end

