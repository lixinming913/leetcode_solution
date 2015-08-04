/**
 *  Reverse Nodes in k-Group 
 *  Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
 *  If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
 *  You may not alter the values in the nodes, only nodes itself may be changed.
 *  Given this linked list: 1->2->3->4->5,For k = 2, you should return: 2->1->4->3->5
 *  For k = 3, you should return: 3->2->1->4->5
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int size = 0;
        ListNode *pnode = head;
        while(pnode != NULL) {
            pnode = pnode->next;
            ++size;
        }
        
        if(k > size)
            return head;
            
        ListNode *new_head = NULL;
        ListNode *new_tail   = NULL;
        
        while(k <= size) {
            ListNode *ghead = NULL;
            
            for(int i = 0; i < k; ++i) {
                ListNode *ptmp = head;
                head = head->next;
                --size;
                ptmp->next = ghead;
                ghead = ptmp;
            }
            
            if(new_head == NULL) {
                new_head = ghead;
                new_tail   = ghead;
            } else {
                new_tail->next = ghead;
            }
            
            while(new_tail->next != NULL) {
                new_tail = new_tail->next;
            }
        }
        
        if(head != NULL)
            new_tail->next = head;
            
        return new_head;
    }
};