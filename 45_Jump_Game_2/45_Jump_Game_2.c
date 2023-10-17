/* 
45.Jump Game II
You are given a 0-indexed array of integers nums of length n. 
You are initially positioned at nums[0].
Each element nums[i] represents the maximum length of a forward jump from index i. 
In other words, if you are at nums[i], you can jump to any nums[i + j] where:

1.0 <= j <= nums[i]
2.i + j < n

Return the minimum number of jumps to reach nums[n - 1].
*/

#include<stdio.h>
int jump(int* nums, int numsSize);
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
    int k=jump(nums,numsSize);
    printf("%d",k);
    return 0;
}

int jump(int* nums, int numsSize){
    int l=0,r=0,count=0;
    while(r<numsSize-1){
        int max=0;
        for(int i=l;i<=r;i++){
            if(i+nums[i]>max){
                max=i+nums[i];
            }
        }
        l=r+1;
        r=max;
        count++;
    }
    return count;

}
