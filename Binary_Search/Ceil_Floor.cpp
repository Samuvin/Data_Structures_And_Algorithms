#include<iostream>
#include<vector>
using namespace std;

int findceil(vector<int>&v,int target)
{
    int lo=0;
    int hi=v.size()-1;
    int ans=-1;
    while(lo<=hi)
    {
        int mid=lo+(hi-lo)/2;
        if (v[mid]>=target)
        {
            ans=v[mid];
            hi=mid-1;
        }
        else
        {
            lo=mid+1;
        }
    }
    return ans;
}

int findfloor(vector<int>&v,int target)
{
    int lo=0;
    int hi=v.size()-1;
    int ans=-1;
    while(lo<=hi)
    {
        int mid=lo+(hi-lo)/2;
        if(v[mid]<=target)
        {
            ans=v[mid];
            lo=mid+1;
        }
        else
        {
            hi=mid-1;
        }
    }
    return ans;
}

void solve(vector<int>&arr,int target)
{
    int ceil=findceil(arr,target);
    int floor=findfloor(arr,target);
    cout<<"Floor : "<<floor<<"\nCeil : "<<ceil;
}

int main()
{
    int n,target;
    cin>>n>>target;
    vector<int>v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    solve(v,target);
}
