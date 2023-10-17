#include<iostream>
using namespace std;

long long sqr_root(long long n)
{
    long long lo=0;
    long long hi=n;
    while(lo<=hi)
    {
        long long mid=lo+(hi-lo)/2;
        if(mid*mid<=n)
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
    long long n;
    cin>>n;
    cout<<sqr_root(n);
}
