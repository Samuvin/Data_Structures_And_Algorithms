#include<iostream>
#include<vector>
using namespace std;

int singleElementInASortedArray(vector<int>&arr)
{
    int size=arr.size();
    if(size==1)return arr[0];
    if(arr[0]!=arr[1])return arr[0];
    if(arr[size-1]!=arr[size-2])return arr[size-1];
    int lo=1;
    int hi=arr.size()-2;
    while(lo<=hi)
    {
        int mid=lo+(hi-lo)/2;
        if(arr[mid]!=arr[mid-1] && arr[mid]!=arr[mid+1])
        {
            return arr[mid];
        }
        if((mid&1)==1 && arr[mid]==arr[mid-1] || (mid&1)==0 && arr[mid]==arr[mid+1])
        {
            lo=mid+1;
        }
        else
        {
            hi=mid-1;
        }
    }
    return -1;
}

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    cout<<singleElementInASortedArray(v);
}
