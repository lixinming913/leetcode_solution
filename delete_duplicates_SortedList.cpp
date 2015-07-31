/**
 *  Remove Duplicates from Sorted List
 *  Given a sorted linked list, 
 *  delete all duplicates such that each element appear only once.
 *  Given 1->1->2, return 1->2.
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) 
            return head;
            
        ListNode *p1 = head;
        ListNode *p2 = head;
        
        while(p2->next != NULL) {
           if(p1->val == p2->next->val) {
               p2->next = p2->next->next;
           } else {
               p1 = p2->next;
               p2 = p2->next;
           }
            
        }
        
        return head;          
    }
};