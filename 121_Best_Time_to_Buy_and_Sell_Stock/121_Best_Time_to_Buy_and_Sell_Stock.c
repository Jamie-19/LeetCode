/*
121.Best Time to Buy and Sell Stock
You are given an array prices where prices[i] is the price of a given stock on the ith day.
You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock
Return the maximum profit you can achieve from this transaction. 
If you cannot achieve any profit, return 0
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
        int maxprice=0,minprice;
        minprice=prices[0];
        for(int i=0;i<pricesSize;i++){
            if(prices[i] < minprice){
                minprice=prices[i];
            }
            else{
                   if(prices[i]-minprice > maxprice){
                       maxprice=prices[i]-minprice;
                   }
            }
        }
        if(maxprice==0){
            return 0;
        }
        else{
            return maxprice;
        }

}  

// Time Complexity: O(n)
// Space Complexity: O(1)