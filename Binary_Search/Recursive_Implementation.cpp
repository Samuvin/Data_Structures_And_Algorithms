#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int BS(vector<int> arr,int low,int high,int target)
{
    if(low>high)
        return 0;
    else{
        int mid=low+(high-low)/2;
        if(arr[mid]==target)
        {
            return mid;
        }
        else if(arr[mid]>target)
        {
            return BS(arr,low,mid-1,target);
        }
        else{
            return BS(arr,mid+1,high,target);
        }
    }
    return 0;
}

int main()
{
    int n;
    cin>>n;
    int target;
    cin>>target;
    vector<int> arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    cout<<BS(arr,0,n-1,target);
}
