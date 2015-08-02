/**
 *  Reorder List 
 *  Given a singly linked list L: L0→L1→…→Ln-1→Ln,
 *  reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
 *  You must do this in-place without altering the nodes' values.
 *  Given {1,2,3,4}, reorder it to {1,4,2,3}.
 */


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void reorderList(struct ListNode* head) {
    if(head == NULL)
        return;
        
    struct ListNode *slow = head;
    struct ListNode *fast = head;
    
    while(fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }
    
    struct ListNode *head2 = slow->next;
    slow->next = NULL;
    struct ListNode *pre = NULL;
    struct ListNode *cur = head2;
    
    while(cur != NULL) {
        struct ListNode *pnext = cur->next;
        cur->next = pre;
        pre = cur;
        cur = pnext;
    }
    
    head2 = pre;
    struct ListNode *p1 = head;
    struct ListNode *p2 = head2;
    while(p1 && p2) {
        struct ListNode *tmp1 = p1->next;
        p1->next = p2;
        p1 = tmp1;
        
        struct ListNode *tmp2 = p2->next;
        p2->next = tmp1;
        p2 = tmp2;
    }
    
   
    
}