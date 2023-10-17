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
int main()  //main function
{
    int nums[100],numsSize,i;
    printf("Enter the size of array: "); //taking input from user
    scanf("%d",&numsSize);
    printf("Enter the elements of array: "); //taking the elements of array from user
    for(i=0;i<numsSize;i++)
    {
        scanf("%d",&nums[i]);
    }
    int k=jump(nums,numsSize);
    printf("%d",k);
    return 0;
}

int jump(int* nums, int numsSize){
    int count=0; //for counting the number of jumps

    int max=0; //for storing the maximum jump
 
    int lastjump=0; //for storing the last jump
 
    int dest=numsSize-1; //for storing the destination

    if(numsSize==1) return 0; //if there is only one element in the array then return 0
    
    for(int i=0;i<numsSize;i++){
        if(nums[i]+i>max){
            max=nums[i]+i; //storing the maximum jump
        }
      
        if(i==lastjump){ //if the index is equal to the last jump then increment the count and update the last jump
            count++;
            lastjump=max;
        }
       
        if(lastjump>=dest){ //if the last jump is greater than or equal to the destination then return the count
            return count;
        }
    }
    return count; 
}
//Time Complexity: O(n)
//Space Complexity: O(1)
