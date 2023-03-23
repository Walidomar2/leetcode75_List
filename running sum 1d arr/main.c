#include <stdio.h>
#include <stdlib.h>

int* runningSum(int* nums, int numsSize, int* returnSize);

int main()
{
    int numArr[4]={1,2,3,4};
    int arrSize = (sizeof(numArr)/sizeof(int));
    int i=0,resultsize=0;

    int* resultptr = runningSum(numArr,arrSize,&resultsize);

    for(i=0;i<arrSize;i++)
    {
        printf("%i\t",*(resultptr+i));
    }

    return 0;
}

int* runningSum(int* nums, int numsSize, int* returnSize){

int i=0;
int *resultArr =malloc(sizeof(int)*numsSize);

resultArr[0] = nums[0];

for(i=1;i<numsSize;i++)
    {
       resultArr[i]=resultArr[i-1]+nums[i];
    }
    *returnSize = numsSize;
return resultArr;
}
