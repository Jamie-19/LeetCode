/*
274.H-Index
Given an array of integers citations where citations[i] is the number of citations a researcher received for their ith paper, 
return the researcher's h-index.
The h-index is defined as the maximum value of h such that the given researcher has published at least h papers that have each been cited at least h times.
*/

#include<stdio.h>
void rotate(int* nums, int numsSize, int k);
int main()
{
    int nums[100],numsSize,i,k;
    //int nums[]={3,2,2,3};
    //taking input from user
    printf("Enter the size of array: ");
    scanf("%d",&numsSize);
    printf("Enter the elements of array: ");
    for(i=0;i<numsSize;i++)
    {
        scanf("%d",&nums[i]);
    }
    printf("Enter the value of k: ");
    scanf("%d",&k);
    rotate(nums,numsSize,k);
    printf("The rotated array is: ");
    for(i=0;i<numsSize;i++)
    {
        printf("%d ",nums[i]);
    }
    return 0;
}

void rotate(int* nums, int numsSize, int k)
{
    int i,j,temp;
    for(i=0;i<k;i++)
    {
        temp=nums[numsSize-1];
        for(j=numsSize-1;j>0;j--)
        {
            nums[j]=nums[j-1];
        }
        nums[0]=temp;
    }
}

// Time Complexity: O(n*k)
// Space Complexity: O(1)



