/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */
#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
// @lc code=start
class Solution {
public:
    // int lengthOfLongestSubstring(string s) {
    //     // 滑动窗口+哈希表
    //     int maxLen = 0;
    //     int right = 0;
    //     unordered_map<char, int> hashtable;
    //     for(int i=0; i<s.length() && right<s.length(); ++i){
    //         while(1){
    //             auto posi = hashtable.find(s[right]);
    //             if(posi==hashtable.end() && right<s.length()){ // 哈希表中找到，右指针右移
    //                 hashtable[s[right++]] = 1;
    //             }
    //             else{ // 反之找到，将左指针删去
    //                 hashtable.erase(s[i]);
    //                 break;
    //             }
    //         }
    //         if(maxLen<right-i)
    //             maxLen = right-i;
    //     }
    //     return maxLen;
    // }
    int lengthOfLongestSubstring(string s) {
        int maxlen = 0;
        unordered_map<char,int> hashtable;
        for(int i=0, j=0; i<s.length(); ++i){
            // 每次右边加入一个新的元素，向右移动左指针j，直到没有重复值
            while(hashtable.find(s[i]) != hashtable.end() && j<i)
                hashtable.erase(s[j++]);
            // 然后把右指针i，添加进入hash 
            hashtable[s[i]] = 1;
            maxlen = max(maxlen, i-j+1);
        }
        return maxlen;
    }
};
// @lc code=end
int main()
{
    string str = "12235";
    Solution s;
    cout<<s.lengthOfLongestSubstring(str)<<endl;
    return 0;
}
