#include <stdio.h>
#include <stdlib.h>

struct ListNode {
      int val;
      struct ListNode *next;
  };

struct ListNode *head;

struct ListNode* reverseList(struct ListNode* head);
void Insert_at_end(struct ListNode **list,int num);
void Print(struct ListNode* list);

int main()
{
    struct ListNode *result=NULL;
    int i=0,data=0;

    printf("Enter list1 elements \n");

    for(i=0;i<5;i++)
    {
      scanf("%i",&data);
      Insert_at_end(&(head),data);
    }
    Print(head);

    result = reverseList(head);
    Print(result);

    return 0;
}

struct ListNode* reverseList(struct ListNode* head)
{

if(head == NULL)
    return NULL;
else
 {
    struct ListNode *prevNode=NULL;
    struct ListNode *currentNode = head;
    struct ListNode *nextNode =head->next;

    while(currentNode->next!=NULL)
    {
        currentNode->next=prevNode;

        prevNode=currentNode;
        currentNode=nextNode;
        nextNode=nextNode->next;
    }

    currentNode->next=prevNode;
    head=currentNode;

    return head;
 }
}
void Insert_at_end(struct ListNode **list,int num)
{
    struct ListNode* ptr=*list;
    struct ListNode* temp =(struct ListNode*)malloc(sizeof(struct ListNode));

    temp->val=num;
    temp->next=NULL;

    if(*list==NULL)
    {
        *list=temp;
    }
    else
    {
        while(ptr->next!=NULL)
        {
           ptr=ptr->next ;
        }
        ptr->next=temp;
    }
}

void Print(struct ListNode* list)
{
   struct ListNode* temp=list; //making a temp pointer to use it to print each node

   printf("The list is :");
    while (temp!=NULL)
    {
        printf("%d",temp->val);
        temp=temp->next;
    }
    printf("\n");
}

