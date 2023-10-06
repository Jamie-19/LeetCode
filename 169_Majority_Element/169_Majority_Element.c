/*
169.Majority Element:
Given an array nums of size n, return the majority element.
*/
#include<stdio.h>
int majorityElement(int* nums, int numsSize);
int main()
{
    int nums[100],numsSize,i;
    printf("Enter the size of array: ");
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
    for(i=0;i<numsSize;i++)
    {
        if(cnt==0)
        {
            sol=nums[i];
            cnt=1;
        }
        else if(sol==nums[i])
        {
            cnt++;
        }
        else{
            cnt--;
        }
        int count=0;
        for(i=0;i,numsSize;i++)
        {
            if(nums[i]==sol)
            {
                count++;
            }
        }
        if(count>numsSize/2)
            return sol;
        else
            return -1;
    }

}