#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void prefix_sum(int arr[],int n)
{
    vector<int> prefix_sum(n);
    prefix_sum[0]=arr[0];
    for(int i=1;i<n;i++)
    {
        prefix_sum[i]=prefix_sum[i-1]+arr[i];
    }

    for(int value : prefix_sum)
    {
        cout<<value<<" ";
    }
}


int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    prefix_sum(arr,n);
}

/*
This technique is used to find the sum of the subarrays in a linear or constant by doing some precomputation This method is algo used to answer the range queries regarding the  subarrays
The Idea is first we have to take a seperate Prefix_array and then we have to give the first value of the array to the prefix array after that we have to iterate from 1 to n-1 and in every 
iteration add the before index element of the prefix sum array and the current element of the given array thus we can able to form the Prefix_sum Array and we can answer the range question in teta 1 time
*/
