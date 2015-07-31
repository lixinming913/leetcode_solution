/**
 *  Add Two Numbers 
 *  You are given two linked lists representing two non-negative numbers. 
 *  The digits are stored in reverse order and each of their nodes contain a single digit.
 *  Add the two numbers and return it as a linked list.
 *  Input: (2 -> 4-> 3) + (5 -> 6 -> 4)
 *  Output: 7 -> 0 -> 8
 **/

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
 
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       
        if(l1 == NULL && l2 == NULL)
            return NULL;

        
        ListNode *list = new ListNode(-1);
        ListNode *pre = NULL;
        list->next = pre;
        
        int flag = 0;
        
        ListNode *p1 = l1;
        ListNode *p2 = l2;
        
        while(p1 && p2) {
            int key = 0;
            ListNode *pnew = (ListNode *)malloc(sizeof(ListNode));
            
            key = p1->val + p2->val + flag;
            flag = 0;
            
            if(key >= 10) {
                flag = 1;
                key -= 10;
                pnew->val = key;
                pnew->next = NULL;
            } else {
                pnew->val = key;
                pnew->next = NULL;
            }
            
            
            
            if(pre == NULL)
                list->next = pnew;
            else
                pre->next = pnew;
                
            pre = pnew;
            
            p1 = p1->next;
            p2 = p2->next;
        }
        
        while(p1 != NULL) {
            int key = p1->val + flag;
            
            flag = key / 10;
            key = key % 10;
            ListNode *pnew = new ListNode(key);
            pnew->next = NULL;
            
            pre->next = pnew;
            pre = pnew;
            p1 = p1->next;
        }
        
        while(p2 != NULL) {
            int key = p2->val + flag;
            flag = key / 10;
            key = key % 10;
            
            ListNode *pnew = new ListNode(key);
            pnew->next = NULL;
            
            pre->next = pnew;
            pre = pnew;
            p2 = p2->next;
        }
        
        if(flag != 0) {
            ListNode *pnew = new ListNode(flag);
            pnew->next = NULL;
            
            pre->next = pnew;
        }
         
        return list->next;   
    }
};