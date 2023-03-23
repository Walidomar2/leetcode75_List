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
    int middleIndex = (int)(numsSize/2);
    
    if(target == nums[middleIndex])
    {
        return middleIndex;
    }
    else if(target > nums[middleIndex])
    {
        for(int i=middleIndex +1; i<numsSize; i++)
        {
            if(target==nums[i])
                return i;
        }

        return -1;
    }
    else 
    {
        for(int i=0; i < middleIndex; i++)
        {
            if(target==nums[i])
                return i;
        }
        return -1;
    }


}