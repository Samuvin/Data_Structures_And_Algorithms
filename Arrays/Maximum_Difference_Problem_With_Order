#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int Brute_Force(int arr[],int size)
{
    int res=0;
    for(int i=0;i<size;i++)
    {
        for(int j=i+1;j<size;j++)
        {
            res=max(res,arr[j]-arr[i]); 
        }
    }
    return res<=0?-1:res;
}


int Better_Solution(int arr[],int size)
{
    int mini=arr[0];
    int res=arr[1]-arr[0];
    for(int i=1;i<size;i++)
    {
        res=max(res,arr[i]-mini);
        mini=min(arr[i],mini);
    }
    return res<=0?-1:res;
}

int main()
{
    int size;
    cin>>size;
    int arr[size];
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }
    cout<<Brute_Force(arr,size);
}
/*
WE have to find maximum value of the difference between the arr[j]-arr[i]
where j>i

The brute Force approach is to use nested loop that is we traverse through all the sub array
and find the value for arr[j]-arr[i] and during every iteration we maintain the result as the 
maximum value found in the given subarray

The optimise approach is that we consider every element in the array as tha jth element
and we consider the first element as the minimum value and during the first iteration we 
used to do arr[j]-minimum value and store the value in the result variable and during every iteration 
we change our minimum value 

so we get the maximum for every large element when we consider the smaller element in the right side of the current element
*/
