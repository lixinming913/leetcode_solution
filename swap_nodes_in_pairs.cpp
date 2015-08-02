/**
 *  Swap Nodes in Pairs 
 *  Given a linked list, swap every two adjacent nodes and return its head.
 *  Given 1->2->3->4, you should return the list as 2->1->4->3.
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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL) 
            return head;
            
        ListNode *pre = head;   
        ListNode *pnode = head;
        bool swap = true;
        while(pnode->next) {
            if(swap) {
                ListNode *pnext = pnode->next;
                pnode->next = pnext->next;
                pnext->next = pnode;
                
                if(pre == head) {
                    head = pnext;
                    pre = pnext;
                } else {
                    pre->next = pnext;
                }
            }
            
            else {
                pre = pnode;
                pnode = pnode->next;
            }
            swap = !swap;
        }
        
        return head;
    }
};