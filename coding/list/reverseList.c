/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/*Notes:  
    Programes below apply to linkedlist without head node.
Yao Ming
*/

//Recursive solution:
struct ListNode* reverseList(struct ListNode* head) {
    if(NULL==head || NULL==head->next){
        printf("The list is null.\n");
        return head;
    }
    
    struct ListNode* p=head->next;
    struct ListNode* newhead=reverseList(p);
    
    p->next=head;
    head->next=NULL;
    
    return newhead;
}

//using 3 pointers
struct ListNode* reverseList(struct ListNode* head) {
    if(NULL==head || NULL==head->next){
        return head;
    }
    
    struct ListNode *pre=NULL, *curr=head, *next=NULL;
    while(NULL!=curr){
        next=curr->next;
        curr->next=pre;
        pre=curr;
        curr=next;
    }
    head=pre;
    return head;
}

//Recursive solution using two pointers:
 struct ListNode* reverseListHelper(struct ListNode* pre, struct ListNode* curr){
    if(NULL==curr){
        return pre;
    }
    struct ListNode* newHead=reverseListHelper(curr, curr->next);
    curr->next=pre;
    return newHead;
}

struct ListNode* reverseList(struct ListNode* head) {
    if(NULL==head || NULL==head->next){
        return head;
    }else{
        return  reverseListHelper(NULL, head);
    }
}

