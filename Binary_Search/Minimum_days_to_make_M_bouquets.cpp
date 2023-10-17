#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool predicate(const vector<int>&days,int day,int k,int m)
{
    int cnt=0;
    int numOfBoq=0;
    for(auto i:days)
    {
        if(i<=day)
        {
            cnt++;
        }
        else
        {
            numOfBoq+=(cnt/k);
            cnt=0;
        }
    }
    numOfBoq+=(cnt/k);
    return numOfBoq>=m;
}

int Minimum_days(vector<int>&days ,int k,int m)
{
    if(k*m>days.size())
	{
		return -1;
	}
    int lo=*min_element(days.begin(),days.end());
    int hi=*max_element(days.begin(),days.end());
    while(lo<=hi)
    {
        int mid=lo+(hi-lo)/2;
        if(predicate(days,mid,k,m))
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
    int size,k,m;
    cin>>size>>k,m;
    vector<int>days(size);
    for(int i=0;i<size;i++)cin>>days[i];
    cout<<Minimum_days(days,k,m);
}Minimum days to make M bouquets
