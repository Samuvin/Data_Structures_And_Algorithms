#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int BS(vector<int> arr,int low,int high,int target)
{
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        if(arr[mid]==target)
        {
            return mid;
        }
        if(arr[mid]>target)
        {
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return -1;
}

int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    int target=0;
    cin>>target;
    for(int i=0;i<n;i++)cin>>arr[i];
    cout<<BS(arr,0,n-1,target);
}
