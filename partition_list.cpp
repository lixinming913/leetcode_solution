/**
 *  Partition List 
 *  Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
 *  You should preserve the original relative order of the nodes in each of the two partitions.
 *  For example, Given 1->4->3->2->5->2 and x = 3, return 1->2->2->4->3->5.
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
    ListNode* partition(ListNode* head, int x) {
        ListNode *less    = new ListNode(-1);
        ListNode *greater = new ListNode(-1);
        ListNode *new_head= less;
        ListNode *gre_head= greater;
        
        if(head == NULL)
            return NULL;
        
        ListNode *pnode = head;
        while(pnode != NULL) {
            ListNode *pnext = pnode->next;
            if(pnode->val < x) {
                less->next = pnode;
                less = less->next;
                less->next= NULL;
            }
            else {
                greater->next = pnode;
                greater = greater->next;
                greater->next = NULL;
            }
            pnode = pnext;
        }
        
        less->next = gre_head->next;
        
        return new_head->next;
    }
};