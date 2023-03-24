#include <stdio.h>
#include <stdlib.h>

int search(int* nums, int numsSize, int target);

int main()
{
    int nums[2]={2,5};
    int value =0;
    int result=0;

    printf("Enter the number : \n");

    scanf("%i",&value);
    result=search(nums,2,value);
    printf("%i\n",result);
}

int search(int* nums, int numsSize, int target){
    int middleIndex =0;
    int leftIndex=0;
    int rightIndex = numsSize - 1;

    while (leftIndex <= rightIndex)
    {
        middleIndex= (rightIndex+leftIndex)/2;

        if(target==nums[middleIndex])
            return middleIndex;
        else if(target<nums[middleIndex])
            rightIndex=middleIndex-1;
        else 
            leftIndex=middleIndex+1;
    }

    return -1;
}