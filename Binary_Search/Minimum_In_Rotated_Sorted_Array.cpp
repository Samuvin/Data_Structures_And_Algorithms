#include<bits/stdc++.h>
using namespace std;

int Minimum(vector<int> &v)
{
    int lo=0;
    int hi=v.size()-1;
    int ans=INT_MAX;
    while(lo<=hi)
    {
        int mid=lo+(hi-lo)/2;
        if(v[lo]<=v[hi])
        {
            ans=min(ans,v[lo]);
            break;
        }
        if(v[lo]<=v[mid])
        {
            ans=min(ans,v[lo]);
            lo=mid+1;
        }
        else{
            ans=min(ans,v[mid]);
            hi=mid-1;
        }
    }
    return ans;
}


int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    cout<<Minimum(v);
}
