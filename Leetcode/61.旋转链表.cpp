/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
 */
#include<iostream>
#include<vector>
#include<deque>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// @lc code=start
class Solution {
public:
    // 本来想用双向队列，但是超时
    // ListNode* rotateRight(ListNode* head, int k) {
    //     if(!head)
    //         return nullptr;
    //     ListNode * curr = head;
    //     deque<ListNode *> q;
    //     while(curr){
    //         q.push_back(curr);
    //         curr=curr->next;
    //     }
    //     if(q.size() == 1)
    //         return head;
    //     for(int i=0; i<k; ++i){
    //         curr = q.back();
    //         q.pop_back();
    //         q.back()->next = nullptr; 
    //         q.push_front(curr);
    //         curr->next = head;
    //         head = curr;
    //     }
    //     return head;
    // }
    ListNode* rotateRight(ListNode* head, int k){
        if(!head)
            return nullptr;
        int len = 1;
        ListNode * tail = head;
        ListNode * pos = head;
        while(tail->next){
            tail = tail->next;
            ++len;
        }
        if(k%len == 0)
            return head;
        int n = len - k%len - 1;
        for(int i=0; i<n; ++i)
            pos = pos->next;
        tail->next = head;
        head = pos->next;
        pos->next = nullptr;
        return head;
    }
};
// @lc code=end
int main()
{
    Solution s;
    vector<int> v1 = {1,2,3,4};
    ListNode * head1 = new ListNode();
    ListNode * tp_head1 = head1;
    for(int i=0; i<v1.size(); ++i){
        tp_head1->next = new ListNode(v1[i]);
        tp_head1 = tp_head1->next;
    }
    tp_head1 = s.rotateRight(head1->next, 4);
    while(tp_head1){
        cout<<tp_head1->val<<"->";
        tp_head1 = tp_head1->next; 
    }
    cout<<"NULL"<<endl;
    return 0;
}
