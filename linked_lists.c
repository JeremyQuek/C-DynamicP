
#include "stdlib.h"
#include "stdio.h"

typedef struct node{
    int item;
    struct node *next;
} Listnode;

int main(void) {
    Listnode *head=NULL, *temp, *tail;
    int i;
    printf("Enter your digit: ");
    scanf(" %d", &i);
    while (i!=-1) {
        if (head==NULL) {
            head = malloc(sizeof(Listnode));
            head->item=i;
            tail=head;
        }
        else {
            tail->next=malloc(sizeof(Listnode));
            tail=tail->next;
        }
        tail->item=i;
        printf("Enter your digit: ");
        scanf(" %d", &i);
    }
    tail->next=NULL;

    temp = malloc(sizeof(Listnode));
    temp = head;
    do {
        printf("%d, ", temp->item);
        temp=temp->next; 
    } while (temp);
}


/////

typedef struct _listnode
{
	int item;
	struct _listnode *next;
} ListNode;			// You should not change the definition of ListNode

typedef struct _linkedlist
{
	int size;
	ListNode *head;
} LinkedList;			// You should not change the definition of LinkedList

void removeNode(ListNode **ptrHead, int index) {
    ListNode *cur=*ptrHead, *prev=NULL;
    int i = 0;
    if (index==0) {
        *ptrHead = cur->next;
        free(cur);
        return;
    }
    while (cur) {
        if (i == index) {
            prev->next=cur->next;
            free(cur);
        }
        prev=cur;
        cur=cur->next;
        i++
    }
}

// In C, when you want a function to be able to modify a pointer that is passed as an argument,
// you need to pass a pointer to that pointer. This is because C uses pass-by-value for function arguments.

int insertNode(ListNode **ptrHead, int index, int value){
    ListNode *pre, *cur; 
    int i =1;
    pre = *ptrHead;
    while (pre) {
        if (i==index) {
            cur= malloc(sizeof(ListNode));
            cur->item=value;
            cur->next=pre->next;
            pre->next=cur;
            return 0;
        }
        pre=pre->next;
        i++;
    }
    return -1;
}
