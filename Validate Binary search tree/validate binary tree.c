#include<stdio.h>
#include<stdbool.h>

#define LONG_MIN    (-2147483647 - 1)
#define LONG_MAX    2147483647

struct TreeNode
{
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
};


int main()
{
    return 0;
}


bool traverse(struct TreeNode* root,long min,long max)
{
  if (!root) 
    return true;

  int value = root->val;

  if (value >= max || value <= min)
    return false;

  return traverse(root->left, min, value) && traverse(root->right, value, max);
}

bool isValidBST(struct TreeNode* root){
     return traverse(root,LONG_MIN,LONG_MAX);
    
}