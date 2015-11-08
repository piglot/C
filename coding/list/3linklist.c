#include <stdio.h>  
  
typedef struct LinkNode  
{  
    int data;  
    struct LinkNode *next;  
} Node;  
  
//非递归解法  
Node* reverse1(Node* header) {  
    Node* p = header->next;  
    header->next = NULL;  
    Node* q = p->next;  
    while(q) {  
        p->next = header;  
        header = p;  
        p = q;  
        q = p->next;  
    }  
  
    p->next = header;  
    header = p;  
    return header;  
}  
  
//递归解法  
Node* reverse2(Node* header) {  
    if(header == 0 || header->next == 0)  
        return header;  
  
    Node* p = header->next;  
    Node* q = reverse2(p);  
    p->next = header;  
    header->next = 0;  
    return q;  
}  
  
int main() {  
    Node h = {1, 0};  
    Node* head = &h;  
    Node node1 = {3, 0};  
    Node node2 = {2, 0};  
    Node node3 = {4, 0};  
    Node node4 = {7, 0};  
    Node node5 = {6, 0};  
    Node node6 = {5, 0};  
  
    head->next = &node1;  
    node1.next = &node2;  
    node2.next = &node3;  
    node3.next = &node4;  
    node4.next = &node5;  
    node5.next = &node6;  
    node6.next = NULL;  
  
    Node* p = reverse2(head);  
    while(p) {  
        printf("p->data = %d\n", p->data);  
        p = p->next;  
    }  
  
    return 0;  
}  
