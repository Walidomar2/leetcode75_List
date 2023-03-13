#include <stdio.h>
#include <stdlib.h>

struct ListNode {
      int val;
      struct ListNode *next;
  };

struct ListNode *head;
struct ListNode *list11=NULL;
struct ListNode *list22=NULL;

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2);
void Insert_at_end(struct ListNode **list,int num);
void Print(struct ListNode* list);

int main()
{
    int i=0,data=0;

    printf("Enter list1 elements \n");
    for(i=0;i<3;i++)
    {
      scanf("%i",&data);
      Insert_at_end(&(list11),data);
    }

    printf("Enter list2 elements \n");
    for(i=0;i<3;i++)
    {
      scanf("%i",&data);
      Insert_at_end(&(list22),data);
    }

    head = mergeTwoLists(list11,list22);
    Print(head);
    //Print(list11);
    //Print(list22);

    return 0;
}

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){

    struct ListNode *result = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *prevNode = result;

    while((list1 != NULL)&&(list2 != NULL))
    {
        if(list1->val < list2->val)
        {
            prevNode->next=list1;
            list1=list1->next;
        }
        else
        {
            prevNode->next=list2;
            list2=list2->next;
        }
        prevNode=prevNode->next;
    }

    if(list1 == NULL)
    {
        prevNode->next = list2;

    }
     if(list2 == NULL)
    {
        prevNode->next = list1;
    }
    result=result->next;
    return result;
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
