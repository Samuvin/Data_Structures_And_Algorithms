#include<iostream>
#include<vector>
using namespace std;
int Brute(vector<int>&arr,int k)
{
    for(int i:arr)
    {
        if(i<=k)
        {
            k++;
        }
        else
        {
            break;
        }
    }
    return k;
}

int Binary_Search(vector<int>&arr,int k)
{
    int lo=0;
    int hi=arr.size()-1;
    while(lo<=hi)
    {
        int mid=lo+(hi-lo)/2;
        int missing=arr[mid]-(mid+1);
        if(missing<k)
        {
            lo=mid+1;
        }
        else
        {
            hi=mid-1;
        }
    }
    return hi+k+1;
}
int main()
{
    int size,k;
    cin>>size>>k;
    vector<int>arr(size);
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }
    cout<<Brute(arr,k)<<"\n";
    cout<<Binary_Search(arr,k)<<"\n";
}
