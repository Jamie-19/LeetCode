/*
189. Rotate Array
Given an integer array nums, 
rotate the array to the right by k steps, 
where k is non-negative.
*/

/*
// Method 1: Brute Force
#include<stdio.h>
void rotate(int* nums, int numsSize, int k);
int main()
{
    int nums[100],numsSize,i,k;
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
}*/
// Time Complexity: O(n*k)
// Space Complexity: O(1)

// Method 2: Using Extra Array

/*#include<stdio.h>
void rotate(int* nums, int numsSize, int k);
int main()
{
    int nums[100],numsSize,i,k;
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
    int i,j,temp[numsSize];
    for(i=0;i<numsSize;i++)
    {
        temp[(i+k)%numsSize]=nums[i];
    }
    for(i=0;i<numsSize;i++)
    {
        nums[i]=temp[i];
    }
}
// Time Complexity: O(n)
// Space Complexity: O(n)*/

// Method 3: Using Reverse

#include<stdio.h>
void rotate(int* nums, int numsSize, int k);
void reverse(int* nums, int start, int end);
int main()
{
    int nums[100],numsSize,i,k;
    printf("Enter the size of array: "); //taking input from user
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
void rotate(int* nums, int numsSize, int k) //using reverse function
{
    k=k%numsSize; 
    reverse(nums,0,numsSize-1);
    reverse(nums,0,k-1);
    reverse(nums,k,numsSize-1);
}
void reverse(int* nums, int start, int end) //reverse function
{
    int temp;
    while(start<end) //using two pointer approach
    {
        //swapping the elements
        temp=nums[start]; 
        nums[start]=nums[end]; 
        nums[end]=temp;
        //incrementing the start and decrementing the end
        start++;
        end--;
    }
}
// Time Complexity: O(n)
// Space Complexity: O(1)