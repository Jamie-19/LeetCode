/*
80. Remove Duplicates from Sorted Array II
Given an integer array nums sorted in non-decreasing order, remove some duplicates in-place such that each unique element appears at most twice. 
The relative order of the elements should be kept the same.
Since it is impossible to change the length of the array in some languages, you must instead have the result be placed in the first part of the array nums. 
More formally, if there are k elements after removing the duplicates, then the first k elements of nums should hold the final result. 
It does not matter what you leave beyond the first k elements.
Return k after placing the final result in the first k slots of nums.
*/
#include<stdio.h>
int removeDuplicates(int* nums, int numsSize);
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
    int k=removeDuplicates(nums,numsSize);
    printf("The majority element in nums is: %d",k);
    return 0;
}
int removeDuplicates(int* nums, int numsSize)
{
    int i,j=0;
    for(i=0;i<numsSize;i++)
    {
        if(i<2 || nums[i]>nums[j-2]) //if the index is less than 2 or the element is greater than the element at index j-2 then store the element at index j
        
        {
            nums[j++]=nums[i]; //storing the element at index j
        }

    }
    return j;
}
