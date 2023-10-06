/*
Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same. Then return the number of unique elements in nums.

Consider the number of unique elements of nums to be k, to get accepted, you need to do the following things:

Change the array nums such that the first k elements of nums contain the unique elements in the order they were present in nums initially. The remaining elements of nums are not important as well as the size of nums.
Return k.
*/
#include<stdio.h>
int removeDuplicates(int* nums, int numsSize);
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
    int k=removeDuplicates(nums,numsSize);
    printf("The number of unique elements in nums are: %d",k);
    for(i=0;i<k;i++)
    {
        printf("\n%d \t",nums[i]);
    }
    return 0;
}
int removeDuplicates(int* nums, int numsSize)
{
    int k=0,i;
    for(i=0;i<numsSize;i++)
    {
        if(nums[i]!=nums[i+1])
        {
            nums[k]=nums[i];
            k+=1;
        }
    }
    return k;
}