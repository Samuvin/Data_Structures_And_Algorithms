#include<iostream>
#include<vector>
using namespace std;
int first_occurrence(vector<int>&v,int target)
{
    int lo=0;
    int hi=v.size()-1;
    while(lo<=hi)
    {
        int mid=lo+(hi-lo)/2;
        if(v[mid]>=target)
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

int last_occurrence(vector<int>&v,int target)
{
    int lo=0;
    int hi=v.size()-1;
    while(lo<=hi)
    {
        int mid=lo+(hi-lo)/2;
        if(v[mid]<=target)
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
    vector<int>v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    vector<int>res(2,-1);
    int x=first_occurrence(v,target);
    int y=last_occurrence(v,target);
    if(x>=0 && x<v.size() && v[x]==target)
    {
        res[0]=x;
        res[1]=y;
    }
    cout<<res[0]<<"\n";
    cout<<res[1]<<"\n";
}
