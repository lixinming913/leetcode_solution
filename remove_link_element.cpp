/**
 *  Remove Linked List Elements 
 *  Remove all elements from a linked list of integers that have value val.
 *  Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
 *  Return: 1 --> 2 --> 3 --> 4 --> 5
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
    ListNode* removeElements(ListNode* head, int val) {
        while(head && head->val == val) {
            ListNode *del = head;
            head = head->next;
            free(del);
            del = NULL;
        }
        
        if(!head)
            return NULL;
            
        ListNode* pre = head;
        ListNode* cur = head->next;
        
        
        while(cur != NULL) {
            if(cur->val != val) {
                pre = cur;
                cur = cur->next;
            }
            else {
                ListNode* del = cur;
                pre->next = cur->next;
                cur = cur->next;
                free(del);
                del = NULL;
            }
        }
            
        return head;
    }
};