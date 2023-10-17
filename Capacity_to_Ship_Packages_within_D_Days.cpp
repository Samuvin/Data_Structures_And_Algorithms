#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

bool predicate(vector<int>&capacity , int mid,int days)
{
    int cnt=1;
    int sum=0;
    for(auto i:capacity)
    {
        if(sum+i>mid)
        {
            cnt++;
            sum=i;
        }
        else
        {
            sum+=i;
        }
    }
    return cnt<=days;
}

int Minimum_days(vector<int>&capacity,int days)
{
    int lo=*max_element(capacity.begin(),capacity.end());
    int hi=accumulate(capacity.begin(),capacity.end(),0);
    while(lo<=hi)
    {
        int mid=lo+(hi-lo)/2;
        if(predicate(capacity,mid,days))
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


int main()
{
    int size,days;
    cin>>size>>days;
    vector<int>capacity(size);
    for(int i=0;i<size;i++)cin>>capacity[i];
    cout<<Minimum_days(capacity,days);

}
