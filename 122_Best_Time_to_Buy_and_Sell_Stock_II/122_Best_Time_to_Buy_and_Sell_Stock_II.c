/*
122.Best Time to Buy and Sell Stock II
You are given an integer array prices where prices[i] is the price of a given stock on the ith day.
On each day, you may decide to buy and/or sell the stock. 
You can only hold at most one share of the stock at any time. 
However, you can buy it then immediately sell it on the same day.
Find and return the maximum profit you can achieve.
*/


#include<stdio.h>
int maxProfit(int* prices, int pricesSize);
int main()
{
    int prices[100],pricesSize,i;
    printf("Enter the size of array: ");
    scanf("%d",&pricesSize);
    printf("Enter the elements of array: ");
    for(i=0;i<pricesSize;i++)
    {
        scanf("%d",&prices[i]);
    }
    int k=maxProfit(prices,pricesSize);
    printf("The maximum profit is: %d",k);
    return 0;
}

int maxProfit(int* prices, int pricesSize){
        int profit=0;
        for(int i=1;i<pricesSize;i++){
            if(prices[i] > prices[i-1]){
                profit+=prices[i]-prices[i-1];
            }
        }
        return profit;
}