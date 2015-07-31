/**
 *  Linked List Cycle 
 *  Given a linked list, determine if it has a cycle in it.
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
    bool hasCycle(ListNode *head) {
        if(head == NULL)
           return false;
           
        ListNode *pSlow = head->next;
        if(pSlow == NULL)
           return false;
        ListNode *pFast = pSlow->next;
        while(pFast && pSlow) {
            if(pFast == pSlow)
                return true;
            
            pSlow = pSlow->next;
            pFast = pFast->next;
            if(pFast != NULL)
                pFast = pFast->next;
        }
        
        return false;
    }
};