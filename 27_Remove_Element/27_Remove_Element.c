/*
27.Remove an element
Given an array nums and a value val, 
remove all instances of that value in-place and return the new length.    
*/

#include<stdio.h>   
int removeElement(int* nums, int numsSize, int val);
int main()
{
    int nums[100],numsSize,val,i;
    printf("Enter the size of array: ");
    scanf("%d",&numsSize);
    printf("Enter the elements of array: ");
    for(i=0;i<numsSize;i++)
    {
        scanf("%d",&nums[i]);
    }
    printf("Enter the value to be removed: ");
    scanf("%d",&val);
    int k=removeElement(nums,numsSize,val);
    printf("The number of elements in nums which are not equal to val are: %d",k);
    for(i=0;i<k;i++)
    {
        printf("\n%d \t",nums[i]);
    }
    return 0;
}

int removeElement(int* nums, int numsSize, int val)
{
    {
        int k=0,i;
        for(i=0;i<numsSize;i++)
        {
            if(nums[i]!=val)
            {
                nums[k]=nums[i];
                k+=1;
            }
        }
        return k;
    }
}