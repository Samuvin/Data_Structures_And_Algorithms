#include<iostream>
using namespace std;

bool Subarray_With_Given_Sum(int arr[],int size, int target)
{
    int lo=0;
    int sum=0;
    for(int i=0;i<size;i++)
    {
        sum+=arr[i];
        while(sum>target)
        {
            sum-=arr[lo];
            lo++;
        }
        if(sum==target)
        {
            return true;
        }
    }
    return false;
}
int main()
{
    int size,target;
    cin>>size>>target;
    int arr[size];
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }
    cout<<((Subarray_With_Given_Sum(arr,size,target))?"YES":"NO");
}
/*
We are Given an array 4 8 12 5
and we need to know if we get the sum as 17 in any of the sub arrays

First we need to traverse an array and we have to add each element
if the sum is greater than the target sum then we need to reduce the window size

As

4 8 12 5

1st:
4

2nd:
12

3rd:
24
which is greater so we need to reduce the window size as till our sum is lesser than target
25 - 4=20
20 - 8=12

4th:
12+5=17

So in window 12 7 we get out sum as 17
*/
