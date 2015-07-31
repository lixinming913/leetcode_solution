/*
 *  Linked List Cycle II 
 *  Given a linked list, return the node where the cycle begins. 
 *  If there is no cycle, return null.
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
    ListNode *meetingnode(ListNode *head) {
        if(head == NULL)
            return NULL;
        
        ListNode *pSlow = head->next;
        if(pSlow == NULL)
            return NULL;
        
        ListNode *pFast = pSlow->next;
        
        while(pSlow != NULL && pFast != NULL) {
            if(pSlow == pFast)
                return pFast;
            
            pSlow = pSlow->next;
            pFast = pFast->next;
            if(pFast != NULL)
                pFast = pFast->next;
        }
        
        return NULL;
    }
    
    ListNode *detectCycle(ListNode *head) {
        ListNode *meeting_node = meetingnode(head);
        if(meeting_node == NULL)
            return NULL;
        /*total numbers of nodes in circle*/
        int n_circle = 1;
        ListNode *pnode1 = meeting_node;
        while(pnode1->next != meeting_node) {
            pnode1 = pnode1->next;
            ++n_circle;
        }
        
        pnode1 = head;
        for(int i = 0 ; i < n_circle; ++i)
            pnode1 = pnode1->next;
            
        ListNode *pnode2 = head;
        while(pnode1 != pnode2) {
            pnode1 = pnode1->next;
            pnode2 = pnode2->next;
        }
        
        return pnode1;    
    }
};