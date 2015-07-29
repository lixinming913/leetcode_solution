/**
 *  Rotate List 
 *  Given a list, rotate the list to the right by k places, where k is non-negative.
 *  Given 1->2->3->4->5->NULL and k = 2, return 4->5->1->2->3->NULL.
 */


#include<stdio.h>
#include<stdlib.h>

/*单链表基本结构*/
struct ListNode {
    int         m_key;
    ListNode   *next;    
};

ListNode *
create(int m)
{
    ListNode *pNode = (ListNode *)malloc(sizeof(ListNode));
  
    pNode->m_key = m;
    pNode->next = NULL;
        
    return pNode;
}


void 
connect(ListNode *pNode1, ListNode *pNode2)
{
    if(!pNode1)
        return;
    
    pNode1->next = pNode2;
}


/*反转链表*/
ListNode* 
rotate(ListNode* head)
{
    if(head->next == NULL)
        return head;
    
    ListNode* pre = NULL;
    ListNode* pnode = head;
        
    while(pnode) {
        ListNode *pnext = pnode->next;
        pnode->next = pre;
        pre = pnode;
        pnode = pnext;
    }
        
    return pre;
}

/*将链表末尾数字移动到链表前端，移动k次*/
ListNode* 
rotateRight(ListNode* head, int k) 
{
        if(k <= 0 || head == NULL || head->next == NULL)
            return head;

        ListNode *p1 = head;
		int n = 0;
        while(p1) {
            p1 = p1->next;
            n++;
        }
        
        k = k % (n );
		if(k == 0)
			return head;

        ListNode *new_head = rotate(head);
        ListNode *p2 = NULL;
        ListNode *left_head = NULL;
        ListNode *right_head = NULL;

        p1 = new_head;
        while(k && p1->next != NULL) {
            p2 = p1;
            p1 = p1->next;
            k--;
        }
        
        
        p2->next = NULL;
        left_head = rotate(new_head);
        right_head = rotate(p1);
            
        ListNode *tmp = left_head;
        while(tmp->next != NULL) {
            tmp = tmp->next;
        }
        tmp->next = right_head;
        
       return left_head;
    }

    
/*打印链表*/
void 
print(ListNode **head)
{
    if(*head == NULL)
        return;
        
    ListNode *pNode = *head;
    while(pNode != NULL) {
        printf("%d ", pNode->m_key);
		pNode = pNode->next;
    }
}


/*测试输出*/
void
test()
{
    ListNode *pNode1 = create(1);
    ListNode *pNode2 = create(2);
    ListNode *pNode3 = create(3);    
    ListNode *pNode4 = create(4);   
    ListNode *pNode5 = create(5);    
    ListNode *pNode6 = create(6);
    
    connect(pNode1, pNode2);
    connect(pNode2, pNode3);
    connect(pNode3, pNode4);
    connect(pNode4, pNode5);
    connect(pNode5, pNode6);
    
    print(&pNode1);
    printf("\n");
    
    pNode1= rotateRight(pNode1, 2) ;
    
    print(&pNode1);
    printf("\n");
}


int
main()
{
    test();
    
    return 0;
}