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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
		// 只扫描一遍，用两个指针
        if(head == nullptr) return head;
        if(n <= 0) return head;
        
        ListNode* first = head;
        ListNode* second = head;
        
        n = n + 1;
        while(first && n--)
        {
            first = first->next;
        }
        
        // 头结点单独处理
        if(n > 0)
        {
            head = head->next;
            return head;
        }
        
        while(first)
        {
            first = first->next;
            second = second->next;
        }
        
        second->next = second->next->next;
        
        return head;
        
    }
};