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
        
        if(n < 0) return head;
        if(head == nullptr) return head;
        
        ListNode* iter = head;
        int N = 0;
        int m = 0;
        
        // ͳ�ƽڵ����
        while(iter)
        {
            N++;
            iter = iter->next;
        }
        
        m = N - n;
        
        // ��������ɾ����һ���ڵ�����
        if(m == 0)
        {
            head = head->next;
            return head;
        }
        
        iter = head;
        m = m - 1;
        while(iter && m--)
        {
            iter = iter->next;
        }
        
        // ɾ���ڵ��ʵ�ʴ���
        iter->next = iter->next->next;
        
        return head; 
    }
};