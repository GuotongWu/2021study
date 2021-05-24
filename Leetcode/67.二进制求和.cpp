/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 */
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    string addBinary(string a, string b) {
        if(a.length() < b.length())
            return addBinary(b,a);
        int flag = 0;
        string res = "";
        for(int i=a.length()-1, j=b.length()-1; i>=0; --i,--j){
            flag += (int)a[i]-48;
            if(j>=0)
                flag += (int)b[j]-48;
            res += (char)(flag%2+48);
            flag /= 2;
        }
        if (flag)
            res += '1';
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end
int main()
{
    string a = "11", b = "1";
    Solution s;
    string res = s.addBinary(a,b);
    cout<<res<<endl;
    return 0;
}