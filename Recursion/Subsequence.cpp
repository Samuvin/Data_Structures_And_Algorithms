#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void subsequence(vector<int>arr,vector<int>&res,int index,int size)
{
    if(index==size)
    {
        if(res.empty())cout<<"{}"<<" ";
        for(auto i: res) 
            cout<<i<<" ";
        cout<<"\n";
        return;
    }
    res.push_back(arr[index]);
    subsequence(arr,res,index+1,size);
    res.pop_back();
    subsequence(arr,res,index+1,size);
}

int main()
{
    int size;
    cin>>size;
    vector<int> v(size);
    for(int i=0;i<size;i++) cin>>v[i];
    vector<int> v2;
    subsequence(v,v2,0,size);
}
