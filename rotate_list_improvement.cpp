/**
 *  Rotate List  
 *  This solution is faster than rotate_list.c, It make a circle linked
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
    ListNode* rotateRight(ListNode* head, int k)  {
        if(head==NULL ||head->next==NULL||k==0)
            return head;
        
        int n = 1;
        ListNode* head1 = head;
        ListNode* head2 = NULL;
        while(head1->next != NULL){
            head1 = head1->next;
            n++;
        }
    
        head1->next = head;
        k %= n;
        int m = n-k;
    
        if(k) {
            while(m--)
                head1 = head1->next;
        }
        head2 = head1->next;
        head1->next = NULL;
    
        return head2;
    }
};