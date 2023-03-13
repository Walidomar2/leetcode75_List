#include <stdio.h>
#include <stdlib.h>

int pivotIndex(int* nums, int numsSize);

int main()
{
    int nums[]={1,7,3,6,5,6};
    int index = 0;

    index = pivotIndex(&nums ,6);

    printf("index = %i ",index);

    return 0;
}

int pivotIndex(int* nums, int numsSize){

   int num=0,lsum=0,rsum=0,flag=0;
    for(int i=0;i<numsSize;i++)
    {
        lsum=0,rsum=0;
        for(int j=0;j<i;j++)
        lsum+=nums[j];
        for(int k=i+1;k<numsSize;k++)
            rsum+=nums[k];

        if(lsum==rsum){
            num=i;
            flag=1;
            break;
        }


    }
    if(flag==0)  return -1;
    return num;
}
