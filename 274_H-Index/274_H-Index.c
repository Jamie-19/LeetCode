/*
274.H-Index
Given an array of integers citations where citations[i] is the number of citations a researcher received for their ith paper, 
return the researcher's h-index.
The h-index is defined as the maximum value of h such that the given researcher has published at least h papers that have each been cited at least h times.
*/


#include<stdio.h>
int hIndex(int* citations, int citationsSize);
int main()
{
    int citations[100],citationsSize,i;
    // taking user input
    printf("Enter the size of array: "); 
    scanf("%d",&citationsSize);
    printf("Enter the elements of array: ");
    for(i=0;i<citationsSize;i++)
    {
        scanf("%d",&citations[i]);
    }
    printf("The h-index is: %d",hIndex(citations,citationsSize));
    return 0;
}

int hIndex(int* citations, int citationsSize)
{
    int i,j,temp;
    // sorting the array in ascending order
    for(i=0;i<citationsSize-1;i++)
    {
        for(j=0;j<citationsSize-i-1;j++)
        {
            if(citations[j]>citations[j+1])
            {
                temp=citations[j];
                citations[j]=citations[j+1];
                citations[j+1]=temp;
            }
        }
    }
    // finding the h-index
    for(i=1;i<=citationsSize;++i)
    {
        if(citations[citationsSize-i] < i) // checks if the number of citations is less than the h-index.if less then return the previous value of i
        {
            return i-1;
        }
    }
    return citationsSize;
}