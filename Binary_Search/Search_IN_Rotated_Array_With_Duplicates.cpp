#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool Search_In_Rotated(vector<int>arr,int target)
{
    int low=0;
    int high=arr.size()-1;
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        if(arr[mid]==target)return true;
        if(arr[low]==arr[mid] && arr[low]==arr[high])
        {
            low++;
            high--;
            continue;
        }
        if(arr[mid]>=arr[low])
        {
            if(arr[low]<=target && arr[mid]>=target)
            {
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        else{
            if(arr[mid]<=target && arr[high]>=target)
            {
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
    }
    return false;
}


int main()
{
    int n,target;
    cin>>n>>target;
    vector<int> arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    if(Search_In_Rotated(arr,target))
    {
        cout<<"IS PRESENT\n";
    }
    else{
        cout<<"IS NOT PRESENT\n";
    }
}
