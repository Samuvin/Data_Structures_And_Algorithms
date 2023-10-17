#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool CanEat(vector<int>&piles , int hour ,int banana)
{
    long long timeTaken=0;
    for(auto i:piles)
    {
        timeTaken+=ceil((double)i/(double)banana);
    }
    return timeTaken<=hour;
}

int Minimum_Time_Taken(vector<int>& piles,int hour)
{
    int lo=1;
    int hi=*max_element(piles.begin(),piles.end());
    while(lo<=hi)
    {
        int mid=lo+(hi-lo)/2;
        if(CanEat(piles,hour,mid))
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
    int size,hour;
    cin>>size>>hour;
    vector<int>piles(size);
    for(int i=0;i<size;i++)cin>>piles[i];
    cout<<Minimum_Time_Taken(piles,hour)<<endl;
}
