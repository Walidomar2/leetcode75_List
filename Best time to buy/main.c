#include <stdio.h>
#include <stdlib.h>

int maxProfit(int* prices, int pricesSize);
int main()
{
    int result=0;
    int prices[6]={7,1,5,3,6,4};

    result = maxProfit(&(prices),6);

    printf("%d",result);

    return 0;
}
int maxProfit(int* prices, int pricesSize){
    int profit =0 ,lastProfit =0 ,i=0;
    int minPrice=prices[0];

    if(pricesSize == 1)
        return profit;

    for(i=1;i<pricesSize;i++)
    {
        if(minPrice < prices[i])
        {
            profit = prices[i]-minPrice;
            if(profit > lastProfit)
                lastProfit = profit;
        }
        else
        {
            minPrice = prices[i];
        }
    }

return lastProfit ;
}
