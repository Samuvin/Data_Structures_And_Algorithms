#include<iostream>
#include<bits/stdc++.h>
using namespace std;

long long maximum_product(vector<int> arr)
{
    int size=arr.size();
    long long maxi=INT_MIN;
    long long prefix=1;
    long long suffix=1;
    for(int i=0;i<size;i++)
    {
        if(prefix==0)prefix=1;
        if(suffix==0)suffix=1;
        prefix*=arr[i];
        suffix*=arr[size-1-i];
        maxi=max(maxi,max(prefix,suffix));
    }
    return maxi;
}


long long Method_2(vector<int> arr)
{
    int maxi=arr[0];
    int mini=arr[0];
    int res=INT_MIN;
    for(int i=1;i<arr.size();i++)
    {
        int temp=max({arr[i],arr[i]*maxi,arr[i]*mini});
        mini=min({arr[i],arr[i]*maxi,arr[i]*mini});
        maxi=temp;
        res=max(res,maxi);
    }
    return res;
}


int main()
{
    int size;
    cin>>size;
    vector<int> v(size);
    for(int i=0;i<size;i++)cin>>v[i];
    cout<<maximum_product(v);
}
/*
The problem states that we are given an array we have to print the 
maximum product obtained from the subarray of the array
The intuition is 
if we have all positive elements the our product will be the 
the product of all elements
if we have even negative numbers
1 2 3 -3 -4 5
Two neagatives cancel out each other and we get the answer
as the product of all the elements

The trickier part is that if we have odd negative elements
such as
1 2 -1 2 3 4 -2 5 6 -4
in this case 2 negatives cancel out each other and one negative will stay
such that out maximum product will be neither the prefix of the array
or suffix of the array
if we want the maximum product then our aim will be to cancel out the least minimum
if we consider we can neither take the prefix product of 1 or suffix product of 1
*/
