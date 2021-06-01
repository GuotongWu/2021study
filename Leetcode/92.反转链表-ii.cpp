/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
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
class Solution {
public:
    // // 我的做法，方法和普通的反转链表相同，最后将反转部分进行拼接 
    // ListNode* reverseBetween(ListNode* head, int left, int right) {
    //     if(left == right)
    //         return head;
    //     ListNode * left_tail = new ListNode(-1);
    //     left_tail->next = head; 
    //     ListNode * right_head;
    //     ListNode * curr;
    //     ListNode * tail;
    //     ListNode * temp;
    //     for(int i=0; i<left-1; ++i)
    //         left_tail = left_tail->next;
    //     curr = left_tail->next;
    //     right_head = curr;
    //     tail = curr->next;
    //     for(int i=0; i<right-left; ++i){
    //         temp = tail->next;
    //         tail->next = curr;
    //         curr = tail;
    //         tail = temp;
    //     }
    //     left_tail->next = curr;
    //     right_head->next = temp;
    //     if(left == 1)
    //         return curr;
    //     else
    //         return head;
    // }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *start  = new ListNode(-1);
        start->next = head;
        ListNode *curr;
        ListNode *temp1, *temp2;
        for(int i=0; i<left-1; ++i)
            start = start->next;
        curr = start->next->next;
        if(right-left == 1){
            temp1 = start->next;
            temp2 = start->next->next->next;
            start->next = start->next->next;
            start->next->next = temp1;
            temp1->next = temp2;
        }
        else{
            for(int i=0; i<right-left-1; ++i){
                temp1 = curr->next;
                temp2 = start->next;
                start->next = curr;
                curr->next = temp2;
                curr = temp1;
            }
        }
        return head;    
    }
};
// @lc code=end
int main()
{
    Solution s;
    vector<int> v1 = {5,6,7,8};
    ListNode * head1 = new ListNode();
    ListNode * tp_head1 = head1;
    for(int i=0; i<v1.size(); ++i){
        tp_head1->next = new ListNode(v1[i]);
        tp_head1 = tp_head1->next;
    }
    tp_head1 = s.reverseBetween(head1->next, 1, 3);
    while(tp_head1){
        cout<<tp_head1->val<<"->";
        tp_head1 = tp_head1->next; 
    }
    cout<<"NULL"<<endl;
    return 0;
}
