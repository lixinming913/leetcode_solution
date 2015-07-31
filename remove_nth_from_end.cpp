/**
 *  Remove Nth Node From End of List 
 *  Given a linked list, remove the nth node from the end of list and return its head.
 *  Given linked list: 1->2->3->4->5, and n = 2.becomes 1->2->3->5
 */

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
    /*设置两个指针，p1指向第一个，p2指向第n-1个，当p2处于尾结点时，p1就是倒数第n个*/
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL || head->next == NULL)
            return NULL;
            
        ListNode *p1 = head;
        ListNode *p2 = head;
        ListNode *pre = NULL;
        
        for(unsigned int i = 0; i < n-1; ++i) {
            p2 = p2->next;
        }
        
        if(p2->next == NULL)
            return head->next;
            
        while(p2->next != NULL) {
            p2 = p2->next;
            pre = p1;
            p1 = p1->next;
        }
        
        pre->next = p1->next;
        
        return head;
    }
};