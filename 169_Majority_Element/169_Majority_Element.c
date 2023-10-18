/*
169.Majority Element:
Given an array nums of size n, return the majority element.
*/

#include<stdio.h>
int majorityElement(int* nums, int numsSize);
int main()
{
    int nums[100],numsSize,i;
    printf("Enter the size of array: "); //taking input from user
    scanf("%d",&numsSize);
    printf("Enter the elements of array: ");
    for(i=0;i<numsSize;i++)
    {
        scanf("%d",&nums[i]);
    }
    int k=majorityElement(nums,numsSize);
    printf("The majority element in nums is: %d",k);
    return 0;
}
int majorityElement(int* nums, int numsSize)
{
    int cnt=0,sol=nums[0],i;
    for(i=0;i<numsSize;i++) //using Moore's Voting Algorithm
    {
        if(cnt==0) //if count is equal to 0 then store the element at index i in sol and increment the count
        {
            sol=nums[i]; //storing the element at index i in sol
            cnt=1; //incrementing the count
        }
        else if(sol==nums[i]) //if the element at index i is equal to sol then increment the count
        {
            cnt++;
        }
        else{ //else decrement the count
            cnt--;
        }
        
        int count=0;

        for(i=0;i,numsSize;i++) //checking if the sol is the majority element or not
        {
            if(nums[i]==sol) //if the element at index i is equal to sol then increment the count
            {
                count++;
            }
        }
        if(count>numsSize/2) //if the count is greater than numsSize/2 then return the count
            return count;
        else
            return printf("No majority element");
    }

}