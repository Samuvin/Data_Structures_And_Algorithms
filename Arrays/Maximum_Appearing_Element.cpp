/*
The task is that you have given two arrays left array which contains the starting point
and the right array which contains the ending point we have to find the maximum element 
occured in these range if more than one integer exists print the smallest one

Input: L[ ] = {1, 4, 3, 1}, R[ ] = {15, 8, 5, 4}
Output: 4

Explanation: Overall ranges are: {1,2,3,4,5,6,7,8,9,10,11,12,13,14 15}, {4,5,6,7,8}, {3,4,5}, {1,2,3,4}. 

In all these ranges, 4 appears the most times.

Input: L[ ] = {1, 5, 9, 13, 21}, R[ ] = {15, 8, 12, 20, 24}
Output: 5
Explanation: Overall Ranges are: {1,2,3,4,5,6,7,8,9,10,11,12,13,14 15}, {5,6,7,8}, {9,10,11,12}, {13,14,15,16,17,18,19,20},{21,22,23,24}
In these ranges, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 all appear 2 times. The smallest number among all are 5.

*/

#include<iostream>
using namespace std;
int brute_Force(int left[],int right[],int size)
{
    int freq[100]={0}; //maximum ending element considered as below 100
    for(int i=0;i<size;i++)
    {
        for(int j=left[i];j<=right[i];j++)
        {
            freq[j]++;
        }
    }
    int res=0;
    for(int i=1;i<100;i++)
    {
        if(freq[res]<freq[i])
        {
            res=i;
        }
    }
    return res;
}

int Efficient(int left[],int right[],int size)
{
    int freq[100]={0};
    for(int i=0;i<size;i++)
    {
        freq[left[i]]+=1;
        freq[right[i]+1]-=1;
    }
    int res=0;
    for(int i=1;i<size;i++)
    {
        freq[i]+=freq[i-1];
        if(freq[i]>freq[res])
        {
            return freq[i];
        }
    }
    return -1;
}
int main()
{
    int size;
    cin>>size;
    int left[size];
    int right[size];
    for(int i=0;i<size;i++)
    {
        cin>>left[i];
    }
    for(int i=0;i<size;i++)
    {
        cin>>right[i];
    }
    cout<<brute_Force(left,right,size);
}
/*
The intuition is that we have taken a frequency array
and we increment the count of a single element for every 
starting and ending senario

That is if we have 1 2 4 as starting array
and 4 5 7 as the ending array

Then out Frequency array looks like

0 1 2 3 3 2 1 1 0 0 ..... Occurence of every element

0 1 2 3 4 5 6 7 8 9 ......... Elements

We iterate throught the array and we find the maximum occured element

Efficient Approch

The intuition is to increment the starting and ending point in the frequency array
we need to increment the starting point and decrement the ending point+1

as 
0 1 1 0 1 -1 -1 0 -1 Occurence

0 1 2 3 4  5 6 7  8..... Elements

Now we have to take prefix sum for the frequency array 
and print the maximum occuring element

prefix_Frequency_array

0 1 2 2 3 2 1 1 0....Occurence
0 1 2 3 4 5 6 7 8 .. Elements

The maximum appeared element is 4

*/
