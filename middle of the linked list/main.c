#include <stdio.h>
#include <stdlib.h>

struct ListNode{
    int val;
    struct ListNode* next;
};
struct ListNode *head;
struct ListNode *Result ;
struct ListNode* middleNode(struct ListNode* head);
void Insert_at_end(struct ListNode **list,int num);
void Print(struct ListNode* list);

int main()
{
    int data=0;
    for(int i=0;i<7;i++)
    {
      scanf("%i",&data);
      Insert_at_end(&(head),data);
    }
    Print(head);

    Result= middleNode(head);
    Print(Result);

    return 0;
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

struct ListNode* middleNode(struct ListNode* head)
{
    if(head == NULL)
    {
        return NULL;
    }
    else
    {
        unsigned int counter = 1;
        struct ListNode *ptr = head;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
            counter++;
        }

        if(counter%2==0)
        {
            counter = counter / 2;
            ptr = head;
            for(int i=0;i<counter;i++)
            {
                ptr=ptr->next;
            }
            head = ptr;
            return head;

        }
        else
        {
            counter=(int)(counter/2);
            ptr = head;
            for(int i=0;i<counter;i++)
            {
                ptr=ptr->next;
            }
            head = ptr;
            return head;
        }

    }

}
