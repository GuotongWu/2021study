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
    // int a[100000];
    int lengthOfLongestSubstring(string s) {
        int maxlen = 0;
        unordered_map<int,int> hashtable;
        for(int i=0, j=0; i<s.length(); ++i){
            auto posi = hashtable.find(s[i]);
            if(posi == hashtable.end()) //如果没有找到重复，将右指针添加进入hash
                hashtable[s[i]] = 1;    
            else{ 
                // 如果找到重复，移动左指针j，直到该值消失
                while(hashtable.find(s[i]) != hashtable.end())
                    hashtable.erase(s[j--]);
            }
            maxlen = max(maxlen, i-j+1);
        }
        return maxlen;
    }
};
// @lc code=end
int main()
{
    string str = "abcabcbb";
    Solution s;
    cout<<s.lengthOfLongestSubstring(str)<<endl;
    return 0;
}
