#include<iostream>
using namespace std;
int left_varient(int arr[],int size,int target)
{
    int lo=0;
    int hi=size-1;
    while(lo<=hi)
    {
        int mid=lo+(hi-lo)/2;
        if(arr[mid]>=target)
        {
            hi=mid-1;
        }
        else
        {
            lo=mid+1;
        }
    }
    return lo;
}

int right_varient(int arr[],int size,int target)
{
    int lo=0;
    int hi=size-1;
    while(lo<=hi)
    {
        int mid=lo+(hi-lo)/2;
        if(arr[mid]<=target)
        {
            lo=mid+1;
        }
        else
        {
            hi=mid-1;
        }
    }
    return hi;
}

int main()
{
    int n,target;
    cin>>n>>target;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"Left most position : "<<left_varient(arr,n,target)<<"\n";
    cout<<"Right most position : "<<right_varient(arr,n,target)<<"\n";
}
