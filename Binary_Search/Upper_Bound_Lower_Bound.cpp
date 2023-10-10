#include<iostream>
#include<vector>
using namespace std;
int lowerBound(vector<int> arr, int n, int x) 
{
	int lo=0;
	int hi=arr.size()-1;
	while(lo<=hi)
	{
		int mid=lo+(hi-lo)/2;
		if(arr[mid]>=x)
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

int upperBound(vector<int> &arr, int x, int n){

	int lo=0;
	int hi=arr.size()-1;
	while(lo<=hi)
	{
		int mid=lo+(hi-lo)/2;
		if(arr[mid]>x)
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
    int size,target;
    cin>>size>>target;
    vector<int>v(size);
    for(int i=0;i<size;i++)cin>>v[i];
    cout<<lowerBound(v,size,target)<<endl;
    cout<<upperBound(v,target,size)<<endl;
}
