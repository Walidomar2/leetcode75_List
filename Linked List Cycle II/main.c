#include <stdio.h>
#include <stdlib.h>

struct ListNode{
    int val;
    struct ListNode *next;
};

int main()
{
    return 0;
}
struct ListNode *detectCycle(struct ListNode *head) {
    if(head == NULL || head->next == NULL)
        return NULL;

    struct ListNode *slowPtr = head; // it jump one node at a time
    struct ListNode *fastPtr = head; // it jump two nodes at a time

    while(fastPtr != NULL && fastPtr->next != NULL)
    {
        slowPtr=slowPtr->next;
        fastPtr=fastPtr->next->next;

        if(slowPtr==fastPtr)
            break;
    }

    if(fastPtr==NULL || fastPtr->next == NULL)
        return NULL;

    fastPtr=head;
    while(fastPtr!=slowPtr)
    {
        slowPtr=slowPtr->next;
        fastPtr=fastPtr->next;
    }
    return fastPtr;
}
