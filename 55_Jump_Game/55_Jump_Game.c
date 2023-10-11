/*
55.Jump Game
You are given an integer array nums. 
You are initially positioned at the array's first index,and each element in the array represents your maximum jump length at that position.
Return true if you can reach the last index, or false otherwise.
*/
#include<stdio.h>
#include<stdbool.h>
bool canJump(int* nums, int numsSize);
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
    bool k=canJump(nums,numsSize);
    if(k==true)
    {
        printf("true");
    }
    else
    {
        printf("false");
    }
    return 0;
}
bool canJump(int* nums, int numsSize){
    int max=0;
    for(int i=0;i<numsSize;i++){
        if(i>max){
            return false;
        }
        if(i+nums[i]>max){
            max=i+nums[i];
        }
    }
}