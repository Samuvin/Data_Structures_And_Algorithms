#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int pivot(vector<int>&arr,int lo,int hi)
{
    int pivot=arr[lo];
    int i=lo;
    int j=hi;
    while(i<j)
    {
        while(arr[i]<=pivot && i<=hi-1)
        {
            i++;
        }
        while(arr[j]>pivot && j>=lo+1)
        {
            j--;
        }
        if(i<j)swap(arr[i],arr[j]);
    }
    swap(arr[lo],arr[j]);
    return j;

}
void Quick_sort(vector<int>&arr,int lo,int hi)
{
    if(lo<hi)
    {
        int partition=pivot(arr,lo,hi);
        Quick_sort(arr,lo,partition-1);
        Quick_sort(arr,partition+1,hi);
    }
}

int main()
{
    int size;
    cin>>size;
    vector<int>arr(size);
    for(int i=0;i<size;i++)cin>>arr[i];
    Quick_sort(arr,0,size-1);
    for(int i=0;i<size;i++)cout<<arr[i]<<" ";


}
