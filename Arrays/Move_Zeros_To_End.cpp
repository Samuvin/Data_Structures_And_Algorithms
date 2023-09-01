#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,zero_cnt=0;
    cin>>n;
    vector<int> Dynammic_Siz_arr(n);
    for(int i=0;i<n;i++)cin>>Dynammic_Siz_arr[i];

    for(int i=0;i<n;i++)
    {
        if(Dynammic_Siz_arr[i]!=0)
        {
            if(Dynammic_Siz_arr[i]==Dynammic_Siz_arr[zero_cnt])
            {
                zero_cnt++;
            }
            else
            {
                swap(Dynammic_Siz_arr[i],Dynammic_Siz_arr[zero_cnt]);
                zero_cnt++;
            }
        }
    }

    for(int i: Dynammic_Siz_arr)
    {
        cout<<i<<" ";
    }
}
/*
The task is to move the zeros from the array to the end of the array thus the given array should first contain elements and then zeros should be there
Input: arr[]  = {1, 2, 0, 0, 0, 3, 6}
Output: 1 2 3 6 0 0 0

Input: arr[] = {0, 1, 9, 8, 4, 0, 0, 2, 7, 0, 6, 0, 9}
Output: 1 9 8 4 2 7 6 9 0 0 0 0 0

Approch:
  We have to traverse through the array exactly once while traversing we have to maintain the cound of elements which are appearing continuosuly while checking that out zero_cnt variable will be 
  on the first zero position when we meet a non zero value after a zero then we need to swap the zero_cnt index with the current index thus we will make the array as elements occur first then zeros will be there

  Time Complexity:O(n)  // we are traversing the array exacting once
*/
