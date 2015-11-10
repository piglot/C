#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 40
	
typedef int ElemType;

typedef struct node
{
    ElemType value;
    struct node *next;
}Node, * Linkedlist;

Linkedlist linklist_create_head(void);
Linkedlist linklist_create_tail(void);
int linklist_print(Linkedlist head);
void linklist_print_reverse(Linkedlist head);
Linkedlist linklist_reverse(Linkedlist head);
Linkedlist linklist_insert(Linkedlist head, int location, ElemType value);
Linkedlist delete_elem_by_value(Linkedlist head, ElemType value);
Linkedlist delete_elem_by_location(Linkedlist head, ElemType value);
Node *get_elem_by_location(Linkedlist head, int location);
Node *get_elem_by_value(Linkedlist head, ElemType value);
int get_int(void);
char get_char(void);

//
Linkedlist linklist_reverse(Linkedlist head)
{
    if(NULL==head || NULL==head->next)
    {
        printf("The list is null.\n");
        return head;  
    }
    Node *p,*q,*r;
    p=head->next;
    q=p->next;
    p->next=NULL;
    while(NULL!=q)
    {
        r=q->next;
        q->next=p;
        p=q;
        q=r;
    }
    head->next=p;
    return head;
}

//
int linklist_print(Linkedlist head)
{
    if(NULL==head || NULL==head->next)
    {
        printf("The list is null.\n");
        return 0;  
    }
    printf("Link list:  ");
    Node *p=head->next;
    while(NULL != p)
    {
        printf("%d ", p->value);
        p=p->next;
    }
    printf("\n");
        return 0;
}

//
void linklist_print_reverse(Linkedlist head)
{
    if(NULL!=head){
        if(head->next!=NULL){
            linklist_print_reverse(head->next);
        }
    printf("%d ",head->value);
    }
}
    
/*
void linklist_print_reverse2(Linkedlist head)
{
    std::stack<Linkedlist> list;
    
    Node *p=head;
    while(p!==NULL)
    {
        list.push(p);
        p=p->next;
    }

    while(!list.empty())
    {
        p=list.top();
        printf("%d ",p->value);
        list.pop();
    }
}
*/

//
Linkedlist linklist_create_head(void)
{
    Node *head=(Node *)malloc(sizeof(Node)); //create head node and head pointer
    if(NULL==head)
        return head;
    head->next=NULL;

    int i=0;
    ElemType value[MAXSIZE];

    printf("Please input values of nodes.\n");
    while(1)
    {
        scanf("%d", &value[i]);
        Node *p=(Node *)malloc(sizeof(Node));
        if(NULL==p)
            break;
        p->value=value[i++];
        p->next=head->next;
        head->next=p;

        if(getchar()=='\n')  //press "Enter" to ends input
            break;
    }
    return head;
}
    
//
Linkedlist linklist_create_tail(void)
{
    Node *head=(Node *)malloc(sizeof(Node));//create head node and head pointer
    if(NULL==head)
        return head;
    head->next=NULL;
    Node *tail=head; //tail pointer

    int i=0;
    ElemType value[MAXSIZE];

    printf("Please input values of nodes.\n");
    while(1)
    {
        scanf("%d", &value[i]);
        Node *p=(Node *)malloc(sizeof(Node));
        p->value=value[i++];
        tail->next=p;
        p->next=NULL;
        tail=p;

        if(getchar()=='\n') //press "Enter" to ends input
            break;
    }   
    return head;
}

//
Linkedlist linklist_insert(Linkedlist head, int location, ElemType value)
{
    Node *pre=get_elem_by_location(head, location-1); //get pre point of location node
    if(NULL==pre)
        return NULL;
    Node *p=(Node *)malloc(sizeof(Node));
    if(NULL==p)
       return NULL;
    p->value=value;
    p->next=pre->next;
    pre->next=p;

    return head;
}
    
    

//
Linkedlist delete_elem_by_value(Linkedlist head, ElemType value)
{
    if(NULL==head || NULL==head->next)
    {
         printf("The list is NULL!\n");
         return NULL;
    }

    Node *pre,*p=head->next;
    while(NULL!=p && p->value!=value)  //
    {
        pre=p;
        p=p->next;
    }
    if(NULL==p) //no value matched from head to tail
    {
        printf("Can't find node value: %d\n", value);
        return NULL;
    }
    pre->next=p->next;  //delete action
    free(p); //release deleted node pointer
    return head;
}


