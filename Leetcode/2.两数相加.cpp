/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * head  = new ListNode();
        ListNode * curr = head;
        int flag = 0;
        while(l1 || l2){
            if(l1 == nullptr){
                curr->val = l2->val + flag;
                l2 = l2->next;
            }else if(l2 == nullptr){
                curr->val = l1->val + flag;
                l1 = l1->next;
            }else{
                curr->val = l1->val + l2->val + flag;
                l1 = l1->next;
                l2 = l2->next;
            }
            if(curr->val >= 10){
                flag = 1;
                curr->val %= 10;
            }else flag = 0;
            curr->next = new ListNode();
            curr = curr->next;
        }
        if(flag)
            curr->val = 1;
        // 无法解决最后的0，所以只有手动删除
        curr = head;
        while(curr->next->next)
            curr = curr->next;
        if(curr->next->val == 0)
            curr->next = nullptr;
        return head;
    }
};
// @lc code=end
int main()
{
    Solution s;
    vector<int> v1 = {7, 4, 3};
    vector<int> v2 = {5, 6, 7, 4};
    ListNode * head1 = new ListNode(v1[0]);
    ListNode * tp_head1 = head1;
    ListNode * head2 = new ListNode(v2[0]);
    ListNode * tp_head2 = head2;
    for(int i=1; i<v1.size(); ++i){
        tp_head1->next = new ListNode(v1[i]);
        tp_head1 = tp_head1->next;
    }
    for(int i=1; i<v2.size(); ++i){
        tp_head2->next = new ListNode(v2[i]);
        tp_head2 = tp_head2->next;
    }
    tp_head1 = nullptr;
    tp_head2 = nullptr;
    tp_head1 = s.addTwoNumbers(head1, head2);
    while(tp_head1){
        cout<<tp_head1->val<<"->";
        tp_head1 = tp_head1->next; 
    }
    cout<<"NULL"<<endl;
    return 0;
}
