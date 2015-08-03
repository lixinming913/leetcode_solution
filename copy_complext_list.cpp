/**
 *  Copy List with Random Pointer 
 *  A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.
 */

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    void CloneNodes(RandomListNode *head) {
        RandomListNode *pnode = head;
        
        while(pnode != NULL) {
            RandomListNode *clone = new RandomListNode(0);
            clone->label          = pnode->label;
            clone->next           = pnode->next;
            clone->random         = NULL;
            
            pnode->next           = clone;
            
            pnode                 = pnode->next->next;
        }
    }
    
    void Connect_random(RandomListNode *head) {
        RandomListNode *pnode = head;
        while(pnode != NULL) {
            RandomListNode *clone = pnode->next;
            if(pnode->random != NULL) {
                clone->random = pnode->random->next;
            }
            
            pnode = clone->next;
        }
    }   
    
    RandomListNode *DividedClone(RandomListNode *head) {
        RandomListNode *new_head = NULL;
        RandomListNode *pnode    = head;
        RandomListNode *pclone   = NULL;
        
        if(pnode != NULL) {
            new_head = pclone = pnode->next;
            pnode->next = pclone->next;
            pnode = pnode->next;
        }
        
        while(pnode != NULL) {
            pclone->next = pnode->next;
            pclone = pclone->next;
            pnode->next = pclone->next;
            pnode = pnode->next;
        }
        
        return new_head;
    }
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head == NULL)
            return NULL;
            
        CloneNodes(head);
        Connect_random(head);
        return DividedClone(head);
        
    }
};