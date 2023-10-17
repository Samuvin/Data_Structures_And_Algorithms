#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

bool predicate(vector<int>&arr,int mid,int threshold)
{
    int sum=0;
    for(auto i:arr)
    {
        sum+=ceil((double)i/(double)mid);
    }
    return sum<=threshold;
}

int Smallest_Divisor_Given_A_Threshold(vector<int>&arr,int threshold)
{
    int lo=1;
    int hi=*max_element(arr.begin(),arr.end());;
    while(lo<=hi)
    {
        int mid=lo+(hi-lo)/2;
        if(predicate(arr,mid,threshold))
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
    int size,threshold;
    cin>>size>>threshold;
    vector<int>v(size);
    for(int i=0;i<size;i++)cin>>v[i];
    cout<<Smallest_Divisor_Given_A_Threshold(v,threshold);
}
