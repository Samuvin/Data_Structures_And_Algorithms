#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool predicate(vector<int>&stalls,int distance,int cows)
{
    int cnt=1;
    int cow=stalls[0];
    for(int i=1;i<stalls.size();i++)
    {
        if(stalls[i]-cow>=distance)
        {
            cnt++;
            cow=stalls[i];
        }
        if(cnt>=cows)
            return true;
    }
    return false;
}

int Aggressive_cows(vector<int>&stalls,int cows)
{
    sort(stalls.begin(),stalls.end());
    int lo=1;
    int hi=stalls[stalls.size()-1]-stalls[0];
    while(lo<=hi)
    {
        int mid=lo+(hi-lo)/2;
        if(predicate(stalls,mid,cows))
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
    int n,cows;
    cin>>n>>cows;
    vector<int>stalls(n);
    for(int i=0;i<n;i++)cin>>stalls[i];
    cout<<Aggressive_cows(stalls,cows);
}
