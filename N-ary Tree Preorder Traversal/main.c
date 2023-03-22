#include <stdio.h>
#include <stdlib.h>

struct Node {
     int val;
     int numChildren;
     struct Node** children;
  };

int NodesCounter(struct Node* root);
void StoreElements(struct Node* root,int* arr,int* pos);
int* preorder(struct Node* root, int* returnSize);


int main()
{

    return 0;
}

int NodesCounter(struct Node* root)
{
    if(NULL==root)
        return NULL;

    int i=0,counter=0;
    for(i=0;i<root->numChildren;i++)
    {
        counter+=NodesCounter(root->children[i]);
    }

    return counter+1;
}

void StoreElements(struct Node* root,int* arr,int* pos)
{
    if(NULL == root || NULL == arr)
        return;

    int i=0;

    arr[*pos]=root->val;
    *pos = *pos + 1;
    for(i=0;i<root->numChildren;i++)
    {
        StoreElements(root->children[i],arr,pos);
    }

    return;
}

int* preorder(struct Node* root, int* returnSize)
{
    int *resultArr,i=0;

    *returnSize = NodesCounter(root);
    resultArr=(int *)malloc(*returnSize * sizeof(int));

    StoreElements(root,resultArr,&i);

    return resultArr;
}
