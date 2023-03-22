#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
 };

void GetDepth(struct TreeNode* root,int currentDepth,int* returnDepth);
void traverse(struct TreeNode* root,int** arr,int* column,int depth);
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes);

int main()
{
    return 0;
}

void GetDepth(struct TreeNode* root,int currentDepth,int* returnDepth)
{
    if(currentDepth>*returnDepth)
        *returnDepth=currentDepth;

    if(NULL == root)
        return ;

    GetDepth(root->left,currentDepth+1,returnDepth);
    GetDepth(root->right,currentDepth+1,returnDepth);
}

void traverse(struct TreeNode* root,int** arr,int* column,int depth)
{
    if(root==NULL)
        return;

    arr[depth][column[depth]++]=root->val;
    traverse(root->left, arr, column, depth+1);
    traverse(root->right, arr, column, depth+1);

}

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes)
{

    *returnSize=0;

    GetDepth(root,0,returnSize);

    int** resultArr = (int**)malloc((*returnSize)*sizeof(int*)); //Array of pointers to arrays

    for(int i=0;i<(*returnSize);i++)
    {
        resultArr[i]=(int*)malloc(1024*sizeof(int*));
    }

    *returnColumnSizes =  (int*)calloc((*returnSize), sizeof(int*));
    traverse(root, resultArr, *returnColumnSizes, 0);
    return resultArr;
}
