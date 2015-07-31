/**
 *  Remove Duplicates from Sorted List II 
 *  Given a sorted linked list, delete all nodes that have duplicate numbers, 
 *  leaving only distinct numbers from the original list.
 *  1->2->3->3->4->4->5, return 1->2->5.
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
        if(head == NULL)
            return NULL;
        
        ListNode *pre = NULL;
        ListNode *pnode = head;
        while(pnode != NULL) {
            ListNode *pnext = pnode->next;
            bool needDelete = false;
            if(pnext != NULL && pnext->val == pnode->val)
                needDelete = true;
            
            if(!needDelete){
                pre = pnode;
                pnode = pnext;
            } else {
                int key = pnode->val;
                ListNode *ptodel = pnode;
                while(ptodel != NULL && ptodel->val == key) {
                    pnext = ptodel->next;
                    
                    delete ptodel;
                    ptodel = NULL;
                    
                    ptodel = pnext;
                }
                
                if(pre == NULL)
                    head = pnext;
                else
                    pre->next = pnext;
                
                pnode = pnext;
            }

        }
        
        return head;
    }
};