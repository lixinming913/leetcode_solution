/**
 *  Merge k Sorted Lists 
 *  Merge k sorted linked lists and return it as one sorted list. 
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL)
            return l2;
            
        if(l2 == NULL)
            return l1;
            
        ListNode* merge_head = NULL;
        if(l1->val < l2->val) {
            merge_head = l1;
            merge_head->next = mergeTwoLists(l1->next, l2);
        } else {
            merge_head = l2;
            merge_head->next = mergeTwoLists(l1, l2->next);
        }
        
        return merge_head;
    }
    
    ListNode* merge(vector<ListNode *> &lists, int left, int right) {
        if(left == right)
            return lists[left];
        else if(left + 1 == right)
            return mergeTwoLists(lists[left], lists[right]);
            
        ListNode* l1 = merge(lists, left, (left+right)/2);
        ListNode* l2 = merge(lists, (left+right)/2 + 1, right);
        return mergeTwoLists(l1, l2);
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty())
            return NULL;
        
        int size = lists.size();
        if(size == 1) 
            return lists[0];
        
        return merge(lists, 0, size-1);
    }
};