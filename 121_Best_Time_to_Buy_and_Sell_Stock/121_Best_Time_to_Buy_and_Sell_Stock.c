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
    printf("Enter the size of array: "); //taking input from user
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

        minprice=prices[0]; //storing the first element of the array in minprice
        
        for(int i=0;i<pricesSize;i++){

            if(prices[i] < minprice){  //if the element is less than the minprice then update the minprice
                
                minprice=prices[i]; //storing the element in minprice
            
            }
            else{
                  
                   if(prices[i]-minprice > maxprice){ //if the element minus the minprice is greater than the maxprice then update the maxprice
                  
                       maxprice=prices[i]-minprice; //storing the element minus the minprice in maxprice
                  
                   }
            }
        }
        if(maxprice==0){
            
            return 0; //if the maxprice is 0 then return 0
        
        }
        else{
            return maxprice;
        }

}  

// Time Complexity: O(n)
// Space Complexity: O(1)