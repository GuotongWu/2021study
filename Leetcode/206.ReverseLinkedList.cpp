/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
 */
#include<iostream>
#include<vector>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head)
            return nullptr;
        ListNode * temp1;
        ListNode * temp2 = head->next;
        head->next = nullptr;
        while(temp2){
            temp1 = temp2->next;
            temp2->next = head;
            head = temp2;
            temp2 = temp1; 
        }
        return head;        
    }
};
// @lc code=end
int main()
{
    Solution s;
    vector<int> v = {1,2,3,4,5};
    ListNode * head = new ListNode(v[0]);
    ListNode * tp_head = head;
    for(int i=1; i<v.size(); ++i){
        tp_head->next = new ListNode(v[i]);
        tp_head = tp_head->next;
    }
    tp_head = nullptr;
    tp_head = s.reverseList(head);
    while(tp_head){
        cout<<tp_head->val<<"->";
        tp_head = tp_head->next; 
    }
    cout<<"NULL"<<endl;
    return 0;
}
