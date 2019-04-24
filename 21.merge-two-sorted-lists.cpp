/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // 两个指针指向头顶，循环中比较两个大小，谁小就加入谁
        if(l1 == nullptr) return l2;
        if(l2 == nullptr) return l1;
        
        ListNode* newHead;
        ListNode* iter1 = l1;
        ListNode* iter2 = l2;
        ListNode* iter;
        
        if(iter1->val < iter2->val)
        {
            newHead = iter1;
            iter1 = iter1->next;
        }
        else
        {
            newHead = iter2;
            iter2 = iter2->next;
        }
        
        iter = newHead;
        
        while(iter1 && iter2)
        {
            if(iter1->val < iter2->val)
            {
                iter->next = iter1;
                iter1 = iter1->next;
                iter = iter->next;
            }
            else
            {
                iter->next = iter2;
                iter2 = iter2->next;
                iter = iter->next;
            }
        }
        
        if(iter1)
        {
            iter->next = iter1;
        }
        
        if(iter2)
        {
            iter->next = iter2;
        }
        
        return newHead;
    }
};