//
Node *get_elem_by_location(Linkedlist head, int location)
{
    if(NULL==head || NULL==head->next)  //list is NULL 
    {
         printf("The list is NULL!\n");
         return NULL;
    }

    if(location<1)  //location error
    {
        printf("location error.\n"); 
        return NULL;
    }

    int i=1;
    Node *p=head->next;
    while(NULL!=p && i<location)
    {
        p=p->next;
        i++;
    }
    if(NULL==p)  //location over the length of list
        printf("location error.\n"); 
    return p;
}

//
Node *get_elem_by_value(Linkedlist head, ElemType value)
{
    if(NULL==head || NULL==head->next)  //list is NULL 
    {
         printf("The list is NULL!\n");
         return NULL;
    }
 
    Node *p=head->next;
    while(NULL!=p && value!=p->value)
        p=p->next;
    if(NULL==p)  //no value matched form head to tail
    {
        printf("Can't find node value: %d\n", value);
        return NULL;
    }
    return p;
}

//
int get_int(void)
{
    int input;
    char ch;

    while(scanf("%d",&input)!=1)  //check if input is an interger.
    {
        while((ch=getchar())!='\n')
            putchar(ch);
        printf(" is not an interger. Please re-enter!\n");
    }
    while((getchar())!='\n'); //clear input buffer(other characters and '\n')
    return input;
}

//
char get_char(void)
{
    char input;
    char ch;

    while(scanf("%c",&input)!=1) //check if is a char
    {
        while((ch=getchar())!='\n')
            putchar(ch);
        printf(" is not a character. Please re-enter!\n");
    }
    while((getchar())!='\n'); //clear input buffer(other characters and '\n')
    return input;
}


//
int main()
{

   
    char a,b;
    int cycle=1;
    Linkedlist ph;

    printf("Please input:\n\
	h ----> head create link list'\n\
	t ----> tail create link list\n");
    while(cycle)
    {
        a=get_char();
        switch(a)
        {
            case 'h':
                ph=linklist_create_head();
                cycle=0;
                break;
            case 't':
                ph=linklist_create_tail();
                cycle=0;
                break;
            default:
               printf("Error. Please input 'h' or 't'.\n");
               break;
        }
    }
    linklist_print(ph);

    cycle=1;
    while(cycle)
    {
        printf("Please choose:\n\
            q ----> quit choose\n\
            g ----> get element by giving value\n\
            l ----> get element by giving location\n\
            r ----> reverse link list\n\
            p ----> print link list\n\
            P ----> print reverse link list\n\
            i ----> insert node to link list\n\
            d ----> delete node from link list\n");
        b=get_char();
        switch(b)
        {
            case 'l':
                printf("Input location:\n");
                int l_location=get_int();
                Node *p_l=get_elem_by_location(ph,l_location);
                if(NULL!=p_l)
                    printf("The value of %dth node is: %d\n",l_location,p_l->value);
                break;
            case 'i':
                printf("Input location to insert:\n");
                int i_location=get_int();
                printf("Input value of node:\n");
                ElemType i_value=get_int();
                linklist_insert(ph,i_location,i_value);
                linklist_print(ph);
                break;
            case 'r':
                linklist_reverse(ph);
                linklist_print(ph);
                break;
            case 'p':
                linklist_print(ph);
                break;
            case 'P':
                if(NULL==ph || NULL==ph)  //list is NULL
                {
                     printf("The list is NULL!\n");
                     break;
                }
                printf("reverse linklist:  ");
                linklist_print_reverse(ph->next);
                printf("\n");
                break;
            case 'd':
                printf("Please input value of node to delete:\n");
                ElemType d_value=get_int();
                delete_elem_by_value(ph,d_value);
                printf("Link list delete (%d):\n", d_value);
                linklist_print(ph);
                break;
            case 'q':
               cycle=0;
               break;
            default:
               break;
        }
    }
       
    return 0;
}


